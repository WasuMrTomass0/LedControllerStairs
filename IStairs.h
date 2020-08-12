// Interface for all stair controll classes

#ifndef ISTAIRS_ISTAIRS_H
#define ISTAIRS_ISTAIRS_H

#include "Settings.h"
#include "General.h"

#include <iostream>
#include <sstream>

enum ManualMode {
	ManualOn = 1,
	ManualOff = 0
};

enum PWMMode{
	PWMOn = 1,
	PWMOff = 0
};

class IStairs{
public:
	IStairs(PWMMode, bool*, int*, const unsigned, const unsigned, const unsigned, const unsigned);
	~IStairs() = default;
	
	virtual bool mainLoop() = 0;
	virtual void resetData() = 0;

	virtual void setMoveUpstairs() { m_upstairsOn = true;   m_timeUpstairs = m_timeMvmnt = millis(); }
	virtual void setMoveDownstairs() { m_downstairsOn = true; m_timeDownstairs = m_timeMvmnt = millis(); }
	
	const unsigned get_steps() const {return m_steps;}
	PWMMode get_ledMode() const {return m_ledMode;}
	bool* get_ledState() const  {return m_stepsState;}
	int* get_ledValues() const {return m_stepsValue;}

	bool get_updateRegisters();


#ifdef DEBUG
	template<typename T>
	void printTab(T* tab, bool newLine = true) {
		if (newLine) std::cout << '\n';
		for (size_t i = 0; i < get_steps(); i++) std::cout << static_cast<T>(tab[i])<<' ';
		if (newLine) std::cout << '\n';
	}
#endif


protected:
	void resetBaseClass();
	void switchAllTo(bool);
	//bool updateValuesBasic(int*, bool*); // Manages m_stepsValue based on m_stepsState // TODO Consider implementing
	bool updateValuesBasic(); // Manages m_stepsValue based on m_stepsState
	bool isPWMNeeded();
	

protected:
	const PWMMode m_ledMode;
	const unsigned m_steps;
	const unsigned int m_ledTime;		// How long are leds are ON?
	const unsigned m_pwmValDiff;		// Each value change (PWM)
	const unsigned m_pwmValTimePeriod;	// Period beetwen pwm values changes
	//const unsigned m_nextStepOnPeriod; 
	//const unsigned m_nextStepOffPeriod;
	const unsigned m_nextStepSwitchPeriod;
	/*	
		Time needed to light one step (0% to 100%):
		255/m_pwmValDiff * m_pwmValTimePeriod
	*/
	bool* m_stepsState;
	int* m_stepsValue;

	unsigned m_timeUpstairs;	// Used for movement flag upstairs
	unsigned m_timeDownstairs;	// Used for movement flag downstairs
	unsigned m_timeMvmnt;		// Used for movement flag

	unsigned m_timePwmValChange; // Previos value change in pwm values - timestamp

	bool m_updateRegisters;

	bool m_downstairsOn;
	bool m_downstairsOff;
	bool m_upstairsOn;
	bool m_upstairsOff;
};
#endif // ISTAIRS_ISTAIRS_H
