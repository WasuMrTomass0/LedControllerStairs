#pragma once

class IOutput 
{
public:
	IOutput() = default;
	virtual void setOutputState(bool) = 0;
	virtual ~IOutput() = default;
};
