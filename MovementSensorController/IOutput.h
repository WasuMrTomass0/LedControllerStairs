#pragma once

class IOutput {
public:
	IOutput() = default;
	virtual void outputState(bool) = 0;	// Read current state and pushes it away
	
	//virtual void setOutputState(bool) = 0;	// Gets current state from controller
	//virtual void pushOutput() = 0;		// Pushes output
};