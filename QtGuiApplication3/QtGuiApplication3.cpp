#include "QtGuiApplication3.h"

QtGuiApplication3::QtGuiApplication3(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.actionOpen_image, SIGNAL(triggered()), this, SLOT(image()));		//click button -> play slot
	connect(ui.actionOpen_Image_2, SIGNAL(triggered()), this, SLOT(image2()));		//click button -> play slot
	connect(ui.actionOpen_Image_3, SIGNAL(triggered()), this, SLOT(image3()));		//click button -> play slot
	connect(ui.actionOpen_Image_4, SIGNAL(triggered()), this, SLOT(image4()));		//click button -> play slot
	connect(ui.actionOpen_Image_5, SIGNAL(triggered()), this, SLOT(image5()));		//click button -> play slot
	connect(ui.actionOpen_Image_6, SIGNAL(triggered()), this, SLOT(image6()));		//click button -> play slot
	connect(ui.actionCylindrical_Projection_image_1, SIGNAL(triggered()), this, SLOT(button5()));//equailzation
	connect(ui.actionInterpolation, SIGNAL(triggered()), this, SLOT(button6()));//equailzation
	//connect(dig.ui.pushButton, SIGNAL(clicked()), this, SLOT(print()));
}

void QtGuiApplication3::image() {	//display dialog

	filePath = QFileDialog::getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp *.raw)");  //picture's lotate save
	QFileInfo info(filePath);

	QString ext = info.suffix();
	
	QFile file(filePath); //file = filepath's file

	Img.load(filePath);

	buffer = QPixmap::fromImage(Img);   //save in buffer
	buffer = buffer.scaled(Img.width(), Img.height());
	
	

	ui.label->setPixmap(buffer);
	ui.label->setScaledContents(true);

}

void QtGuiApplication3::image2() {	//display dialog

	filePath = QFileDialog::getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp *.raw)");  //picture's lotate save
	QFileInfo info(filePath);

	QString ext = info.suffix();

	Img2.load(filePath);

	buffer = QPixmap::fromImage(Img2);   //save in buffer
	buffer = buffer.scaled(Img2.width(), Img2.height());

	ui.label_2->setPixmap(buffer);
	ui.label_2->setScaledContents(true);

}  //equal image 1~ 6 load method

void QtGuiApplication3::image3() {	//display dialog

	filePath = QFileDialog::getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp *.raw)");  //picture's lotate save
	QFileInfo info(filePath);

	QString ext = info.suffix();


	Img3.load(filePath);

	buffer = QPixmap::fromImage(Img3);   //save in buffer
	buffer = buffer.scaled(Img3.width(), Img3.height());

	ui.label_3->setPixmap(buffer);
	ui.label_3->setScaledContents(true);

}

void QtGuiApplication3::image4() {	//display dialog

	filePath = QFileDialog::getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp *.raw)");  //picture's lotate save
	QFileInfo info(filePath);

	QString ext = info.suffix();

	Img4.load(filePath);

	buffer = QPixmap::fromImage(Img4);   //save in buffer
	buffer = buffer.scaled(Img4.width(), Img4.height());

	ui.label_4->setPixmap(buffer);
	ui.label_4->setScaledContents(true);

}

void QtGuiApplication3::image5() {	//display dialog

	filePath = QFileDialog::getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp *.raw)");  //picture's lotate save
	QFileInfo info(filePath);

	QString ext = info.suffix();


	Img5.load(filePath);

	buffer = QPixmap::fromImage(Img5);   //save in buffer
	buffer = buffer.scaled(Img5.width(), Img5.height());

	ui.label_5->setPixmap(buffer);
	ui.label_5->setScaledContents(true);

}

void QtGuiApplication3::image6() {	//display dialog

	filePath = QFileDialog::getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp *.raw)");  //picture's lotate save
	QFileInfo info(filePath);

	QString ext = info.suffix();

	Img6.load(filePath);

	buffer = QPixmap::fromImage(Img6);   //save in buffer
	buffer = buffer.scaled(Img6.width(), Img6.height());

	ui.label_6->setPixmap(buffer);
	ui.label_6->setScaledContents(true);

}


void QtGuiApplication3::button5() {//equailiztion
	
	Dialog dig;
	dig.exec(); // dialog for input f

	double f = dig.f;  //receive focal point range

	if (Img.width() != NULL) {
		double x, y, x2, y2, h, o; // original picture point x,y   //   projection picture point x2,y2,   seta o, height h

		QImage Img_2 = Img;


		double hi = Img.height() / 2;
		double wi = Img.width() / 2;



		for (y2 = 0; y2 < Img.height(); y2++) {
			for (x2 = 0; x2 < Img.width(); x2++) {

				x2 = x2 - wi;  //translation to picture's center.
				y2 = hi - y2; //translation to picture's center.
				x = f * tan(((x2) / f));   //inverse warping
				y = hi - (y2 * (sqrt(pow(x, 2) + pow(f, 2)) / f));
				x = x + wi;
				x2 = x2 + wi;  //retranslation to picture's edge
				y2 = -y2 + hi;
				Img.setPixel(x2, y2, Img_2.pixel(x, y)); //finish inverse warping
			}
		}

		buffer = QPixmap::fromImage(Img);   //save in buffer
		buffer = buffer.scaled(Img.width(), Img.height());

		ui.label->setPixmap(buffer);

		ui.label->setScaledContents(true);
	}

	if (Img2.width() != NULL) {					//Img2 ~ 6's projection is same.
		double x, y, x2, y2, h, o;

		QImage Img2_2 = Img2;


		double hi = Img2.height() / 2;
		double wi = Img2.width() / 2;



		for (y2 = 0; y2 < Img2.height(); y2++) {
			for (x2 = 0; x2 < Img2.width(); x2++) {

				x2 = x2 - wi;
				y2 = hi - y2;
				x = f * tan(((x2) / f));
				y = hi - (y2 * (sqrt(pow(x, 2) + pow(f, 2)) / f));
				x = x + wi;
				x2 = x2 + wi;
				y2 = -y2 + hi;
				Img2.setPixel(x2, y2, Img2_2.pixel(x, y));
			}
		}

		buffer = QPixmap::fromImage(Img2);   //save in buffer
		buffer = buffer.scaled(Img2.width(), Img2.height());

		ui.label_2->setPixmap(buffer);

		ui.label_2->setScaledContents(true);
	}

	if (Img3.width() != NULL) {
		double x, y, x2, y2,h, o;

		QImage Img3_2 = Img3;


		double hi = Img3.height() / 2;
		double wi = Img3.width() / 2;



		for (y2 = 0; y2 < Img3.height(); y2++) {
			for (x2 = 0; x2 < Img3.width(); x2++) {

				x2 = x2 - wi;
				y2 = hi - y2;
				x = f * tan(((x2) / f));
				y = hi - (y2 * (sqrt(pow(x, 2) + pow(f, 2)) / f));
				x = x + wi;
				x2 = x2 + wi;
				y2 = -y2 + hi;
				Img3.setPixel(x2, y2, Img3_2.pixel(x, y));
			}
		}

		buffer = QPixmap::fromImage(Img3);   //save in buffer
		buffer = buffer.scaled(Img3.width(), Img3.height());

		ui.label_3->setPixmap(buffer);

		ui.label_3->setScaledContents(true);
	}

	if (Img4.width() != NULL) {
		double x, y, x2, y2,  h, o;

		QImage Img4_2 = Img4;


		double hi = Img4.height() / 2;
		double wi = Img4.width() / 2;



		for (y2 = 0; y2 < Img4.height(); y2++) {
			for (x2 = 0; x2 < Img4.width(); x2++) {

				x2 = x2 - wi;
				y2 = hi - y2;
				x = f * tan(((x2) / f));
				y = hi - (y2 * (sqrt(pow(x, 2) + pow(f, 2)) / f));
				x = x + wi;
				x2 = x2 + wi;
				y2 = -y2 + hi;
				Img4.setPixel(x2, y2, Img4_2.pixel(x, y));
			}
		}

		buffer = QPixmap::fromImage(Img4);   //save in buffer
		buffer = buffer.scaled(Img4.width(), Img4.height());

		ui.label_4->setPixmap(buffer);

		ui.label_4->setScaledContents(true);
	}

	if (Img5.width() != 0) {
		double x, y, x2, y2, h, o;

		QImage Img5_2 = Img5;


		double hi = Img5.height() / 2;
		double wi = Img5.width() / 2;



		for (y2 = 0; y2 < Img5.height(); y2++) {
			for (x2 = 0; x2 < Img5.width(); x2++) {

				x2 = x2 - wi;
				y2 = hi - y2;
				x = f * tan(((x2) / f));
				y = hi - (y2 * (sqrt(pow(x, 2) + pow(f, 2)) / f));
				x = x + wi;
				x2 = x2 + wi;
				y2 = -y2 + hi;
				Img5.setPixel(x2, y2, Img5_2.pixel(x, y));
			}
		}

		buffer = QPixmap::fromImage(Img5);   //save in buffer
		buffer = buffer.scaled(Img5.width(), Img5.height());

		ui.label_5->setPixmap(buffer);

		ui.label_5->setScaledContents(true);
	}

	if (Img6.width() != NULL) {
		double x, y, x2, y2, h, o;

		QImage Img6_2 = Img6;


		double hi = Img6.height() / 2;
		double wi = Img6.width() / 2;



		for (y2 = 0; y2 < Img6.height(); y2++) {
			for (x2 = 0; x2 < Img6.width(); x2++) {

				x2 = x2 - wi;
				y2 = hi - y2;
				x = f * tan(((x2) / f));
				y = hi - (y2 * (sqrt(pow(x, 2) + pow(f, 2)) / f));
				x = x + wi;
				x2 = x2 + wi;
				y2 = -y2 + hi;
				Img6.setPixel(x2, y2, Img6_2.pixel(x, y));
			}
		}

		buffer = QPixmap::fromImage(Img6);   //save in buffer
		buffer = buffer.scaled(Img6.width(), Img6.height());

		ui.label_6->setPixmap(buffer);

		ui.label_6->setScaledContents(true);
	}















}


void QtGuiApplication3::button6() { //interpolation
	if (Img.width() != NULL) {
		QRgb left = 0;
		QRgb right = 0;


		for (int i = 0; i < Img.height(); i++) {
			for (int j = 0; j < Img.width(); j++) {
				if (j == 0) {		//if image left side.
					right = Img.pixel(i, j + 1);
					left = right;
				}
				else if (j == Img.width() - 1) { //if image right side
					left = Img.pixel(i, j - 1);
					right = left;
				}
				else { // if image pixel has left,right pixel.
					left = Img.pixel(i, j - 1);
					right = Img.pixel(i, j + 1);
				}


				if (Img.pixel(i, j) == 0 && left != 0 && right != 0) { //using linear interpolation
					Img.setPixel(i, j, (left + right) / 2);
				}
			}
		}

		buffer = QPixmap::fromImage(Img);   //save in buffer
		buffer = buffer.scaled(Img.width(), Img.height());

		ui.label->setPixmap(buffer);

		ui.label->setScaledContents(true);
	}

	if (Img2.width() != NULL) {
		QRgb left = 0;
		QRgb right = 0;


		for (int i = 0; i < Img2.height(); i++) {
			for (int j = 0; j < Img2.width(); j++) {
				if (j == 0) {
					right = Img2.pixel(i, j + 1);
					left = right;
				}
				else if (j == Img2.width() - 1) {
					left = Img2.pixel(i, j - 1);
					right = left;
				}
				else {
					left = Img2.pixel(i, j - 1);
					right = Img2.pixel(i, j + 1);
				}


				if (Img2.pixel(i, j) == 0 && left != 0 && right != 0) {
					Img2.setPixel(i, j, (left + right) / 2);
				}
			}
		}

		buffer = QPixmap::fromImage(Img2);   //save in buffer
		buffer = buffer.scaled(Img2.width(), Img2.height());

		ui.label_2->setPixmap(buffer);

		ui.label_2->setScaledContents(true);
	}

	if (Img3.width() != NULL) {
		QRgb left = 0;
		QRgb right = 0;


		for (int i = 0; i < Img3.height(); i++) {
			for (int j = 0; j < Img3.width(); j++) {
				if (j == 0) {
					right = Img3.pixel(i, j + 1);
					left = right;
				}
				else if (j == Img3.width() - 1) {
					left = Img3.pixel(i, j - 1);
					right = left;
				}
				else {
					left = Img3.pixel(i, j - 1);
					right = Img3.pixel(i, j + 1);
				}


				if (Img3.pixel(i, j) == 0 && left != 0 && right != 0) {
					Img3.setPixel(i, j, (left + right) / 2);
				}
			}
		}

		buffer = QPixmap::fromImage(Img3);   //save in buffer
		buffer = buffer.scaled(Img3.width(), Img3.height());

		ui.label_3->setPixmap(buffer);

		ui.label_3->setScaledContents(true);
	}

	if (Img4.width() != NULL) {
		QRgb left = 0;
		QRgb right = 0;


		for (int i = 0; i < Img4.height(); i++) {
			for (int j = 0; j < Img4.width(); j++) {
				if (j == 0) {
					right = Img4.pixel(i, j + 1);
					left = right;
				}
				else if (j == Img4.width() - 1) {
					left = Img4.pixel(i, j - 1);
					right = left;
				}
				else {
					left = Img4.pixel(i, j - 1);
					right = Img4.pixel(i, j + 1);
				}


				if (Img4.pixel(i, j) == 0 && left != 0 && right != 0) {
					Img4.setPixel(i, j, (left + right) / 2);
				}
			}
		}

		buffer = QPixmap::fromImage(Img4);   //save in buffer
		buffer = buffer.scaled(Img4.width(), Img4.height());

		ui.label_4->setPixmap(buffer);

		ui.label_4->setScaledContents(true);
	}

	if (Img5.width() != NULL) {
		QRgb left = 0;
		QRgb right = 0;


		for (int i = 0; i < Img5.height(); i++) {
			for (int j = 0; j < Img5.width(); j++) {
				if (j == 0) {
					right = Img5.pixel(i, j + 1);
					left = right;
				}
				else if (j == Img5.width() - 1) {
					left = Img5.pixel(i, j - 1);
					right = left;
				}
				else {
					left = Img5.pixel(i, j - 1);
					right = Img5.pixel(i, j + 1);
				}


				if (Img5.pixel(i, j) == 0 && left != 0 && right != 0) {
					Img5.setPixel(i, j, (left + right) / 2);
				}
			}
		}

		buffer = QPixmap::fromImage(Img5);   //save in buffer
		buffer = buffer.scaled(Img5.width(), Img5.height());

		ui.label_5->setPixmap(buffer);

		ui.label_5->setScaledContents(true);
	}

	if (Img6.width() != NULL) {
		QRgb left = 0;
		QRgb right = 0;


		for (int i = 0; i < Img6.height(); i++) {
			for (int j = 0; j < Img6.width(); j++) {
				if (j == 0) {
					right = Img6.pixel(i, j + 1);
					left = right;
				}
				else if (j == Img6.width() - 1) {
					left = Img6.pixel(i, j - 1);
					right = left;
				}
				else {
					left = Img6.pixel(i, j - 1);
					right = Img6.pixel(i, j + 1);
				}


				if (Img6.pixel(i, j) == 0 && left != 0 && right != 0) {
					Img6.setPixel(i, j, (left + right) / 2);
				}
			}
		}

		buffer = QPixmap::fromImage(Img6);   //save in buffer
		buffer = buffer.scaled(Img6.width(), Img6.height());

		ui.label_6->setPixmap(buffer);

		ui.label_6->setScaledContents(true);
	}
}