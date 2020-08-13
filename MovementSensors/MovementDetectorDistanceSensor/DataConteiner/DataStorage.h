#pragma once

#include "Settings.h"

struct TimedMeauserement {
	time_t time;
	data_t value;
	TimedMeauserement(data_t, time_t);
};

class DataContainer
{
protected:
	const unsigned m_size;		// Tab size
	int m_index;			// Points to last added data
	TimedMeauserement* m_data;	// Tab with stored data
	
	

	bool newDataFlag;	// After caluclation flag is cleared


protected:
	void incrIndex() { m_index = (m_index + 1) % m_size; }

public:
	DataContainer(const unsigned);

	void addValue(data_t value, time_t time) {
		incrIndex();
		m_data[m_index] = TimedMeauserement(value, time);
	}
	
	float getSlopeFactor();


};

