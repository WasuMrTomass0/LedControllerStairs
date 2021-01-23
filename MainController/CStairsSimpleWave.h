#ifndef CSTAIRSSIMPLEWAVE_CSTAIRSSIMPLEWAVE_H
#define CSTAIRSSIMPLEWAVE_CSTAIRSSIMPLEWAVE_H

#include "IStairs.h"

class CStairsSimpleWave
	: public IStairs
{
public:
	CStairsSimpleWave(PWMMode, bool*, int*);
	void resetData() final;
	bool mainLoop() final;

protected:
	unsigned m_timeShiftUpstairs;   // Timestamp for turning ON next step
	unsigned m_timeShiftDownstairs; // Timestamp for turning ON next step

	unsigned m_timeUpstairsOff; // same as m_timeUpstairs but used for turning off the step's light
	unsigned m_timeDownstairsOff;

	bool* m_ledStateUpstairs;
	bool* m_ledStateDownstairs;
};

#endif //CSTAIRSSIMPLEWAVE_CSTAIRSSIMPLEWAVE_H