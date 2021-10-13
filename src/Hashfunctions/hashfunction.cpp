#include "hashfunction.h"
#include <cmath>
#include <iostream>

Hashfunction::Hashfunction() {

}

Hashfunction::~Hashfunction() {

}

const unsigned long long Hashfunction::PolynomialRollingHash(std::string& input, unsigned long long p, unsigned long long m) {

	unsigned long long result = 0;

	for (size_t i = 0; i < input.length(); i++) {
		result += PowULL(p, i) * input.at(i);
	}

	return result % m;
}

const unsigned long long Hashfunction::StringFolding(std::string& input, unsigned long long m) {

	unsigned long long result = 0;
	unsigned long long mul = 1;

	for (size_t i = 0; i < input.length(); i++) {
		mul = (i % 8 == 0) ? 1LL : mul * 256LL;
		result += input.at(i) * mul;
	}

	return result % m;
}

const unsigned long long  Hashfunction::RSHash(const char* str, unsigned int length)
{
	const unsigned long long b = 378551;
	unsigned long long a = 63689;
	unsigned long long hash = 0;

	for (int i = 0; i < length; ++str, ++i)
	{
		hash = hash * a + (*str);
		a = a * b;
	}

	return hash;
}

const unsigned long long Hashfunction::ELFHash(const char* str, unsigned int length)
{
	unsigned long long hash = 0;
	unsigned long long x = 0;

	for (int i = 0; i < length; ++str, ++i)
	{
		hash = (hash << 4) + (*str);

		if ((x = hash & 0xF00000000000L) != 0)
		{
			hash ^= (x >> 24);
		}

		hash &= ~x;
	}

	return hash;
}


const unsigned long long Hashfunction::PowULL(unsigned long long base, unsigned short exponent) {
	unsigned long long result = base;

	if (exponent == 0)
		return 1;

	for (int i = 1; i < exponent; i++) {
		result *= base;
	}

	return result;
}