#include "hashfunction.h"
#include <cmath>
#include <iostream>
#include <bitset>
#include <vector>
#include <array>
#include <string>
#include <sstream>

Hashfunction::Hashfunction() {

}

Hashfunction::~Hashfunction() {

}


const std::string Hashfunction::SHA256(std::string &input)
{
	//Step by Step Tutuorial https://qvault.io/cryptography/how-sha-2-works-step-by-step-sha-256/
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
	while ((binaryData.length() % 512) < (512 - 64))
		binaryData.append("0");

	//Append 64 bits to the end, where the 64 bits are a big-edian integer representing the length of the oríginal input in binary
	binaryData.append(std::bitset<64>(binaryDataLength).to_string());

	//Setp 2 Initialize Hash Values
	//Now we create 8 hash values. These are hard-coded constants that represent the first 32 bits
	//of the fractional parts of the square roots of the first 8 primes: 2, 3, 5, 7, 11, 13, 17, 19
	unsigned int h0 = 0x6a09e667;
	unsigned int h1 = 0xbb67ae85;
	unsigned int h2 = 0x3c6ef372;
	unsigned int h3 = 0xa54ff53a;
	unsigned int h4 = 0x510e527f;
	unsigned int h5 = 0x9b05688c;
	unsigned int h6 = 0x1f83d9ab;
	unsigned int h7 = 0x5be0cd19;

	//Setp 3 Initialize Round Constants
	//Similar to step 2, we are creating some constants. This time, there are 64 of them.
	//Each value (0-63) is the first 32 bits of the fractional parts of the cube roots of the first 64 primes (2 – 311).

	std::array<int, 64> k = { { 0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
									    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
									    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
									    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
									    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
									    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
									    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
									    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 } };

	//Step 4 Chunk Loop
	//The following steps will happen for each 512-bit “chunk” of data from our input. At each iteration of the loop,
	//we will be mutating the hash values h0-h7, which will be the final output.

	std::vector<std::string> chunks;

	for (size_t i = 0, chunkCount = binaryData.length() / 512; i < chunkCount; i++) {
		char chunk[512];
		size_t a = binaryData.copy(chunk, 512, i * 512);
		chunks.push_back(std::string(chunk));
	}

	//Step 5 Create Message Schedule
	for (auto chunk : chunks) {
		std::array<unsigned int, 64> w;

		//copy the input data from step 1 into a new array where each entry is a 32-bit word
		for (size_t i = 0; i < 16; i++) {
			std::string binary32Bits = chunk.substr(i * 32, 32);
			w[i] = std::stoi(binary32Bits, nullptr, 2);
		}

		//add 48 more words initialized to zero, such that we have an array w[0-63]
		for (size_t i = 16; i < 64; i++) {
			w[i] = 0;
		}

		//modify the zero-ed indexes at the end of the array using the following algorithm:
		//For i from w[16...63]:
		//	s0   = (W[i - 15] rightrotate 7) xor (w[i - 15] rightrotate 18) xor (w[i - 15] rightshift3)
		//  s1   = (w[i -2] rightrotate 17) xor (w[i - 2] rightrotate 19) xor (w[i - 2] rightsdhift 10)
		//  w[i] = w[i - 16] + s0 + w[i - 7] + s1

		for (size_t i = 16; i < 64; i++) {

			unsigned int s0 = (rightRotate(w[i - 15], 7)) ^ (rightRotate(w[i - 15], 18)) ^ (w[i - 15] >> 3);
			unsigned int s1 = (rightRotate(w[i - 2], 17)) ^ (rightRotate(w[i - 2], 19)) ^ (w[i - 2] >> 10);
			w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		}

		//Step 6 Compression
		unsigned int a = h0;
		unsigned int b = h1;
		unsigned int c = h2;
		unsigned int d = h3;
		unsigned int e = h4;
		unsigned int f = h5;
		unsigned int g = h6;
		unsigned int h = h7;

		for (size_t i = 0; i < 64; i++) {

			unsigned int s1 = (rightRotate(e, 6)) ^ (rightRotate(e, 11)) ^ (rightRotate(e, 25));
			unsigned int ch = (e & f) ^ (~e & g);
			unsigned int temp1 = h + s1 + ch + k[i] +w[i];
			unsigned int s0 = (rightRotate(a, 2)) ^ (rightRotate(a, 13)) ^ (rightRotate(a, 22));
			unsigned int maj = (a & b) ^ (a & c) ^ (b & c);
			unsigned int temp2 = s0 + maj;
			h = g;
			g = f;
			f = e;
			e = d + temp1;
			d = c;
			c = b;
			b = a;
			a = temp1 + temp2;
		}

		//Step 7 Modify Final Values
		//After the compression loop, but still, within the chunk loop, we modify the hash values ny adding
		//their respective variables to them, a-h. As usual, all addition is modulo 2^32

		h0 += a;
		h1 += b;
		h2 += c;
		h3 += d;
		h4 += e;
		h5 += f;
		h6 += g;
		h7 += h;
	}

	//Step 8 Concatenate Final Hash
	std::stringstream resultStream;

	resultStream << std::uppercase << std::hex << h0;
	resultStream << std::uppercase << std::hex << h1;
	resultStream << std::uppercase << std::hex << h2;
	resultStream << std::uppercase << std::hex << h3;
	resultStream << std::uppercase << std::hex << h4;
	resultStream << std::uppercase << std::hex << h5;
	resultStream << std::uppercase << std::hex << h6;
	resultStream << std::uppercase << std::hex << h7;

	return resultStream.str();
}

unsigned int Hashfunction::leftRotate(unsigned int n, unsigned int d) {
	return (n << d) | (n >> (32 - d));
}

unsigned int Hashfunction::rightRotate(unsigned int n, unsigned int d) {
	return (n >> d) | (n << (32 - d));
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