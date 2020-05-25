#pragma once

#include "ui_Dialog.h"
#include <QDialog>

#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qbuffer.h>

class Dialog : public QDialog
{
	Q_OBJECT

public:

	Dialog(QWidget *parent = Q_NULLPTR);
	~Dialog();

	Ui::Dialog ui;
	double f;
	int dia1 = 0;//key
	int dia2 = 0;
	QPixmap buffer;
	QString filePath;
	QByteArray array1;
	QImage* rawImg;

	//unsigned char* data;
	int wid2, hei2;


private:

public slots:
	void button(); //select picture
	void button2(); // cancel
};
