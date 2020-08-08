#include "CStairsBasic.h"

CStairsBasic::CStairsBasic(LedMode ledmode, bool* m_stepsState, int* m_stepsValue)
	: IStairs(ledmode, m_stepsState, m_stepsValue)
	, m_ledTime(10000)
	, m_currLedState(false)
{
	
}

void CStairsBasic::resetData() {
	resetBaseClass();
	m_currLedState = false;
}


bool CStairsBasic::mainLoop() {
	if (m_downstairsOn || m_upstairsOn) {
		if (!m_currLedState) {
			switchAllTo(true);
			m_currLedState = true;
			m_updateRegisters = true;
		}
	} else if (m_currLedState) {
		if (m_timestamp + m_ledTime < millis()) {
			switchAllTo(false);
			m_currLedState = false;
			m_updateRegisters = true;
		}
	}
	return true;
}
