//#pragma once
//
//#include "Settings.h"
//#include "ISensor.h"
//#include "IOutput.h"
//#include "DSMeasurements.h"
//#include "DSSlopeFactor.h"
//#include "IController.h"
//
//#include <array>
//
//// Enum stages - but HOW?
//enum class DirVerdict
//{
//	NONE,	// No movement
//	OK,		// Can turn on the signal
//	NOK		// Can NOT
//};
//
//enum class Range
//{
//	OUT_STEP,
//	ON_STEP,
//
//};
//
//
//// Config
//constexpr data_t rangeMax = 1;	// Maximum measurement range
//constexpr data_t rangeDirActivate = 1;	// All measurements must be DirVerdict::OK
//constexpr data_t rangeAllActivate = 1;	// Half of measurements are enoug hto activate
//
//constexpr data_t AllActivate = 1;	// Maximum measurement range
//
//
//#define SCNT 2
//class CControllerDualDistance: public IController
//{
//protected:
//	ISensor* m_sensorLeft;
//	ISensor* m_sensorRight;
//
//	// Decide if Left and Right containers are REALLY needed
//
//	DSMeasurements* m_MeasLeft;		// Is it needed?
//	DSMeasurements* m_MeasRight;	// Is it needed?
//	DSMeasurements* m_MeasMin;
//
//	// Especially here
//
//	DSSlopeFactor* m_slopeLeft;		// Is it needed?
//	DSSlopeFactor* m_slopeRight;	// Is it needed?
//	DSSlopeFactor* m_slopeMin;		//minimum indicates approaching object. Check it!
//
//	IDataContainer<DirVerdict>* m_dirVerdicts;	// Verdicts stored
//	//IDataContainer<DirVerdict>* m_rangeZonesHistory;	
//	IDataContainer<time_type>* m_time;			// Time stored
//
//	time_type m_currTime;
//
//protected:
//	void measure();					// Read data from Sensors and upload to DataContainers
//	void calculateSlope();
//	void decideDirection();
//
//	bool makeVerdict();
//
//public:
//	CControllerDualDistance(IOutput*, ISensor*, ISensor*, unsigned);
//
//	void mainLoop() final;
//};