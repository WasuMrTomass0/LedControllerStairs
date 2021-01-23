#ifndef CSTAIRSBASIC_CSTAIRSBASIC_H
#define CSTAIRSBASIC_CSTAIRSBASIC_H

#include "IStairs.h"

class CStairsBasic
	: public IStairs
{
public:
	CStairsBasic(PWMMode, bool*, int*);
	
	void resetData() final;
	bool mainLoop() final;
	
protected:
	bool m_currLedState;
};

#endif //CSTAIRSBASIC_CSTAIRSBASIC_H
