#include "Product.h"

Product::Product(int8_t multiplier)
{
	leastSignificantBit = 0;
	value = 0;
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
	value += ((int16_t)multiplicand << 8);
}

void Product::arithmeticRightShift()
{
	leastSignificantBit = (bool)(value & 1);
	value = value >> 1;
}
