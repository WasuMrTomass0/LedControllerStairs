#pragma once

#include "Settings.h"

template<typename T>
class IDataContainer{
protected:
	const unsigned m_size;		// Tab size
	int m_index;				// Points to last added data
	T* m_data;					// Tab with stored data
	bool m_newDataFlag;			// After calculation flag is cleared

protected:
	void incrIndex(){ m_index = (m_index + 1) % m_size; }
	unsigned corrIndex(int index) { return index % m_size; }

public:
	IDataContainer(const unsigned size)
		: m_size(size)
		, m_index(0)
		, m_newDataFlag(false)
		, m_data(new T[size])
	{
	}

	~IDataContainer() {
		delete(m_data);
	}

	void addValue(T value){
		incrIndex(); 
		m_data[m_index] = value;
		m_newDataFlag = true;
	}
	
	T get_newest_value() { return m_data[corrIndex(m_index)]; }
	T get_oldest_value() { return m_data[corrIndex(m_index+1)]; }


	bool allEqualTo(const T&) {
		for (unsigned i = 0; i < m_size; i++) {
			if (T != m_data[i]) return false;
		}
		return true;
	}
};

