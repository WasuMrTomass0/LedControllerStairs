
#ifndef CSTAIRSBASIC_CSTAIRSBASIC_H
#define CSTAIRSBASIC_CSTAIRSBASIC_H

#include "IStairs.h"

class CStairsBasic: public IStairs{
	
public:
	CStairsBasic(LedMode, bool*, int*);
	//CStairsBasic(LedMode ledmode, bool* stepsState = nullptr, int* stepsValue = nullptr);
	
	void resetData();
	bool mainLoop() override;
	
protected:
	const unsigned int m_ledTime;
	bool m_currLedState;
};





#endif //CSTAIRSBASIC_CSTAIRSBASIC_H
