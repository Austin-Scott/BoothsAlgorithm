#include "toBinaryStrings.h"

string toBinaryString(Product value)
{
	return toBinaryString(value.getValue()) + to_string(value.getLeastSignificantBit());
}
