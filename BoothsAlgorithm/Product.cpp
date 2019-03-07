#include "Product.h"

Product::Product(int8_t multiplier)
{
	leastSignificantBit = 0;
	value = 0;
	//TODO
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
	//TODO
	return int8_t();
}

void Product::add(int8_t multiplicand)
{
	//TODO
}

void Product::arithmeticRightShift()
{
	//TODO
}
