#include "hashfunction.h"
#include <cmath>
#include <iostream>
#include <bitset>

Hashfunction::Hashfunction() {

}

Hashfunction::~Hashfunction() {

}


const std::string Hashfunction::SHA256(std::string &input)
{
	//Step 1 Pre-Processing
	std::string binaryData = "";
	//convert to string to binary
	for (auto letter : input) {
		binaryData.append(std::bitset<8>(letter).to_string());
	}
	unsigned int binaryDataLength = binaryData.length();

	//Append a single 1
	binaryData.append("1");

	//Pad with 0´s until data is a multiple of 512, less 64 bits
	while (binaryData.length() < (512 - 64))
		binaryData.append("0");

	//Append 64 bits to the end, where the 64 bits are a big-edian integer representing the length of the oríginal input in binary
	binaryData.append(std::bitset<64>(binaryDataLength).to_string());

	//Setp 2 Initialize Hash Values
	//Now we create 8 hash values. These are hard-coded constants that represent the first 32 bits
	//of the fractional parts of the square roots of the first 8 primes: 2, 3, 5, 7, 11, 13, 17, 19
	int h0 = 0x6a09e667;
	int h1 = 0xbb67ae85;
	int h2 = 0x3c6ef372;
	int h3 = 0xa54ff53a;
	int h4 = 0x510e527f;
	int h5 = 0x9b05688c;
	int h6 = 0x1f83d9ab;
	int h7 = 0x5be0cd19;

	//Setp 3 Initialize Round Constants
	//Similar to step 2, we are creating some constants. This time, there are 64 of them.
	//Each value (0-63) is the first 32 bits of the fractional parts of the cube roots of the first 64 primes (2 – 311).



	//Step 4 Chunk Loop

	//Step 5 Create Message Schedule
	//copy the input data from step 1 into a new array where each entry is a 32-bit word

	//add 48 more words initialized to zero, such that we have an array w[0-63]

	//Step 6 Compression

	//Step 7 Modify Final Values

	//Step 8 Concatenate Final Hash

	return input;
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


// http://www.partow.net/programming/hashfunctions/index.html#top
const unsigned long long Hashfunction::RSHash(const std::string& input)
{
	const unsigned long long b = 378551;
	unsigned long long a = 63689;
	unsigned long long hash = 0;

	for (std::size_t i = 0; i < input.length(); i++)
	{
		hash = hash * a + input[i];
		a = a * b;
	}

	return hash;
}


// http://www.partow.net/programming/hashfunctions/index.html#top
const unsigned long long Hashfunction::ELFHash(const std::string& input)
{
	unsigned long long hash = 0;
	unsigned long long x = 0;

	for (std::size_t i = 0; i < input.length(); i++)
	{
		hash = (hash << 4) + input[i];
		if ((x = hash & 0xF0000000LL) != 0)
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