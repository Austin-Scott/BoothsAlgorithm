#include "inputNumber.h"

int8_t inputNumber()
{
	int selection = 0;
	while (true) {
		cin.clear();
		cin >> selection;
		if (selection >= INT8_MIN && selection <= INT8_MAX)
			return (int8_t)selection;
		cout << "Error. Please enter a number from " << (int)INT8_MIN << " to " << (int)INT8_MAX << ": ";
	}
}
