// Interface for all stair controll classes

#ifndef ISTAIRS_ISTAIRS_H
#define ISTAIRS_ISTAIRS_H

#include "Settings.h"
#include <cstdlib>
#include <iostream>

unsigned long millis() {
	return 2;
}

enum ManualMode {
	ManualOn,
	ManualOff
};

enum LedMode{
	PWMOn,
	PWMOff
};

class IStairs{
public:
	IStairs(LedMode, bool*, int*);
	~IStairs() = default;
	
	virtual bool mainLoop() = 0;
	virtual void resetData() = 0;

	virtual void setMoveUpstairs() { m_upstairsOn = true;   m_timestampUpstairs = millis(); m_timestamp = m_timestampUpstairs;  } // = 0;
	virtual void setMoveDownstairs() { m_downstairsOn = true; m_timestampDownstairs = millis(); m_timestamp = m_timestampDownstairs; } // = 0;
	
	const unsigned get_steps() const {return m_steps;}
	LedMode get_ledMode() const {return m_ledMode;}
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

protected:
	const LedMode m_ledMode;
	const unsigned m_steps;

	bool* m_stepsState;
	int* m_stepsValue;
	
	unsigned m_timestampUpstairs;
	unsigned m_timestampDownstairs;
	unsigned m_timestamp;

	bool m_updateRegisters;

	bool m_downstairsOn;
	bool m_downstairsOff;
	bool m_upstairsOn;
	bool m_upstairsOff;
};
#endif // ISTAIRS_ISTAIRS_H
