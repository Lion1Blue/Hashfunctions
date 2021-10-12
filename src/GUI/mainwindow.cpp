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

	ui->comboBoxAlgorithmns->insertItem(0, "String Folding");
	ui->comboBoxAlgorithmns->insertItem(1, "Polynomail Rolling Hash");

	ui->textEditOutput->setReadOnly(true);
	QObject::connect(ui->textEditInput, SIGNAL(textChanged()), this, SLOT(TextEditTextChanged()));

	
}

void MainWindow::GenerateClicked() {
	const int currentIndex = ui->comboBoxAlgorithmns->currentIndex();
	unsigned long long result = 0;
	Hashfunction hash;
	std::string input = ui->textEditInput->toPlainText().toStdString();

	switch (currentIndex)
	{
	//String Folding
	case 0:
		result = hash.StringFolding(input);
		break;

	//Polynomail Rolling Hash
	case 1: 
		result = hash.PolynomialRollingHash(input);
		break;

	default:
		break;
	}

	ui->textEditOutput->setText(QString::number(result));
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

