// Interface for all stair controll classes

#ifndef ISTAIRS_ISTAIRS_H
#define ISTAIRS_ISTAIRS_H

#include "Settings.h"

#include <cstdlib> // malloc
// #include <iostream>

enum ManualMode {
	ManualOn = 1,
	ManualOff = 0
};

enum LedMode{
	PWMOn = 1,
	PWMOff = 0
};

class IStairs{
public:
	IStairs(LedMode, bool*, int*, const unsigned, const unsigned, const unsigned, const unsigned, const unsigned);
	~IStairs() = default;
	
	virtual bool mainLoop() = 0;
	virtual void resetData() = 0;

	virtual void setMoveUpstairs()   { m_upstairsOn = true;   m_timeUpstairs = m_timeMvmnt = millis(); }
	virtual void setMoveDownstairs() { m_downstairsOn = true; m_timeDownstairs = m_timeMvmnt = millis(); }
	
	const unsigned get_steps() const {return m_steps;}
	LedMode get_ledMode() const {return m_ledMode;}
	bool* get_ledState() const  {return m_stepsState;}
	int* get_ledValues() const {return m_stepsValue;}

	bool get_updateRegisters();

/*
#ifdef DEBUG
	template<typename T>
	void printTab(T* tab, bool newLine = true) {
		if (newLine) std::cout << '\n';
		for (size_t i = 0; i < get_steps(); i++) std::cout << static_cast<T>(tab[i])<<' ';
		if (newLine) std::cout << '\n';
	}
#endif
*/

protected:
	void resetBaseClass();
	void switchAllTo(bool);
	bool updateValuesBasic(int*, bool*); // Manages m_stepsValue based on m_stepsState
	bool didTimePass(unsigned*, const unsigned, bool);

protected:
	const LedMode m_ledMode;
	const unsigned m_steps;
	const unsigned m_pwmValDiff; // Each value change
	const unsigned m_pwmValTimePeriod; // Period beetwen changes
	const unsigned m_nextStepOnPeriod; 
	const unsigned m_nextStepOffPeriod;


	bool* m_stepsState;
	int* m_stepsValue;

	unsigned m_timeUpstairs;
	unsigned m_timeDownstairs;
	unsigned m_timeMvmnt;

	unsigned m_timePwmValChange;

	bool m_updateRegisters;

	bool m_downstairsOn;
	bool m_downstairsOff;
	bool m_upstairsOn;
	bool m_upstairsOff;
};
#endif // ISTAIRS_ISTAIRS_H
