#include "mainwindow.h"
#include <iostream>
#include "Hashfunctions/hashfunction.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	//QApplication a(argc, argv);
	//MainWindow w;
	//w.show();
	//return a.exec();

	Hashfunction hash;

	std::string testString = "hello world";

	hash.SHA256(testString);
}
