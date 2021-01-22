#pragma once

#include "Settings.h"

class IDistance 
{
public:
	IDistance() = default;
	virtual TYPE::distance getDistance() = 0;
	virtual ~IDistance() = default;
};

/*
	All inherits shall be declared in this file.
*/

// Ultrasound distance sensor HCSR04
class Distance_HCSR04 
	: public IDistance 
{
protected:
	const unsigned m_trigPin;
	const unsigned m_echoPin;

protected:
	TYPE::distance m_readDistance();

public:
	Distance_HCSR04(const unsigned trig, const unsigned echo) 
		: IDistance()
		, m_trigPin(trig)
		, m_echoPin(echo)
	
	{}
	/*
	W programie u¿ywanym przez ostatni okres czasu u¿yto niepoprawnego przelicznika. Jednak uda³o siê ustaliæ w³aœciwy próg detekcji.
		duration = pulseIn(echoPin, HIGH);
		distance = ((float) duration) / 58;
		if(distance < 750) Serial.println(distance);
		
		750 * 58 = 43500
		43500 * 0.17 = 7395
	*/
	TYPE::distance getDistance() { return static_cast<float>(m_readDistance()) * 0.17; }
	virtual ~Distance_HCSR04() = default;
};
