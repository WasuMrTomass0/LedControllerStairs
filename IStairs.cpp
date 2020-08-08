#include "IStairs.h"

IStairs::IStairs(LedMode ledmode, bool* m_stepsState = nullptr, int* m_stepsValue = nullptr) :
	m_ledMode(ledmode)
	//, m_steps(sett::steps)
	, m_steps(SETT_STEPS)
	, m_timestampUpstairs(0)
	, m_timestampDownstairs(0)
	, m_downstairsOn(false)
	, m_downstairsOff(false)
	, m_upstairsOn(false)
	, m_upstairsOff(false)
	, m_updateRegisters(false)
{
	/*
		Memory is not realeased. It is used to the end.
	*/
	if(!m_stepsState) { m_stepsState = static_cast<bool*>(malloc(m_steps * sizeof(bool))); }
	if(!m_stepsValue) { m_stepsValue = static_cast<int*>(malloc(m_steps * sizeof(int))); }
	

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
	for (size_t i = 0; i < m_steps; i++) {
		m_stepsState[i] = state;
		m_stepsValue[i] = val;
	}
}

bool IStairs::get_updateRegisters() {
	bool state = m_updateRegisters;
	m_updateRegisters = false;
	return state;
}
