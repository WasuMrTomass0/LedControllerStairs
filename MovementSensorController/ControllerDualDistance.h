#pragma once

#include "Settings.h"
#include "ISensor.h"
#include "IOutput.h"
#include "DSMeasurements.h"
#include "DSSlopeFactor.h"
#include "IController.h"

#include <array>

// Enum stages - but HOW?
enum class DirVerdict
{
	NONE,	// No movement
	OK,		// Can turn on the signal
	NOK		// Can NOT
};

// Config
constexpr data_t rangeMaxMeas = 1;	// Maximum measurement range

#define SCNT 2
class CControllerDualDistance: public IController
{
protected:
	ISensor* m_sensorLeft;
	ISensor* m_sensorRight;

	// Decide if Left and Right containers are REALLY needed

	DSMeasurements* m_MeasLeft;
	DSMeasurements* m_MeasRight;
	DSMeasurements* m_MeasMin;

	// Especially here

	DSSlopeFactor* m_slopeLeft;
	DSSlopeFactor* m_slopeRight;
	DSSlopeFactor* m_slopeMin;		//minimum indicates approaching object. Check it!

	IDataContainer<DirVerdict>* m_dirVerdicts;	// Verdicts stored

	time_type m_currTime;

protected:
	void measure();	// Read data from Sensors and upload to DataContainers
	void calculateSlope();
	bool makeVerdict();

public:
	CControllerDualDistance(IOutput*, ISensor*, ISensor*, unsigned);

	void mainLoop() final;
};