#pragma once
#include <string>

#include "Product.h"

using namespace std;

template<class T> string toBinaryString(T value) {
	string result = "";
	int numberOfBytes = sizeof(value);
	for (int byteOffset = numberOfBytes - 1; byteOffset >= 0; byteOffset--) {
		for (int bitOffset = 7; bitOffset >= 0; bitOffset--) {
			T bitmask = (T)1<<(8*byteOffset+bitOffset);
			if (value&bitmask) {
				result.push_back('1');
			}
			else {
				result.push_back('0');
			}
		}
	}
	return result;
}

string toBinaryString(Product value);