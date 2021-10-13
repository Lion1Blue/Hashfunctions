#pragma once
#include <string>


class Hashfunction
{
public:
	Hashfunction();
	~Hashfunction();

	const unsigned long long PolynomialRollingHash(std::string &input, unsigned long long p = 53, unsigned long long m = 14495372961309516197);
	const unsigned long long StringFolding(std::string &input, unsigned long long m = 14495372961309516197);
	const unsigned long long RSHash(const char* str, unsigned int length);
	const unsigned long long ELFHash(const char* str, unsigned int length);

private:

	const unsigned long long PowULL(unsigned long long base, unsigned short exponent);
};

