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
{
}

void CControllerDualDistance::measure() {
	m_MeasLeft->addValue(m_sensorLeft->getMeas_cm());
	m_MeasRight->addValue(m_sensorRight->getMeas_cm());
	m_MeasMin->addValue(std::min<data_t>(m_MeasLeft->get_last_value(), m_MeasRight->get_last_value()));
}

void CControllerDualDistance::calculateSlope() {

}

bool CControllerDualDistance::makeVerdict() {
	return false;
}

void CControllerDualDistance::mainLoop() {
	m_currTime = millis();

	measure();

	calculateSlope();

	outputState(makeVerdict());
}