#include "CSensorHCSr04.h"

data_t CSensorHCSr04::getMeausrement() {
	digitalWrite(m_trig, LOW);
	delayMicroseconds(2);
	digitalWrite(m_trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(m_trig, LOW);
	return pulseIn(m_echo, HIGH);
}