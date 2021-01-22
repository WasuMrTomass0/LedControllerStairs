//#pragma once
//
//#include "DataStorage.h"
//
//struct TimedMeauserement {
//	time_type time;
//	data_t value;
//	TimedMeauserement(data_t d, time_type t) : value(d), time(t) {}
//	TimedMeauserement operator<(const TimedMeauserement& other) { return value < other.value ? *this : other; }
//	TimedMeauserement operator<=(const TimedMeauserement& other) { return value <= other.value ? *this : other; }
//	TimedMeauserement operator>(const TimedMeauserement& other) { return value > other.value ? *this : other; }
//	TimedMeauserement operator>=(const TimedMeauserement& other) { return value >= other.value ? *this : other; }
//	bool operator==(const TimedMeauserement& other) { return value == other.value; }
//	bool operator!=(const TimedMeauserement& other) { return value != other.value; }
//};
//
//class DSMeasurements : public IDataContainer<data_t>{
//	/* Class focused on storing measured distance data used to evaluate movement direction. */
//
//
//public:
//	DSMeasurements(unsigned);
//	/*void addValue(data_t d, time_type t) {
//		incrIndex();
//		m_data[m_index] = TimedMeauserement(d, t);
//		newDataFlag = true;
//	}*/
//};