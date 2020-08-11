
#ifndef CSTAIRSBASIC_CSTAIRSBASIC_H
#define CSTAIRSBASIC_CSTAIRSBASIC_H

#include "IStairs.h"

class CStairsBasic: public IStairs{
	
public:
	CStairsBasic(PWMMode, bool*, int*);
	//CStairsBasic(PWMMode ledmode, bool* stepsState = nullptr, int* stepsValue = nullptr);
	
	void resetData() final;
	bool mainLoop() final;
	
protected:
	const unsigned int m_ledTime;
	bool m_currLedState;
};

#endif //CSTAIRSBASIC_CSTAIRSBASIC_H
