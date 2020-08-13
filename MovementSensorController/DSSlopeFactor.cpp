#include "DSSlopeFactor.h"

DSSlopeFactor::DSSlopeFactor(const unsigned size) : IDataContainer(size) {

}

void DSSlopeFactor::calculateSlope(data_t d_old, data_t d_new, time_type t_old, time_type t_new) {
	float slope = 0.0f;
	int diff_time = t_new - t_old;
	if (diff_time != 0) {
		int diff = d_new - d_old;
		if (abs(diff) < SLOPEFACTOR_MIN_DIFF) {
			slope = static_cast<float>(diff_time) / static_cast<float>(diff);
		}
	}
	addValue(slope);
}

void DSSlopeFactor::calculateMean() {
	float sum = 0.0f;
	for (unsigned i = 0; i < m_size; i++) sum += m_data[i];
	m_meanFactor = sum / static_cast<float>(m_size);
	m_newDataFlag = false;
}

float DSSlopeFactor::getSlopeFactor() { 
	if (m_newDataFlag) calculateMean();
	return m_meanFactor; 
}