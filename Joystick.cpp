#include "MMap.h"

#define JOY_X_CH 0 // ADC_IN0
#define JOY_Y_CH 1 // ADC_IN1
#define MIN_ADC 0
#define MAX_ADC 4095
#define MID_ADC ((MAX_ADC+MIN_ADC)/2)
#define DEADBAND 600

class Joystick {
	MMap* _mmio;

private:
    int read(int ch) {
		return 0;
	}

public:
	Joystick(MMap* m) {_mmio = m;}

	// Returns 'f', 'b', 'l', 'r', or 0 for no push.
	char GetCommand() {
		int x = read(JOY_X_CH);
		int y = read(JOY_Y_CH);

		if (y > MID_ADC + DEADBAND) return 'f'; // pushed up
		if (y < MID_ADC - DEADBAND)  return 'b'; // pushed down
		if (x > MID_ADC + DEADBAND) return 'l'; // pushed left
		if (x < MID_ADC - DEADBAND)  return 'r'; // pushed right
		return 0; // in the middle: not pushed
	}

	// Print the adc value read
	void Print() {
		std::cout << "X=" << read(JOY_X_CH) << "  Y=" << read(JOY_Y_CH) << std::endl;
	}
};