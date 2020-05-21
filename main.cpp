#include "../WiringPi/wiringPi/wiringPi.h"
// #include <wiringPi.h>
#include <cmath>
#include <iostream>

class Synthesizer {
	static const int sampleRate = 48000;
};

class Oscillator {
};

int main() {
	const int pwmPin = 1;
	const int freqA = 440;
	const int delay = 20;
	const float pi = std::acos(-1);

	float phase;
	wiringPiSetup();
	pinMode(pwmPin, PWM_OUTPUT);

	while (true) {
		pwmWrite(pwmPin, std::sin(phase));
		phase += freqA * 2.0f * pi / 50000.0f;
		phase = std::fmod(phase, (2 * pi));
		delayMicroseconds(delay);
	}

	return 0;
}
