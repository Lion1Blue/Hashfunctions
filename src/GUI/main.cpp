#include "mainwindow.h"
#include <iostream>
#include "Hashfunctions/hashfunction.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();

	//unsigned long long test = 18446744073709551615LL;
	//std::cout << test << std::endl;
	//test = test + 123123LL;
	//
	//std::cout << test << std::endl;

	/*
	Hashfunction h;
	std::string a("È");
	unsigned long long result = h.PolynomialRollingHash(a);
	std::cout << a.at(0) << std::endl;
	std::cout << result << std::endl;
	*/
}
