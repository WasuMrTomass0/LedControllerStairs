#include "CStairsBasic.h"

CStairsBasic::CStairsBasic(PWMMode ledmode, bool* stepsState, int* stepsValue)
	: IStairs(ledmode, stepsState, stepsValue, 
		/*pwmValDiff*/ 15, 
		/*pwmValTimePeriod*/ 50,
		/*ledTime*/ 10000,
		/*m_stepShiftPeriod*/ 0
	)
	, m_currLedState(false)
{
	resetData();
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
		if (didTimePass(&m_timeMvmnt, m_ledTime)){
			switchAllTo(false);
			m_currLedState = false;
			m_updateRegisters = true;
		}
	}
	m_downstairsOn = m_upstairsOn = false; // Clear flags
	if (m_ledMode == PWMOff) return true;  // Code below only for active PWM
	updateValuesBasic();
	isUpdateNeeded();
	return true;
}
