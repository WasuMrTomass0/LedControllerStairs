#include "CStairsSimpleWave.h"

CStairsSimpleWave::CStairsSimpleWave(PWMMode ledmode, bool* stepsState, int* stepsValue)
	: IStairs(ledmode, stepsState, stepsValue,
		/*pwmValDiff*/ 15,
		/*pwmValTimePeriod*/ 50,
		/*ledTime*/ 5000,
		/*m_stepShiftPeriod*/ 300
	)
	, m_timeShiftUpstairs(0)
	, m_timeShiftDownstairs(0)
	, m_timeUpstairsOff(0)
	, m_timeDownstairsOff(0)
{
	m_ledStateUpstairs = new bool[SETT_STEPS];
	m_ledStateDownstairs = new bool[SETT_STEPS];
	resetData();
}

void CStairsSimpleWave::resetData() {
	resetBaseClass();
	m_timeShiftUpstairs = 0;
	m_timeShiftDownstairs = 0;
	for (unsigned i = 0; i < SETT_STEPS; i++) {
		m_ledStateUpstairs[i] = false;
		m_ledStateDownstairs[i] = false;
	}
}

bool CStairsSimpleWave::mainLoop() {
	if (m_upstairsOn || m_upstairsOff) {
		if (didTimePass(&m_timeShiftUpstairs, m_stepShiftPeriod, true)) {
			if (m_ledMode == PWMOff) {
				m_updateRegisters = !isAllEqualTo(m_stepsState, SETT_STEPS, true);
			}

			shiftTab(m_ledStateUpstairs, SETT_STEPS, true);
			m_ledStateUpstairs[0] = !m_upstairsOff;

			if (m_upstairsOn) {
				if (didTimePass(&m_timeUpstairs, m_ledTime)) {
					m_upstairsOn = false;
					m_upstairsOff = true;
				}
			} else if (isAllEqualTo(m_ledStateUpstairs, SETT_STEPS, false)) {
				m_upstairsOff = false;
			}
		}
	}

	if (m_downstairsOn || m_downstairsOff) {
		if (didTimePass(&m_timeShiftDownstairs, m_stepShiftPeriod, true)) {
			if (m_ledMode == PWMOff) {
				m_updateRegisters = !isAllEqualTo(m_stepsState, SETT_STEPS, true);
			}

			shiftTab(m_ledStateDownstairs, SETT_STEPS, false);
			m_ledStateDownstairs[SETT_STEPS-1] = !m_downstairsOff;

			if (m_downstairsOn) {
				if (didTimePass(&m_timeDownstairs, m_ledTime)) {
					m_downstairsOn = false;
					m_downstairsOff = true;
				}
			}
			else if (isAllEqualTo(m_ledStateDownstairs, SETT_STEPS, false)) {
				m_downstairsOff = false;
			}
		}
	}

	orBool(m_ledStateDownstairs, m_ledStateUpstairs, m_stepsState, SETT_STEPS);
	if (m_ledMode == PWMOff) return true;  // Code below only for active PWM

	updateValuesBasic();
	m_updateRegisters = isPWMNeeded();
	return true;
}
