#include "GlobalFunctions.h"
#include "Settings.h"

void buzzer_blink(unsigned n_times, unsigned period)
{
	if (period > 200) period = 200; // Max delay value
	for (size_t i = 0; i < n_times; ++i)
	{
		digitalWrite(PINOUT::DS_BUZZER, HIGH);
		delay(period);
		digitalWrite(PINOUT::DS_BUZZER, LOW);
		delay(period);
	}
}
