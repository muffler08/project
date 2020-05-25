#pragma once

#include "ui_QtGuiApplication3.h"
#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <qdialog.h>
#include <qimage.h>
#include <qpixmap.h>
#include<qaction.h>
#include<qtransform.h>
#include <math.h>
#include"Dialog.h"
#
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qimage.h>
#include <qbuffer.h>
#include<qpoint.h>
#include <qfiledialog.h>
class QtGuiApplication3 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication3(QWidget *parent = Q_NULLPTR);

	Ui::QtGuiApplication3Class ui;
	QString filePath;

	QImage Img, Img2, Img3, Img4, Img5, Img6;       // QImage for image to load
	QPixmap buffer;  // QPixmap use for buffer
	QPixmap buffer2;  // QPixmap use for buffer

	QByteArray array1;

	QTransform transform; //rotate

	unsigned char array[17] = { 0, }; //histogram array
	int height = 0;
	int width = 0;

	//unsigned char rotate[731][731] = { 0, };

	//unsigned char rotate45[731 * 731] = { 0, };



private:



public slots:
	void image();		//slot load image
	void image2();		//slot load image
	void image3();		//slot load image
	void image4();		//slot load image
	void image5();		//slot load image
	void image6();		//slot load image
	void button5();//projection
	void button6(); //interpolation
};
