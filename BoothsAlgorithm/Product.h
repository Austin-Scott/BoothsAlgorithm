#pragma once
#include <cstdint>
#include <string>

using namespace std;

class Product {
private:
	//Signed 16 bit integer
	int16_t value;
	//Stores the value of the additional 17th bit
	bool leastSignificantBit;
public:
	Product(int8_t multiplier);
	int16_t getValue();
	bool getLeastSignificantBit();
	int8_t getLastTwoBits();
	void add(int8_t multiplicand);
	void arithmeticRightShift();
};