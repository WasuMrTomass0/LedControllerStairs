#ifndef CSTAIRSSIMPLEWAVE_CSTAIRSSIMPLEWAVE_H
#define CSTAIRSSIMPLEWAVE_CSTAIRSSIMPLEWAVE_H

#include "IStairs.h"
#include <array>

class CStairsSimpleWave: public IStairs{
public:
	CStairsSimpleWave(PWMMode, bool*, int*);

	void resetData() final;
	bool mainLoop() final;

protected:
	unsigned m_timeOnStepUpstairs;   // Timestamp for turning ON next step
	unsigned m_timeOnStepDownstairs; // Timestamp for turning ON next step
	unsigned m_timeOffStepUpstairs;   // Timestamp for turning ON next step
	unsigned m_timeOffStepDownstairs; // Timestamp for turning ON next step

	unsigned m_timeUpstairsOff; // same as m_timeUpstairs but used for turning off the step's light
	unsigned m_timeDownstairsOff;

	/*std::array<bool, SETT_STEPS> m_ledStateUpstairs;
	std::array<bool, SETT_STEPS> m_ledStateDownstairs;*/
	bool* m_ledStateUpstairs;
	bool* m_ledStateDownstairs;

	bool m_currLedStateUpstairs;  // Current led state for new steps
	bool m_currLedStateDownstairs;  // Current led state for new steps

};

#endif //CSTAIRSSIMPLEWAVE_CSTAIRSSIMPLEWAVE_H