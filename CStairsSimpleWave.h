#ifndef CSTAIRSSIMPLEWAVE_CSTAIRSSIMPLEWAVE_H
#define CSTAIRSSIMPLEWAVE_CSTAIRSSIMPLEWAVE_H

#include "IStairs.h"

class CStairsSimpleWave: public IStairs{
public:
	CStairsSimpleWave(PWMMode, bool*, int*);

	void resetData() final;
	bool mainLoop() final;

protected:


};

#endif //CSTAIRSSIMPLEWAVE_CSTAIRSSIMPLEWAVE_H