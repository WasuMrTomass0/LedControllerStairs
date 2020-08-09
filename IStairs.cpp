#include "IStairs.h"

IStairs::IStairs(LedMode ledmode, bool* stepsState = nullptr, int* stepsValue = nullptr,
	const unsigned pwmValDiff, const unsigned pwmValTimePeriod, const unsigned timePwmValChange,
	const unsigned nextStepOnPeriod, const unsigned nextStepOffPeriod) :
	m_ledMode(ledmode)
	, m_steps(SETT_STEPS)
	, m_timeUpstairs(0)
	, m_timeDownstairs(0)
	, m_timeMvmnt(0)
	, m_downstairsOn(false)
	, m_downstairsOff(false)
	, m_upstairsOn(false)
	, m_upstairsOff(false)
	, m_updateRegisters(false)
	, m_pwmValDiff(pwmValDiff)
	, m_pwmValTimePeriod(pwmValTimePeriod)
	, m_timePwmValChange(timePwmValChange)
	,m_nextStepOnPeriod(nextStepOnPeriod)
	,m_nextStepOffPeriod(nextStepOffPeriod)
{
	/*
		Memory will not realeased. It is used to the end.
	*/
	if (!stepsState) { m_stepsState = static_cast<bool*>(malloc(m_steps * sizeof(bool))); }
	else m_stepsState = stepsState;
	if(!stepsValue) { m_stepsValue = static_cast<int*>(malloc(m_steps * sizeof(int))); }
	else m_stepsValue = stepsValue;
	resetBaseClass();
}

void IStairs::resetBaseClass() {
	for (size_t i = 0; i < m_steps; i++) {
		m_stepsState[i] = false;
		m_stepsValue[i] = 0;
	}
	m_downstairsOn = false;
	m_downstairsOff = false;
	m_upstairsOn = false;
	m_upstairsOff = false;
}

void IStairs::switchAllTo(bool state) {
	int val = state ? 255 : 0;
	for (unsigned i = 0; i < m_steps; i++) {
		m_stepsState[i] = state;
		m_stepsValue[i] = val;
	}
}

bool IStairs::get_updateRegisters() {
	bool state = m_updateRegisters;
	m_updateRegisters = false;
	return state;
}

//bool IStairs::updateValuesBasic(int* stepsValue, bool* stepsState) {
//if (!stepsValue) stepsValue = m_stepsValue;
//if (!stepsState) stepsState = m_stepsState;
//
//}


bool IStairs::updateValuesBasic() {
	if (!didTimePass(&m_timePwmValChange, m_pwmValTimePeriod)) return false;
	for (unsigned i = 0; i < m_steps; i++) { // Analise if it can be made more efficient
		m_stepsValue[i] += m_stepsState[i] ? m_pwmValDiff : -m_pwmValDiff; 
		if (m_stepsValue[i] < 0)	m_stepsValue[i] = 0;
		if (m_stepsValue[i] > 255)  m_stepsValue[i] = 255;
	}
	return true;
}

bool IStairs::didTimePass(unsigned* time, const unsigned period, bool update_time = true) {
	if (*time + period < millis()) {
		if (update_time) { *time = millis(); }
		return true;
	}
	return false;
}

bool IStairs::isPWMNeeded(){
	for (unsigned i = 0; i < m_steps; i++) {
		if (m_stepsValue[i] != 0 && m_stepsValue[i] != 255) return true;
	}
	return false;
}
