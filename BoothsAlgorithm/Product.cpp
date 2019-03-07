#include "Product.h"

Product::Product(int8_t multiplier)
{
	leastSignificantBit = 0;
	value = 0;
	//Uses a bitmask to ensure only the last byte of value changes with respect to multiplier
	value += ((int16_t)multiplier)&0x00FF;
}

int16_t Product::getValue()
{
	return value;
}

bool Product::getLeastSignificantBit()
{
	return leastSignificantBit;
}

int8_t Product::getLastTwoBits()
{
	return (int8_t)((value & 1) << 1) + (int8_t)leastSignificantBit;
}

void Product::add(int8_t multiplicand)
{
	//Adds multiplicand to the most significant byte of value
	value += ((int16_t)multiplicand << 8);
}

void Product::arithmeticRightShift()
{
	//Update the leastSignificantBit and arithmetic right shift value
	leastSignificantBit = (bool)(value & 1);
	value = value >> 1;
}
