#include "IStairs.h"

IStairs::IStairs(PWMMode ledmode, bool* stepsState, int* stepsValue,
	const unsigned pwmValDiff, const unsigned pwmValTimePeriod,
	const unsigned ledTime, const unsigned stepShiftPeriod)
	: m_steps(SETT_STEPS)
	, m_ledMode(ledmode)
	, m_ledTime(ledTime)
	, m_pwmValDiff(pwmValDiff)
	, m_pwmValTimePeriod(pwmValTimePeriod)
	, m_stepShiftPeriod(stepShiftPeriod)
	, m_timeUpstairs(0)
	, m_timeDownstairs(0)
	, m_timeMvmnt(0)
	, m_timePwmValChange(0)
	, m_downstairsOn(false)
	, m_downstairsOff(false)
	, m_upstairsOn(false)
	, m_upstairsOff(false)
	, m_updateRegisters(false)
{
	// Memory will not be realeased. It is used to the end.
	if (!stepsState) { m_stepsState = new bool[SETT_STEPS]; }
	else m_stepsState = stepsState;
	if(!stepsValue) { m_stepsValue = new int[SETT_STEPS]; }
	else m_stepsValue = stepsValue;
	resetBaseClass();
}

void IStairs::resetBaseClass() {
	for (unsigned i = 0; i < m_steps; i++) {
		m_stepsState[i] = false;
		m_stepsValue[i] = 0;
	}
	m_downstairsOn = false;
	m_downstairsOff = false;
	m_upstairsOn = false;
	m_upstairsOff = false;

	m_updateRegisters = true;
}

void IStairs::switchAllTo(bool state) {
	for (unsigned i = 0; i < m_steps; i++) {
		m_stepsState[i] = state;
	}
}

bool IStairs::get_updateRegisters() {
	bool state = m_updateRegistersPrevious = m_updateRegisters;
	m_updateRegisters = false;
	return state;
}

bool IStairs::updateValuesBasic() {
	if (!didTimePass(&m_timePwmValChange, m_pwmValTimePeriod, true)) return false;
	for (unsigned i = 0; i < m_steps; i++) { // Analise if it can be made more efficient
		m_stepsValue[i] += m_stepsState[i] ? m_pwmValDiff : -(static_cast<int>(m_pwmValDiff)); 
		if (m_stepsValue[i] < 0)	m_stepsValue[i] = 0;
		if (m_stepsValue[i] > 255)  m_stepsValue[i] = 255;
	}
	return true;
}

bool IStairs::isPWMNeeded(){
	for (unsigned i = 0; i < m_steps; i++) {
		if (m_stepsValue[i] != 0 && m_stepsValue[i] != 255) return true;
	}
	return false;
}

void IStairs::isUpdateNeeded() {
	m_updateRegisters = isPWMNeeded();
	if (!m_updateRegisters && m_updateRegistersPrevious) m_stepsValue[0] == 255 ? turnOnAllLeds() : turnOffAllLeds();
}
