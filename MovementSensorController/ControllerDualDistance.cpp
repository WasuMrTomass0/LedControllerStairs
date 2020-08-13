#include "ControllerDualDistance.h"


CControllerDualDistance::CControllerDualDistance(IOutput* output, ISensor* leftSensor, ISensor* rightSensor, unsigned size)
	: IController(output)
	, m_currTime(0)
	, m_sensorLeft(leftSensor)
	, m_sensorRight(rightSensor)
	, m_MeasLeft(new DSMeasurements(size))
	, m_MeasRight(new DSMeasurements(size))
	, m_MeasMin(new DSMeasurements(size))
	, m_slopeLeft(new DSSlopeFactor(size))
	, m_slopeRight(new DSSlopeFactor(size))
	, m_slopeMin(new DSSlopeFactor(size))
	, m_dirVerdicts(new IDataContainer<DirVerdict>(size))
	, m_time(new IDataContainer<time_type>(size))
{
}

void CControllerDualDistance::measure() {
	m_time->addValue(m_currTime);
	m_MeasLeft->addValue(m_sensorLeft->getMeas_cm());
	m_MeasRight->addValue(m_sensorRight->getMeas_cm());
	m_MeasMin->addValue(std::min<data_t>(m_MeasLeft->get_newest_value(), m_MeasRight->get_newest_value()));

	//m_MeasMin->addValue(std::min<data_t>(m_sensorLeft->getMeas_cm(), m_sensorRight->getMeas_cm()));
}

void CControllerDualDistance::calculateSlope() {
	m_slopeLeft->calculateSlope(
		m_MeasLeft->get_oldest_value(), m_MeasLeft->get_newest_value(),
		m_time->get_oldest_value(), m_time->get_newest_value()
	);
	m_slopeRight->calculateSlope(
		m_MeasRight->get_oldest_value(), m_MeasRight->get_newest_value(),
		m_time->get_oldest_value(), m_time->get_newest_value()
	);
	// // // // // // // // // //
	m_slopeMin->calculateSlope(
		m_MeasMin->get_oldest_value(), m_MeasMin->get_newest_value(),
		m_time->get_oldest_value(), m_time->get_newest_value()
	);
}

void CControllerDualDistance::decideDirection() {
	float slope = m_slopeMin->get_newest_value();
	DirVerdict ver;

	if (abs(slope) <= SLOPEFACTOR_MIN_SLOPE) ver = DirVerdict::NONE;
	else ver = slope < 0 ? DirVerdict::OK : DirVerdict::NOK;
	
	m_dirVerdicts->addValue(ver);
}

bool CControllerDualDistance::makeVerdict() {
	data_t val = m_MeasMin->get_newest_value();
	if (val <= rangeAllActivate) {	
		if (m_slopeMin->getSlopeFactor() > SLOPEFACTOR_MIN_SLOPE * 10.0) return true;
	}
	//if (val <= rangeDirActivate) { // All(?) must be DirVerdict::Ok
	//	return true;
	//}

	return false;
}

void CControllerDualDistance::mainLoop() {
	m_currTime = millis();

	measure();

	calculateSlope();

	decideDirection();

	outputState(makeVerdict());
}