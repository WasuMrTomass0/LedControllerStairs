#include "CStairsSimpleWave.h"

CStairsSimpleWave::CStairsSimpleWave(PWMMode ledmode, bool* stepsState, int* stepsValue)
	: IStairs(ledmode, stepsState, stepsValue,
		/*pwmValDiff*/ 10,
		/*pwmValTimePeriod*/ 40,
		/*nextStepOnPeriod*/ 300, // Merge 'nextStepOnPeriod' and 'nextStepOffPeriod' into one variable!
		/*nextStepOffPeriod*/ 350
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
		if (didTimePass(&m_timeOnStepUpstairs, m_nextStepOnPeriod, true)) {
			shiftTab(m_ledStateUpstairs, SETT_STEPS, true);
			m_ledStateUpstairs[0] = m_upstairsOn;
		}
	}
}