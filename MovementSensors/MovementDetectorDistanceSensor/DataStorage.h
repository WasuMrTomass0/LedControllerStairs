#pragma once

#include <array>

typedef unsigned data_t; // Stored data type
typedef unsigned time_t; // Stored time type

struct TimedMeauserement {
	time_t time;
	data_t value;
	TimedMeauserement(data_t, time_t);
};

class DataContainer
{
protected:
	TimedMeauserement* m_data;
	unsigned m_index;
	const unsigned m_size;

	void incrIndex() { m_index = (m_index + 1) % m_size; }

public:
	DataContainer(const unsigned);

	void addValue(data_t, time_t);
	

};

