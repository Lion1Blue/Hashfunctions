#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Hashfunctions/hashfunction.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	QObject::connect(ui->pushButtonGenerate, SIGNAL(clicked()), this, SLOT(GenerateClicked()));

	ui->comboBoxAlgorithmns->insertItem(0, "Identity Function");
	ui->comboBoxAlgorithmns->insertItem(1, "String Folding");
	ui->comboBoxAlgorithmns->insertItem(2, "Polynomail Rolling Hash");
	ui->comboBoxAlgorithmns->insertItem(3, "Robert Sedgwicks Algorithm");
	ui->comboBoxAlgorithmns->insertItem(4, "ELF Hash");

	ui->textEditOutput->setReadOnly(true);
	QObject::connect(ui->textEditInput, SIGNAL(textChanged()), this, SLOT(TextEditTextChanged()));

	
}

void MainWindow::GenerateClicked() {
	const int currentIndex = ui->comboBoxAlgorithmns->currentIndex();
	unsigned long long result = 0;
	Hashfunction hash;
	std::string input = ui->textEditInput->toPlainText().toStdString();
	QString output = " ";

	switch (currentIndex)
	{
	//Identity Function
	case 0:
		output = ui->textEditInput->toPlainText();
		break;

	//String Folding
	case 1:
		result = hash.StringFolding(input);
		output = QString::number(result);
		break;

	//Polynomail Rolling Hash
	case 2: 
		result = hash.PolynomialRollingHash(input);
		output = QString::number(result);
		break;
	
	//RS Hash http://www.partow.net/programming/hashfunctions/index.html
	case 3:
		result = hash.RSHash(input);
		output = QString::number(result);
		break;

	//ELF Hash
	case 4:
		result = hash.ELFHash(input);
		output = QString::number(result);
		break;

	default:
		break;
	}

	ui->textEditOutput->setText(output);
}

void MainWindow::TextEditTextChanged() {
	if (ui->textEditInput->toPlainText().length() > 65535) {
		ui->textEditInput->setPlainText(ui->textEditInput->toPlainText().left(ui->textEditInput->toPlainText().length() - 1));
		ui->textEditInput->moveCursor(QTextCursor::End);
		QMessageBox::information(NULL, QString::fromUtf8("Warning"),
			QString::fromUtf8("Warning: no more then ") + QString::number(65535) + QString::fromUtf8(" characters in this field"),
			QString::fromUtf8("Ok"));
	}
}

MainWindow::~MainWindow()
{
    delete ui;
}

