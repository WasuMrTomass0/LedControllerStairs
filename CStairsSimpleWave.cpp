#include "CStairsSimpleWave.h"

CStairsSimpleWave::CStairsSimpleWave(PWMMode ledmode, bool* stepsState, int* stepsValue)
	: IStairs(ledmode, stepsState, stepsValue,
		/*pwmValDiff*/ 10,
		/*pwmValTimePeriod*/ 40,
		/*nextStepSwitchPeriod*/ 300,
		/*ledTime*/ 10000
	)
	, m_timeOnStepUpstairs(0)
	, m_timeOnStepDownstairs(0)
	, m_timeOffStepUpstairs(0)
	, m_timeOffStepDownstairs(0)
	, m_timeUpstairsOff(0)
	, m_timeDownstairsOff(0)
{
	resetData();
}


//m_ledStateUpstairs

void CStairsSimpleWave::resetData() {
	resetBaseClass();
	m_timeOnStepUpstairs = 0;
	m_timeOnStepDownstairs = 0;
	m_timeOffStepUpstairs = 0;
	m_timeOffStepDownstairs = 0;
	//for (unsigned i = 0; i < m_ledStateUpstairs.size(); i++) {
	for (unsigned i = 0; i < SETT_STEPS; i++) {
		m_ledStateUpstairs[i] = false;
		m_ledStateDownstairs[i] = false;
	}
}

bool CStairsSimpleWave::mainLoop() {
	if (m_upstairsOn || m_upstairsOff) {
		if (didTimePass(&m_timeOnStepUpstairs, m_nextStepSwitchPeriod, true)) {
			m_updateRegisters = true;

			shiftTab(m_ledStateUpstairs, SETT_STEPS, true); // Shift steps
			m_ledStateUpstairs[0] = m_upstairsOn; // Input new state to first step

			if (m_upstairsOn && !m_upstairsOff) {
				if (didTimePass(&m_timeUpstairs, m_ledMode)) { // Time has passed, 
					m_upstairsOn = false;
					m_upstairsOff = true;
				}
			} else if (isAllEqualTo(m_ledStateUpstairs, SETT_STEPS, false)) {
				m_upstairsOff = false; // All steps are turned off. No need to shift steps
			}
		}
	}

	if (m_downstairsOn || m_downstairsOff) {
		if (didTimePass(&m_timeOnStepDownstairs, m_nextStepSwitchPeriod, true)) {
			m_updateRegisters = true;

			shiftTab(m_ledStateDownstairs, SETT_STEPS, false); // Shift steps
			m_ledStateUpstairs[0] = m_upstairsOn; // Input new state to first step

			if (m_downstairsOn && !m_downstairsOff) {
				if (didTimePass(&m_timeDownstairs, m_ledMode)) { // Time has passed, 
					m_downstairsOn = false;
					m_downstairsOff = true;
				}
			}
			else if (isAllEqualTo(m_ledStateDownstairs, SETT_STEPS, false)) {
				m_downstairsOff = false; // All steps are turned off. No need to shift steps
			}
		}
	}

	orBool(m_ledStateDownstairs, m_ledStateUpstairs, m_stepsState, SETT_STEPS);
	if (m_ledMode == PWMOff) return true;  // Code below only for active PWM

	updateValuesBasic();
	m_updateRegisters = isPWMNeeded();
	return true;
}
