#include "Distance.h"

TYPE::distance Distance_HCSR04::m_readDistance() {
	digitalWrite(m_trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(m_trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(m_trigPin, LOW);
	return pulseIn(m_echoPin, HIGH);
}
