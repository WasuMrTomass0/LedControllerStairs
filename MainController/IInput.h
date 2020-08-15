#pragma once


class IInput
{
public:
	IInput() = default;
	~IInput() = default;

	virtual bool getInput() = 0;
};

