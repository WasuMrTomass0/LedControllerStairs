#pragma once

class IInput 
{
public:
	IInput() = default;
	virtual bool getOutputState(bool) = 0;
	virtual ~IInput() = default;
};
