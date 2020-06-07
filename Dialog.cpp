#include "Dialog.h"

Dialog::Dialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//mainGui = new QtGuiApplication3;
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(button()));   //select picture
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(button2())); //cancel

	dia1 = 0;
	dia2 = 0;
}

Dialog::~Dialog()
{
}


void Dialog::button() {
								//input Height & Width
	QString focal = ui.textEdit->toPlainText();

	f = focal.toDouble();
	

		
	
	close();
}

void Dialog::button2() {

	close(); //cancel button

}