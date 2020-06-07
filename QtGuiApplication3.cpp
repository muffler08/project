#include "QtGuiApplication3.h"


bool maxmin(QImage Image, QImage Image2, QImage Image3, int x, int y) {
	if (Image2.pixel(x - 1, y) < Image.pixel(x, y) &&
		Image2.pixel(x, y - 1) < Image.pixel(x, y) &&
		Image2.pixel(x + 1, y) < Image.pixel(x, y) &&
		Image2.pixel(x, y + 1) < Image.pixel(x, y) &&
		Image2.pixel(x + 1, y + 1) < Image.pixel(x, y) &&
		Image2.pixel(x - 1, y - 1) < Image.pixel(x, y) &&
		Image2.pixel(x - 1, y + 1) < Image.pixel(x, y) &&
		Image2.pixel(x + 1, y - 1) < Image.pixel(x, y) &&
		Image2.pixel(x, y) < Image.pixel(x, y) &&

		Image3.pixel(x, y) < Image.pixel(x, y) &&
		Image3.pixel(x, y - 1) < Image.pixel(x, y) &&
		Image3.pixel(x + 1, y) < Image.pixel(x, y) &&
		Image3.pixel(x, y + 1) < Image.pixel(x, y) &&
		Image3.pixel(x + 1, y + 1) < Image.pixel(x, y) &&
		Image3.pixel(x - 1, y - 1) < Image.pixel(x, y) &&
		Image3.pixel(x - 1, y + 1) < Image.pixel(x, y) &&
		Image3.pixel(x + 1, y - 1) < Image.pixel(x, y) &&
		Image3.pixel(x, y) < Image.pixel(x, y) &&

		Image.pixel(x + 1, y) < Image.pixel(x, y) &&
		Image.pixel(x, y + 1) < Image.pixel(x, y) &&
		Image.pixel(x - 1, y) < Image.pixel(x, y) &&
		Image.pixel(x, y - 1) < Image.pixel(x, y) &&
		Image.pixel(x + 1, y + 1) < Image.pixel(x, y) &&
		Image.pixel(x - 1, y - 1) < Image.pixel(x, y) &&
		Image.pixel(x + 1, y - 1) < Image.pixel(x, y) &&
		Image.pixel(x - 1, y + 1) < Image.pixel(x, y)) return true;
	else return false;
}


//button widget
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
	connect(ui.actionCylindrical_Projection_image_1, SIGNAL(triggered()), this, SLOT(button5()));//Cylindrical projection
	connect(ui.actionInterpolation, SIGNAL(triggered()), this, SLOT(button6()));//interpolation
	connect(ui.actionKeypoint_Detection, SIGNAL(triggered()), this, SLOT(button7()));//key point detection
	//connect(dig.ui.pushButton, SIGNAL(clicked()), this, SLOT(print()));
}


//load image 1~6
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

void QtGuiApplication3::image6() {	

	filePath = QFileDialog::getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp *.raw)");  //picture's lotate save
	QFileInfo info(filePath);

	QString ext = info.suffix();

	Img6.load(filePath);

	buffer = QPixmap::fromImage(Img6);   //save in buffer
	buffer = buffer.scaled(Img6.width(), Img6.height());

	ui.label_6->setPixmap(buffer);
	ui.label_6->setScaledContents(true);

}

//cylindercal projection
void QtGuiApplication3::button5() {//cylindercal projection
	
	Dialog dig;
	dig.exec(); // dialog for input f

	double f = dig.f;  //receive focal point range

	if (Img.width() != NULL) {
		double x, y, x2, y2, h, o; // original picture point x,y   //   projection picture point x2,y2,   seta o, height h

		QImage Img_2 = Img;


		double hi = Img.height() / 2;
		double wi = Img.width() / 2;

		height = Img.height();
		width = Img.width();


		for (y2 = 0; y2 < height; y2++) {
			for (x2 = 0; x2 < width; x2++) {

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
		height = Img2.height();
		width = Img2.width();


		for (y2 = 0; y2 < height; y2++) {
			for (x2 = 0; x2 < width; x2++) {

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

		height = Img3.height();
		width = Img3.width();
		double hi = Img3.height() / 2;
		double wi = Img3.width() / 2;



		for (y2 = 0; y2 < height; y2++) {
			for (x2 = 0; x2 < width; x2++) {

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

		height = Img4.height();
		width = Img4.width();
		double hi = Img4.height() / 2;
		double wi = Img4.width() / 2;



		for (y2 = 0; y2 < height; y2++) {
			for (x2 = 0; x2 <width; x2++) {

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

		height = Img5.height();
		width = Img5.width();

		for (y2 = 0; y2 < height; y2++) {
			for (x2 = 0; x2 < width; x2++) {

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
		height = Img6.height();
		width = Img6.width();


		for (y2 = 0; y2 < height; y2++) {
			for (x2 = 0; x2 < width; x2++) {

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

		height = Img.height();
		width = Img.width();

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0) {		//if image left side.
					right = Img.pixel(i, j + 1);
					left = right;
				}
				else if (j == width - 1) { //if image right side
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
		height = Img2.height();
		width = Img2.width();

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0) {
					right = Img2.pixel(i, j + 1);
					left = right;
				}
				else if (j == width - 1) {
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
		height = Img3.height();
		width = Img3.width();

		for (int i = 0; i <height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0) {
					right = Img3.pixel(i, j + 1);
					left = right;
				}
				else if (j == width - 1) {
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
		height = Img4.height();
		width = Img4.width();

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0) {
					right = Img4.pixel(i, j + 1);
					left = right;
				}
				else if (j == width - 1) {
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
		height = Img5.height();
		width = Img5.width();

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0) {
					right = Img5.pixel(i, j + 1);
					left = right;
				}
				else if (j == width - 1) {
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
		height = Img6.height();
		width = Img6.width();

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0) {
					right = Img6.pixel(i, j + 1);
					left = right;
				}
				else if (j == width - 1) {
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

void QtGuiApplication3::button7() {//key point detection
	//Gaussian  1/(2¤Ðo^2) * e^-(x^2 + y^2 / 2o^2)
	//double sigma = 1 / sqrt(2); 


	QImage Img_2_1, Img_2_2, Img_2_3, Img_2_4;		//x2 size image octave 1
	QImage Img_1_1, Img_1_2, Img_1_3, Img_1_4;		//x1 size image octave 2
	QImage Img_12_1, Img_12_2, Img_12_3, Img_12_4;  //x1/2 size image octave 3
	QImage Img_14_1, Img_14_2, Img_14_3, Img_14_4;  //x1/4 size image octave 4
	width = Img.width();
	height = Img.height();

	QImage Img_2_0(width * 2, height * 2, QImage::Format_RGB888); // x2 size image octave 1
	QImage Img_12_0(width / 2, height / 2, QImage::Format_RGB888);// x1/2 size image octave 3
	QImage Img_14_0(width / 4, height / 4, QImage::Format_RGB888);// x1/4 size image octave 4
	double sigma[4];

	sigma[0] = 1 / sqrt(2);
	sigma[1] = 1;
	sigma[2] = sqrt(2);
	sigma[3] = 2;


	double filt;
	double filter[4][5][5];
	double sum = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////make mask 5 level.
	for (int layer = 0; layer < 4; layer++) {
		sum = 0;
		for (int i = -2; i < 3; i++) { // first sigma = 1/v2 ,   and each step * v2
			for (int j = -2; j < 3; j++) {
				filt = exp(-(i * i + j * j) / (2 * sigma[layer] * sigma[layer])) / (2 * 3.14159265358979323846 * sigma[layer] * sigma[layer]);
				filter[layer][i + 2][j + 2] = filt;
				sum += filter[layer][i + 2][j + 2];
			}
		}

		sum = 1 / sum;
		for (int i = -2; i < 3; i++) { //nomalize 
			for (int j = -2; j < 3; j++) {
				filter[layer][i + 2][j + 2] = filter[layer][i + 2][j + 2] * sum;
			}
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	/////////////////////////////////////////////////////////////////////////////////////////make each octave first image.
	for (int x = 1; x < width - 1; x++) {
		for (int y = 1; y < height - 1; y++) {


			QColor a1(Img.pixelColor(x, y)), a2(Img.pixelColor(x + 1, y)), a3(Img.pixelColor(x, y + 1)), a4(Img.pixelColor(x + 1, y + 1));

			double  r1 = a1.red(), r2 = a2.red(), r3 = a3.red(), r4 = a4.red(),
				g1 = a1.green(), g2 = a2.green(), g3 = a3.green(), g4 = a4.green(),
				b1 = a1.blue(), b2 = a2.blue(), b3 = a3.blue(), b4 = a4.blue();

			Img_2_0.setPixel(x * 2, y * 2, Img.pixel(x, y));
			Img_2_0.setPixelColor(x * 2 + 1, y * 2, QColor((r1 + r2) / 2, (g1 + g2) / 2, (b1 + b2) / 2));
			Img_2_0.setPixelColor(x * 2, y * 2 + 1, QColor((r1 + r3) / 2, (g1 + g3) / 2, (b1 + b3) / 2));
			Img_2_0.setPixelColor(x * 2 + 1, y * 2 + 1, QColor((r1 + r2 + r3 + r4) / 4, (g1 + g2 + g3 + g4) / 4, (b1 + b2 + b3 + b4) / 4));   // make x2 size image.


			if (x < (Img.width() / 2) && y < (Img.height() / 2))Img_12_0.setPixel(x, y, Img.pixel(x * 2, y * 2)); //make x2 size image
			if (x < (Img.width() / 4) && y < (Img.height() / 4))Img_14_0.setPixel(x, y, Img.pixel(x * 4, y * 4)); //make x4 size image
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////

	Img_1_1 = Img, Img_1_2 = Img, Img_1_3 = Img, Img_1_4 = Img;
	Img_2_1 = Img_2_0, Img_2_2 = Img_2_0, Img_2_3 = Img_2_0, Img_2_4 = Img_2_0;
	Img_12_1 = Img_12_0, Img_12_2 = Img_12_0, Img_12_3 = Img_12_0, Img_12_4 = Img_12_0;
	Img_14_1 = Img_14_0, Img_14_2 = Img_14_0, Img_14_3 = Img_14_0, Img_14_4 = Img_14_0;


	for (int layer = 0; layer < 4; layer++) { //OCT.2  origin size. x1.

		for (int x = 2; x < width - 2; x++) {
			for (int y = 2; y < height - 2; y++) {

				double red = 0, green = 0, blue = 0;

				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {

						QColor pix2(Img.pixelColor(x - 2 + i, y - 2 + j));
						red += pix2.red() * filter[layer][i][j];
						green += pix2.green() * filter[layer][i][j];
						blue += pix2.blue() * filter[layer][i][j];


					}
				}


				QColor pix(red, green, blue);
				if (layer == 0)Img_1_1.setPixelColor(x, y, pix);
				else if (layer == 1)Img_1_2.setPixelColor(x, y, pix);
				else if (layer == 2)Img_1_3.setPixelColor(x, y, pix);
				else if (layer == 3)Img_1_4.setPixelColor(x, y, pix);
			}
		}

	}
	width = Img_2_0.width();
	height = Img_2_0.height();

	for (int layer = 0; layer < 4; layer++) { //OCT.1  origin size. x2

		for (int x = 2; x < width - 2; x++) {
			for (int y = 2; y < height - 2; y++) {

				double red = 0, green = 0, blue = 0;

				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {

						QColor pix2(Img_2_0.pixelColor(x - 2 + i, y - 2 + j));
						red += pix2.red() * filter[layer][i][j];
						green += pix2.green() * filter[layer][i][j];
						blue += pix2.blue() * filter[layer][i][j];


					}
				}


				QColor pix(red, green, blue);
				if (layer == 0)Img_2_1.setPixelColor(x, y, pix);
				else if (layer == 1)Img_2_2.setPixelColor(x, y, pix);
				else if (layer == 2)Img_2_3.setPixelColor(x, y, pix);
				else if (layer == 3)Img_2_4.setPixelColor(x, y, pix);
			}
		}

	}



	width = Img_12_0.width();
	height = Img_12_0.height();

	for (int layer = 0; layer < 4; layer++) { //OCT.3  origin size. x0.5 .

		for (int x = 2; x < width - 2; x++) {
			for (int y = 2; y < height - 2; y++) {

				double red = 0, green = 0, blue = 0;

				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {

						QColor pix2(Img_12_0.pixelColor(x - 2 + i, y - 2 + j));
						red += pix2.red() * filter[layer][i][j];
						green += pix2.green() * filter[layer][i][j];
						blue += pix2.blue() * filter[layer][i][j];


					}
				}


				QColor pix(red, green, blue);
				if (layer == 0)Img_12_1.setPixelColor(x, y, pix);
				else if (layer == 1)Img_12_2.setPixelColor(x, y, pix);
				else if (layer == 2)Img_12_3.setPixelColor(x, y, pix);
				else if (layer == 3)Img_12_4.setPixelColor(x, y, pix);
			}
		}

	}

	width = Img_14_0.width();
	height = Img_14_0.height();
	for (int layer = 0; layer < 4; layer++) { //OCT.4  origin size. x0.25.

		for (int x = 2; x < width - 2; x++) {
			for (int y = 2; y < height - 2; y++) {

				double red = 0, green = 0, blue = 0;

				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {

						QColor pix2(Img_14_0.pixelColor(x - 2 + i, y - 2 + j));
						red += pix2.red() * filter[layer][i][j];
						green += pix2.green() * filter[layer][i][j];
						blue += pix2.blue() * filter[layer][i][j];


					}
				}


				QColor pix(red, green, blue);
				if (layer == 0)Img_14_0.setPixelColor(x, y, pix);
				else if (layer == 1)Img_14_0.setPixelColor(x, y, pix);
				else if (layer == 2)Img_14_3.setPixelColor(x, y, pix);
				else if (layer == 3)Img_14_4.setPixelColor(x, y, pix);
			}
		}

	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////// finish of Gaussian blur image. ( 1~4 oct  & each oct have 5level.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////// 
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////make step by step DoG


	width = Img.width();
	height = Img.height();
	for (int x = 2; x < width - 2; x++) {  //make Difference of Gausssian image  (DOG image.)  Oct 1
		for (int y = 2; y < height - 2; y++) {
			QRgb dog4 = Img_1_3.pixel(x, y) - Img_1_4.pixel(x, y);
			if (dog4 < 0) dog4 *= (unsigned int)-1;
			Img_1_4.setPixel(x, y, dog4);

			QRgb dog3 = Img_1_2.pixel(x, y) - Img_1_3.pixel(x, y);
			if (dog3 < 0) dog3 *= (unsigned int)-1;
			Img_1_3.setPixel(x, y, dog3);

			QRgb dog2 = Img_1_1.pixel(x, y) - Img_1_2.pixel(x, y);
			if (dog2 < 0) dog2 *= (unsigned int)-1;
			Img_1_2.setPixel(x, y, dog2);

			QRgb dog1 = Img.pixel(x, y) - Img_1_1.pixel(x, y);
			if (dog1 < 0) dog1 *= (unsigned int)-1;
			Img_1_1.setPixel(x, y, dog1);


		}
	}


	width = Img_2_0.width();
	height = Img_2_0.height();
	for (int x = 2; x < width - 2; x++) {  //make Difference of Gausssian image  (DOG image.) Oct 2
		for (int y = 2; y < height - 2; y++) {
			QRgb dog4 = Img_2_3.pixel(x, y) - Img_2_4.pixel(x, y);
			if (dog4 < 0) dog4 *= (unsigned int)-1;
			Img_2_4.setPixel(x, y, dog4);

			QRgb dog3 = Img_2_2.pixel(x, y) - Img_2_3.pixel(x, y);
			if (dog3 < 0) dog3 *= (unsigned int)-1;
			Img_2_3.setPixel(x, y, dog3);

			QRgb dog2 = Img_2_1.pixel(x, y) - Img_2_2.pixel(x, y);
			if (dog2 < 0) dog2 *= (unsigned int)-1;
			Img_2_2.setPixel(x, y, dog2);

			QRgb dog1 = Img.pixel(x, y) - Img_2_1.pixel(x, y);
			if (dog1 < 0) dog1 *= (unsigned int)-1;
			Img_2_1.setPixel(x, y, dog1);


		}
	}


	width = Img_12_0.width();
	height = Img_12_0.height();
	for (int x = 2; x < width - 2; x++) {  //make Difference of Gausssian image  (DOG image.)
		for (int y = 2; y < height - 2; y++) {
			QRgb dog4 = Img_12_3.pixel(x, y) - Img_12_4.pixel(x, y);
			if (dog4 < 0) dog4 *= (unsigned int)-1;
			Img_12_4.setPixel(x, y, dog4);

			QRgb dog3 = Img_12_2.pixel(x, y) - Img_12_3.pixel(x, y);
			if (dog3 < 0) dog3 *= (unsigned int)-1;
			Img_12_3.setPixel(x, y, dog3);

			QRgb dog2 = Img_12_1.pixel(x, y) - Img_12_2.pixel(x, y);
			if (dog2 < 0) dog2 *= (unsigned int)-1;
			Img_12_2.setPixel(x, y, dog2);

			QRgb dog1 = Img.pixel(x, y) - Img_12_1.pixel(x, y);
			if (dog1 < 0) dog1 *= (unsigned int)-1;
			Img_12_1.setPixel(x, y, dog1);


		}
	}


	width = Img_14_0.width();
	height = Img_14_0.height();
	for (int x = 2; x < width - 2; x++) {  //make Difference of Gausssian image  (DOG image.)
		for (int y = 2; y < height - 2; y++) {
			QRgb dog4 = Img_14_3.pixel(x, y) - Img_14_4.pixel(x, y);
			if (dog4 < 0) dog4 *= (unsigned int)-1;
			Img_14_4.setPixel(x, y, dog4);

			QRgb dog3 = Img_14_2.pixel(x, y) - Img_14_3.pixel(x, y);
			if (dog3 < 0) dog3 *= (unsigned int)-1;
			Img_14_3.setPixel(x, y, dog3);

			QRgb dog2 = Img_14_1.pixel(x, y) - Img_14_2.pixel(x, y);
			if (dog2 < 0) dog2 *= (unsigned int)-1;
			Img_14_2.setPixel(x, y, dog2);

			QRgb dog1 = Img.pixel(x, y) - Img_14_1.pixel(x, y);
			if (dog1 < 0) dog1 *= (unsigned int)-1;
			Img_14_1.setPixel(x, y, dog1);


		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////// 
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	QColor redddd(219, 68, 85);

	width = Img.width();
	height = Img.height();
	//find maximum or minimum.
	for (int x = 1; x < width - 1; x++) {
		for (int y = 1; y < height - 1; y++) {



			if (Img.pixel(x - 1, y) > Img_1_1.pixel(x, y) &&
				Img.pixel(x, y - 1) > Img_1_1.pixel(x, y) &&
				Img.pixel(x + 1, y) > Img_1_1.pixel(x, y) &&
				Img.pixel(x, y + 1) > Img_1_1.pixel(x, y) &&
				Img.pixel(x + 1, y + 1) > Img_1_1.pixel(x, y) &&
				Img.pixel(x - 1, y - 1) > Img_1_1.pixel(x, y) &&
				Img.pixel(x - 1, y + 1) > Img_1_1.pixel(x, y) &&
				Img.pixel(x + 1, y - 1) > Img_1_1.pixel(x, y) &&
				Img.pixel(x, y) > Img_1_1.pixel(x, y) &&

				Img_1_2.pixel(x, y) > Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x, y - 1) > Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x + 1, y) > Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x, y + 1) > Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x + 1, y + 1) > Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x - 1, y - 1) > Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x - 1, y + 1) > Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x + 1, y - 1) > Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x, y) > Img_1_1.pixel(x, y) &&

				Img_1_1.pixel(x + 1, y) > Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x, y + 1) > Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x - 1, y) > Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x, y - 1) > Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x + 1, y + 1) > Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x - 1, y - 1) > Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x + 1, y - 1) > Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x - 1, y + 1) > Img_1_1.pixel(x, y)

				) {
				double Dx1 = Img_1_1.pixel(x - 1, y), Dx2 = Img_1_1.pixel(x + 1, y);
				double Dy1 = Img_1_1.pixel(x, y - 1), Dy2 = Img_1_1.pixel(x, y + 1);
				double Dxy1 = Img_1_1.pixel(x + 1, y + 1), Dxy2 = Img_1_1.pixel(x - 1, y - 1), Dxy3 = Img_1_1.pixel(x - 1, y + 1), Dxy4 = Img_1_1.pixel(x + 1, y - 1);
				double Do = Img_1_1.pixel(x, y);
				QRgb Do2 = Img_1_1.pixel(x, y);
				double Dxx = Dx1 + Dx2 - 2 * Do;

				double Dyy = Dy1 + Dy2 - 2 * Do;
				double Dxy = (Dxy1 + Dxy2 - Dxy3 - Dxy4) / 4;
				double Tr = Dxx + Dyy;
				double det = Dxx * Dyy - Dxy * Dxy;
				//if (Img_1_2.pixel(x + 1, y) > Img_1_2.pixel(x - 1, y) && Img_1_2.pixel(x, y - 1) > Img_1_2.pixel(x, y + 1)) {
				if (Tr * Tr / det > 10 && Do2 > 4279000000) {
					//if ((Img_1_2.pixel(x + 1, y) + Img_1_2.pixel(x - 1, y)) - 2 * Img_1_2.pixel(x, y) > 200 && (Img_1_2.pixel(x, y - 1) + Img_1_2.pixel(x, y + 1)) - 2 * Img_1_2.pixel(x, y) > 200) {
					Img.setPixelColor(x + 1, y, redddd); //red spot.
					Img.setPixelColor(x, y + 1, redddd);
					Img.setPixelColor(x + 1, y + 1, redddd);
					Img.setPixelColor(x + 1, y - 1, redddd);
					Img.setPixelColor(x - 1, y + 1, redddd);
					Img.setPixelColor(x - 1, y, redddd);
					Img.setPixelColor(x, y - 1, redddd);
					Img.setPixelColor(x - 1, y - 1, redddd);
					Img.setPixelColor(x, y, redddd);
				}

			}

			else if (Img_1_1.pixel(x - 1, y) > Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x, y - 1) > Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x + 1, y) > Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x, y + 1) > Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x + 1, y + 1) > Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x - 1, y - 1) > Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x - 1, y + 1) > Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x + 1, y - 1) > Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x, y) > Img_1_2.pixel(x, y) &&

				Img_1_3.pixel(x, y) > Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x, y - 1) > Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x + 1, y) > Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x, y + 1) > Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x + 1, y + 1) > Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x - 1, y - 1) > Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x - 1, y + 1) > Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x + 1, y - 1) > Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x, y) > Img_1_2.pixel(x, y) &&

				Img_1_2.pixel(x + 1, y) > Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x, y + 1) > Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x - 1, y) > Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x, y - 1) > Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x + 1, y + 1) > Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x - 1, y - 1) > Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x + 1, y - 1) > Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x - 1, y + 1) > Img_1_2.pixel(x, y)) {

				double Dx1 = Img_1_2.pixel(x - 1, y), Dx2 = Img_1_2.pixel(x + 1, y);
				double Dy1 = Img_1_2.pixel(x, y - 1), Dy2 = Img_1_2.pixel(x, y + 1);
				double Dxy1 = Img_1_2.pixel(x + 1, y + 1), Dxy2 = Img_1_2.pixel(x - 1, y - 1), Dxy3 = Img_1_2.pixel(x - 1, y + 1), Dxy4 = Img_1_2.pixel(x + 1, y - 1);
				double Do = Img_1_2.pixel(x, y);

				double Dxx = Dx1 + Dx2 - 2 * Do;

				double Dyy = Dy1 + Dy2 - 2 * Do;
				double Dxy = (Dxy1 + Dxy2 - Dxy3 - Dxy4) / 4;

				QRgb Do2 = Img_1_2.pixel(x, y);
				double Tr = Dxx + Dyy;
				double det = Dxx * Dyy - Dxy * Dxy;
				//if (Img_1_2.pixel(x + 1, y) > Img_1_2.pixel(x - 1, y) && Img_1_2.pixel(x, y - 1) > Img_1_2.pixel(x, y + 1)) {
				if (Tr * Tr / det > 10 && Do2 > 4279000000) {
					Img.setPixelColor(x + 1, y, redddd); //red spot.
					Img.setPixelColor(x, y + 1, redddd);
					Img.setPixelColor(x + 1, y + 1, redddd);
					Img.setPixelColor(x + 1, y - 1, redddd);
					Img.setPixelColor(x - 1, y + 1, redddd);
					Img.setPixelColor(x - 1, y, redddd);
					Img.setPixelColor(x, y - 1, redddd);
					Img.setPixelColor(x - 1, y - 1, redddd);
					Img.setPixelColor(x, y, redddd);
				}

			}
			else if (Img_1_1.pixel(x - 1, y) < Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x, y - 1) < Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x + 1, y) < Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x, y + 1) < Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x + 1, y + 1) < Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x - 1, y - 1) < Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x - 1, y + 1) < Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x + 1, y - 1) < Img_1_2.pixel(x, y) &&
				Img_1_1.pixel(x, y) < Img_1_2.pixel(x, y) &&

				Img_1_3.pixel(x, y) < Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x, y - 1) < Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x + 1, y) < Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x, y + 1) < Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x + 1, y + 1) < Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x - 1, y - 1) < Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x - 1, y + 1) < Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x + 1, y - 1) < Img_1_2.pixel(x, y) &&
				Img_1_3.pixel(x, y) < Img_1_2.pixel(x, y) &&

				Img_1_2.pixel(x + 1, y) < Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x, y + 1) < Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x - 1, y) < Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x, y - 1) < Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x + 1, y + 1) < Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x - 1, y - 1) < Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x + 1, y - 1) < Img_1_2.pixel(x, y) &&
				Img_1_2.pixel(x - 1, y + 1) < Img_1_2.pixel(x, y)) {

				double Dx1 = Img_1_2.pixel(x - 1, y), Dx2 = Img_1_2.pixel(x + 1, y);
				double Dy1 = Img_1_2.pixel(x, y - 1), Dy2 = Img_1_2.pixel(x, y + 1);
				double Dxy1 = Img_1_2.pixel(x + 1, y + 1), Dxy2 = Img_1_2.pixel(x - 1, y - 1), Dxy3 = Img_1_2.pixel(x - 1, y + 1), Dxy4 = Img_1_2.pixel(x + 1, y - 1);
				double Do = Img_1_2.pixel(x, y);

				QRgb Do2 = Img_1_2.pixel(x, y);
				double Dxx = Dx1 + Dx2 - 2 * Do;

				double Dyy = Dy1 + Dy2 - 2 * Do;
				double Dxy = (Dxy1 + Dxy2 - Dxy3 - Dxy4) / 4;

				double Tr = Dxx + Dyy;
				double det = Dxx * Dyy - Dxy * Dxy;
				//if (Img_1_2.pixel(x + 1, y) > Img_1_2.pixel(x - 1, y) && Img_1_2.pixel(x, y - 1) > Img_1_2.pixel(x, y + 1)) {
				if (Tr * Tr / det > 10 && Do2 > 4279000000) {

					Img.setPixelColor(x + 1, y, redddd); //red spot.
					Img.setPixelColor(x, y + 1, redddd);
					Img.setPixelColor(x + 1, y + 1, redddd);
					Img.setPixelColor(x + 1, y - 1, redddd);
					Img.setPixelColor(x - 1, y + 1, redddd);
					Img.setPixelColor(x - 1, y, redddd);
					Img.setPixelColor(x, y - 1, redddd);
					Img.setPixelColor(x - 1, y - 1, redddd);
					Img.setPixelColor(x, y, redddd);
				}

			}



			else if (Img.pixel(x - 1, y) < Img_1_1.pixel(x, y) &&
				Img.pixel(x, y - 1) < Img_1_1.pixel(x, y) &&
				Img.pixel(x + 1, y) < Img_1_1.pixel(x, y) &&
				Img.pixel(x, y + 1) < Img_1_1.pixel(x, y) &&
				Img.pixel(x + 1, y + 1) < Img_1_1.pixel(x, y) &&
				Img.pixel(x - 1, y - 1) < Img_1_1.pixel(x, y) &&
				Img.pixel(x - 1, y + 1) < Img_1_1.pixel(x, y) &&
				Img.pixel(x + 1, y - 1) < Img_1_1.pixel(x, y) &&
				Img.pixel(x, y) < Img_1_1.pixel(x, y) &&

				Img_1_2.pixel(x, y) < Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x, y - 1) < Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x + 1, y) < Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x, y + 1) < Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x + 1, y + 1) < Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x - 1, y - 1) < Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x - 1, y + 1) < Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x + 1, y - 1) < Img_1_1.pixel(x, y) &&
				Img_1_2.pixel(x, y) < Img_1_1.pixel(x, y) &&

				Img_1_1.pixel(x + 1, y) < Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x, y + 1) < Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x - 1, y) < Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x, y - 1) < Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x + 1, y + 1) < Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x - 1, y - 1) < Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x + 1, y - 1) < Img_1_1.pixel(x, y) &&
				Img_1_1.pixel(x - 1, y + 1) < Img_1_1.pixel(x, y)) {

				double Dx1 = Img_1_1.pixel(x - 1, y), Dx2 = Img_1_1.pixel(x + 1, y);
				double Dy1 = Img_1_1.pixel(x, y - 1), Dy2 = Img_1_1.pixel(x, y + 1);
				double Dxy1 = Img_1_1.pixel(x + 1, y + 1), Dxy2 = Img_1_1.pixel(x - 1, y - 1), Dxy3 = Img_1_1.pixel(x - 1, y + 1), Dxy4 = Img_1_1.pixel(x + 1, y - 1);
				double Do = Img_1_1.pixel(x, y);

				QRgb Do2 = Img_1_1.pixel(x, y);
				double Dxx = Dx1 + Dx2 - 2 * Do;

				double Dyy = Dy1 + Dy2 - 2 * Do;
				double Dxy = (Dxy1 + Dxy2 - Dxy3 - Dxy4) / 4;

				double Tr = Dxx + Dyy;
				double det = Dxx * Dyy - Dxy * Dxy;
				//if (Img_1_2.pixel(x + 1, y) > Img_1_2.pixel(x - 1, y) && Img_1_2.pixel(x, y - 1) > Img_1_2.pixel(x, y + 1)) {
				if (Tr * Tr / det > 10 && Do2 > 4279000000) {
					Img.setPixelColor(x + 1, y, redddd); //red spot.
					Img.setPixelColor(x, y + 1, redddd);
					Img.setPixelColor(x + 1, y + 1, redddd);
					Img.setPixelColor(x + 1, y - 1, redddd);
					Img.setPixelColor(x - 1, y + 1, redddd);
					Img.setPixelColor(x - 1, y, redddd);
					Img.setPixelColor(x, y - 1, redddd);
					Img.setPixelColor(x - 1, y - 1, redddd);
					Img.setPixelColor(x, y, redddd);
				}



			}
		}
	}

	width = Img_2_0.width();
	height = Img_2_0.height();

	for (int x = 1; x < width - 1; x++) {
		for (int y = 1; y < height - 1; y++) {



			if (Img_2_0.pixel(x - 1, y) > Img_2_1.pixel(x, y) &&
				Img_2_0.pixel(x, y - 1) > Img_2_1.pixel(x, y) &&
				Img_2_0.pixel(x + 1, y) > Img_2_1.pixel(x, y) &&
				Img_2_0.pixel(x, y + 1) > Img_2_1.pixel(x, y) &&
				Img_2_0.pixel(x + 1, y + 1) > Img_2_1.pixel(x, y) &&
				Img_2_0.pixel(x - 1, y - 1) > Img_2_1.pixel(x, y) &&
				Img_2_0.pixel(x - 1, y + 1) > Img_2_1.pixel(x, y) &&
				Img_2_0.pixel(x + 1, y - 1) > Img_2_1.pixel(x, y) &&
				Img_2_0.pixel(x, y) > Img_2_1.pixel(x, y) &&

				Img_2_2.pixel(x, y) > Img_2_1.pixel(x, y) &&
				Img_2_2.pixel(x, y - 1) > Img_2_1.pixel(x, y) &&
				Img_2_2.pixel(x + 1, y) > Img_2_1.pixel(x, y) &&
				Img_2_2.pixel(x, y + 1) > Img_2_1.pixel(x, y) &&
				Img_2_2.pixel(x + 1, y + 1) > Img_2_1.pixel(x, y) &&
				Img_2_2.pixel(x - 1, y - 1) > Img_2_1.pixel(x, y) &&
				Img_2_2.pixel(x - 1, y + 1) > Img_2_1.pixel(x, y) &&
				Img_2_2.pixel(x + 1, y - 1) > Img_2_1.pixel(x, y) &&
				Img_2_2.pixel(x, y) > Img_2_1.pixel(x, y) &&

				Img_2_1.pixel(x + 1, y) > Img_2_1.pixel(x, y) &&
				Img_2_1.pixel(x, y + 1) > Img_2_1.pixel(x, y) &&
				Img_2_1.pixel(x - 1, y) > Img_2_1.pixel(x, y) &&
				Img_2_1.pixel(x, y - 1) > Img_2_1.pixel(x, y) &&
				Img_2_1.pixel(x + 1, y + 1) > Img_2_1.pixel(x, y) &&
				Img_2_1.pixel(x - 1, y - 1) > Img_2_1.pixel(x, y) &&
				Img_2_1.pixel(x + 1, y - 1) > Img_2_1.pixel(x, y) &&
				Img_2_1.pixel(x - 1, y + 1) > Img_2_1.pixel(x, y)

				) {
				double Dx1 = Img_2_1.pixel(x - 1, y), Dx2 = Img_2_1.pixel(x + 1, y);
				double Dy1 = Img_2_1.pixel(x, y - 1), Dy2 = Img_2_1.pixel(x, y + 1);
				double Dxy1 = Img_2_1.pixel(x + 1, y + 1), Dxy2 = Img_2_1.pixel(x - 1, y - 1), Dxy3 = Img_2_1.pixel(x - 1, y + 1), Dxy4 = Img_2_1.pixel(x + 1, y - 1);
				double Do = Img_2_1.pixel(x, y);
				QRgb Do2 = Img_2_1.pixel(x, y);
				double Dxx = Dx1 + Dx2 - 2 * Do;

				double Dyy = Dy1 + Dy2 - 2 * Do;
				double Dxy = (Dxy1 + Dxy2 - Dxy3 - Dxy4) / 4;
				double Tr = Dxx + Dyy;
				double det = Dxx * Dyy - Dxy * Dxy;
				//if (Tr * Tr / det > 10 && Do2 > 4279000000) {
				//	//if ((Img_2_2.pixel(x + 1, y) + Img_2_2.pixel(x - 1, y)) - 2 * Img_2_2.pixel(x, y) > 200 && (Img_2_2.pixel(x, y - 1) + Img_2_2.pixel(x, y + 1)) - 2 * Img_2_2.pixel(x, y) > 200) {
				//	Img.setPixelColor(x+1, y, redddd); //red spot.
				//	Img.setPixelColor(x, y + 1, redddd);
				//	Img.setPixelColor(x +1, y + 1, redddd);
				//	Img.setPixelColor(x + 1, y - 1, redddd);
				//	Img.setPixelColor(x - 1, y + 1, redddd);
				//	Img.setPixelColor(x - 1, y, redddd);
				//	Img.setPixelColor(x, y - 1, redddd);
				//	Img.setPixelColor(x - 1, y - 1, redddd);
				//	Img.setPixelColor(x, y, redddd);
				//}

			}

			else if (Img_2_1.pixel(x - 1, y) > Img_2_2.pixel(x, y) &&
				Img_2_1.pixel(x, y - 1) > Img_2_2.pixel(x, y) &&
				Img_2_1.pixel(x + 1, y) > Img_2_2.pixel(x, y) &&
				Img_2_1.pixel(x, y + 1) > Img_2_2.pixel(x, y) &&
				Img_2_1.pixel(x + 1, y + 1) > Img_2_2.pixel(x, y) &&
				Img_2_1.pixel(x - 1, y - 1) > Img_2_2.pixel(x, y) &&
				Img_2_1.pixel(x - 1, y + 1) > Img_2_2.pixel(x, y) &&
				Img_2_1.pixel(x + 1, y - 1) > Img_2_2.pixel(x, y) &&
				Img_2_1.pixel(x, y) > Img_2_2.pixel(x, y) &&

				Img_2_3.pixel(x, y) > Img_2_2.pixel(x, y) &&
				Img_2_3.pixel(x, y - 1) > Img_2_2.pixel(x, y) &&
				Img_2_3.pixel(x + 1, y) > Img_2_2.pixel(x, y) &&
				Img_2_3.pixel(x, y + 1) > Img_2_2.pixel(x, y) &&
				Img_2_3.pixel(x + 1, y + 1) > Img_2_2.pixel(x, y) &&
				Img_2_3.pixel(x - 1, y - 1) > Img_2_2.pixel(x, y) &&
				Img_2_3.pixel(x - 1, y + 1) > Img_2_2.pixel(x, y) &&
				Img_2_3.pixel(x + 1, y - 1) > Img_2_2.pixel(x, y) &&
				Img_2_3.pixel(x, y) > Img_2_2.pixel(x, y) &&

				Img_2_2.pixel(x + 1, y) > Img_2_2.pixel(x, y) &&
				Img_2_2.pixel(x, y + 1) > Img_2_2.pixel(x, y) &&
				Img_2_2.pixel(x - 1, y) > Img_2_2.pixel(x, y) &&
				Img_2_2.pixel(x, y - 1) > Img_2_2.pixel(x, y) &&
				Img_2_2.pixel(x + 1, y + 1) > Img_2_2.pixel(x, y) &&
				Img_2_2.pixel(x - 1, y - 1) > Img_2_2.pixel(x, y) &&
				Img_2_2.pixel(x + 1, y - 1) > Img_2_2.pixel(x, y) &&
				Img_2_2.pixel(x - 1, y + 1) > Img_2_2.pixel(x, y)) {

				double Dx1 = Img_2_2.pixel(x - 1, y), Dx2 = Img_2_2.pixel(x + 1, y);
				double Dy1 = Img_2_2.pixel(x, y - 1), Dy2 = Img_2_2.pixel(x, y + 1);
				double Dxy1 = Img_2_2.pixel(x + 1, y + 1), Dxy2 = Img_2_2.pixel(x - 1, y - 1), Dxy3 = Img_2_2.pixel(x - 1, y + 1), Dxy4 = Img_2_2.pixel(x + 1, y - 1);
				double Do = Img_2_2.pixel(x, y);

				double Dxx = Dx1 + Dx2 - 2 * Do;

				double Dyy = Dy1 + Dy2 - 2 * Do;
				double Dxy = (Dxy1 + Dxy2 - Dxy3 - Dxy4) / 4;

				QRgb Do2 = Img_2_2.pixel(x, y);
				double Tr = Dxx + Dyy;
				double det = Dxx * Dyy - Dxy * Dxy;
				if (Img_2_2.pixel(x + 1, y) > Img_2_2.pixel(x - 1, y) && Img_2_2.pixel(x, y - 1) > Img_2_2.pixel(x, y + 1)) {
					if (Tr * Tr / det > 10 && Do2 > 4279000000) {
						Img.setPixelColor(x / 2 + 1, y / 2, redddd); //red spot.
						Img.setPixelColor(x / 2, y / 2 + 1, redddd);
						Img.setPixelColor(x / 2 + 1, y / 2 + 1, redddd);
						Img.setPixelColor(x / 2 + 1, y / 2 - 1, redddd);
						Img.setPixelColor(x / 2 - 1, y / 2 + 1, redddd);
						Img.setPixelColor(x / 2 - 1, y / 2, redddd);
						Img.setPixelColor(x / 2, y / 2 - 1, redddd);
						Img.setPixelColor(x / 2 - 1, y / 2 - 1, redddd);
						Img.setPixelColor(x / 2, y / 2, redddd);
					}

				}
				else if (Img_2_1.pixel(x - 1, y) < Img_2_2.pixel(x, y) &&
					Img_2_1.pixel(x, y - 1) < Img_2_2.pixel(x, y) &&
					Img_2_1.pixel(x + 1, y) < Img_2_2.pixel(x, y) &&
					Img_2_1.pixel(x, y + 1) < Img_2_2.pixel(x, y) &&
					Img_2_1.pixel(x + 1, y + 1) < Img_2_2.pixel(x, y) &&
					Img_2_1.pixel(x - 1, y - 1) < Img_2_2.pixel(x, y) &&
					Img_2_1.pixel(x - 1, y + 1) < Img_2_2.pixel(x, y) &&
					Img_2_1.pixel(x + 1, y - 1) < Img_2_2.pixel(x, y) &&
					Img_2_1.pixel(x, y) < Img_2_2.pixel(x, y) &&

					Img_2_3.pixel(x, y) < Img_2_2.pixel(x, y) &&
					Img_2_3.pixel(x, y - 1) < Img_2_2.pixel(x, y) &&
					Img_2_3.pixel(x + 1, y) < Img_2_2.pixel(x, y) &&
					Img_2_3.pixel(x, y + 1) < Img_2_2.pixel(x, y) &&
					Img_2_3.pixel(x + 1, y + 1) < Img_2_2.pixel(x, y) &&
					Img_2_3.pixel(x - 1, y - 1) < Img_2_2.pixel(x, y) &&
					Img_2_3.pixel(x - 1, y + 1) < Img_2_2.pixel(x, y) &&
					Img_2_3.pixel(x + 1, y - 1) < Img_2_2.pixel(x, y) &&
					Img_2_3.pixel(x, y) < Img_2_2.pixel(x, y) &&

					Img_2_2.pixel(x + 1, y) < Img_2_2.pixel(x, y) &&
					Img_2_2.pixel(x, y + 1) < Img_2_2.pixel(x, y) &&
					Img_2_2.pixel(x - 1, y) < Img_2_2.pixel(x, y) &&
					Img_2_2.pixel(x, y - 1) < Img_2_2.pixel(x, y) &&
					Img_2_2.pixel(x + 1, y + 1) < Img_2_2.pixel(x, y) &&
					Img_2_2.pixel(x - 1, y - 1) < Img_2_2.pixel(x, y) &&
					Img_2_2.pixel(x + 1, y - 1) < Img_2_2.pixel(x, y) &&
					Img_2_2.pixel(x - 1, y + 1) < Img_2_2.pixel(x, y)) {

					double Dx1 = Img_2_2.pixel(x - 1, y), Dx2 = Img_2_2.pixel(x + 1, y);
					double Dy1 = Img_2_2.pixel(x, y - 1), Dy2 = Img_2_2.pixel(x, y + 1);
					double Dxy1 = Img_2_2.pixel(x + 1, y + 1), Dxy2 = Img_2_2.pixel(x - 1, y - 1), Dxy3 = Img_2_2.pixel(x - 1, y + 1), Dxy4 = Img_2_2.pixel(x + 1, y - 1);
					double Do = Img_2_2.pixel(x, y);

					QRgb Do2 = Img_2_2.pixel(x, y);
					double Dxx = Dx1 + Dx2 - 2 * Do;

					double Dyy = Dy1 + Dy2 - 2 * Do;
					double Dxy = (Dxy1 + Dxy2 - Dxy3 - Dxy4) / 4;

					double Tr = Dxx + Dyy;
					double det = Dxx * Dyy - Dxy * Dxy;
					// (Img_2_2.pixel(x + 1, y) > Img_2_2.pixel(x - 1, y) && Img_2_2.pixel(x, y - 1) > Img_2_2.pixel(x, y + 1)) {
					if (Tr * Tr / det > 10 && Do2 > 4279000000) {

						Img.setPixelColor(x / 2 + 1, y / 2, redddd); //red spot.
						Img.setPixelColor(x / 2, y / 2 + 1, redddd);
						Img.setPixelColor(x / 2 + 1, y / 2 + 1, redddd);
						Img.setPixelColor(x / 2 + 1, y / 2 - 1, redddd);
						Img.setPixelColor(x / 2 - 1, y / 2 + 1, redddd);
						Img.setPixelColor(x / 2 - 1, y / 2, redddd);
						Img.setPixelColor(x / 2, y / 2 - 1, redddd);
						Img.setPixelColor(x / 2 - 1, y / 2 - 1, redddd);
						Img.setPixelColor(x / 2, y / 2, redddd);
					}

				}



				else if (Img_2_0.pixel(x - 1, y) < Img_2_1.pixel(x, y) &&
					Img_2_0.pixel(x, y - 1) < Img_2_1.pixel(x, y) &&
					Img_2_0.pixel(x + 1, y) < Img_2_1.pixel(x, y) &&
					Img_2_0.pixel(x, y + 1) < Img_2_1.pixel(x, y) &&
					Img_2_0.pixel(x + 1, y + 1) < Img_2_1.pixel(x, y) &&
					Img_2_0.pixel(x - 1, y - 1) < Img_2_1.pixel(x, y) &&
					Img_2_0.pixel(x - 1, y + 1) < Img_2_1.pixel(x, y) &&
					Img_2_0.pixel(x + 1, y - 1) < Img_2_1.pixel(x, y) &&
					Img_2_0.pixel(x, y) < Img_2_1.pixel(x, y) &&

					Img_2_2.pixel(x, y) < Img_2_1.pixel(x, y) &&
					Img_2_2.pixel(x, y - 1) < Img_2_1.pixel(x, y) &&
					Img_2_2.pixel(x + 1, y) < Img_2_1.pixel(x, y) &&
					Img_2_2.pixel(x, y + 1) < Img_2_1.pixel(x, y) &&
					Img_2_2.pixel(x + 1, y + 1) < Img_2_1.pixel(x, y) &&
					Img_2_2.pixel(x - 1, y - 1) < Img_2_1.pixel(x, y) &&
					Img_2_2.pixel(x - 1, y + 1) < Img_2_1.pixel(x, y) &&
					Img_2_2.pixel(x + 1, y - 1) < Img_2_1.pixel(x, y) &&
					Img_2_2.pixel(x, y) < Img_2_1.pixel(x, y) &&

					Img_2_1.pixel(x + 1, y) < Img_2_1.pixel(x, y) &&
					Img_2_1.pixel(x, y + 1) < Img_2_1.pixel(x, y) &&
					Img_2_1.pixel(x - 1, y) < Img_2_1.pixel(x, y) &&
					Img_2_1.pixel(x, y - 1) < Img_2_1.pixel(x, y) &&
					Img_2_1.pixel(x + 1, y + 1) < Img_2_1.pixel(x, y) &&
					Img_2_1.pixel(x - 1, y - 1) < Img_2_1.pixel(x, y) &&
					Img_2_1.pixel(x + 1, y - 1) < Img_2_1.pixel(x, y) &&
					Img_2_1.pixel(x - 1, y + 1) < Img_2_1.pixel(x, y)) {

					double Dx1 = Img_2_1.pixel(x - 1, y), Dx2 = Img_2_1.pixel(x + 1, y);
					double Dy1 = Img_2_1.pixel(x, y - 1), Dy2 = Img_2_1.pixel(x, y + 1);
					double Dxy1 = Img_2_1.pixel(x + 1, y + 1), Dxy2 = Img_2_1.pixel(x - 1, y - 1), Dxy3 = Img_2_1.pixel(x - 1, y + 1), Dxy4 = Img_2_1.pixel(x + 1, y - 1);
					double Do = Img_2_1.pixel(x, y);

					QRgb Do2 = Img_2_1.pixel(x, y);
					double Dxx = Dx1 + Dx2 - 2 * Do;

					double Dyy = Dy1 + Dy2 - 2 * Do;
					double Dxy = (Dxy1 + Dxy2 - Dxy3 - Dxy4) / 4;

					double Tr = Dxx + Dyy;
					double det = Dxx * Dyy - Dxy * Dxy;
					//if (Tr * Tr / det > 10 && Do2 > 4279000000) {
					//	//Img.setPixelColor(x / 2 + 1, y / 2, redddd); //red spot.
					//	//Img.setPixelColor(x / 2, y / 2 + 1, redddd);
					//	//Img.setPixelColor(x / 2 + 1, y / 2 + 1, redddd);
					//	//Img.setPixelColor(x / 2 + 1, y / 2 - 1, redddd);
					//	//Img.setPixelColor(x / 2 - 1, y / 2 + 1, redddd);
					//	//Img.setPixelColor(x / 2 - 1, y / 2, redddd);
					//	//Img.setPixelColor(x / 2, y / 2 - 1, redddd);
					//	//Img.setPixelColor(x / 2 - 1, y / 2 - 1, redddd);
					//	//Img.setPixelColor(x / 2, y / 2, redddd);
					//	Img.setPixelColor(x + 1, y, redddd); //red spot.
					//	Img.setPixelColor(x, y + 1, redddd);
					//	Img.setPixelColor(x + 1, y + 1, redddd);
					//	Img.setPixelColor(x + 1, y - 1, redddd);
					//	Img.setPixelColor(x - 1, y + 1, redddd);
					//	Img.setPixelColor(x - 1, y, redddd);
					//	Img.setPixelColor(x, y - 1, redddd);
					//	Img.setPixelColor(x - 1, y - 1, redddd);
					//	Img.setPixelColor(x, y, redddd);
					//}



				}
			}
		}


		buffer = QPixmap::fromImage(Img);   //save in buffer
		buffer = buffer.scaled(Img.width(), Img.height());

		ui.label->setPixmap(buffer);

		ui.label->setScaledContents(true);


		//buffer = QPixmap::fromImage(Img_1_1);   //save in buffer
		//buffer = buffer.scaled(Img_1_1.width(), Img_1_1.height());

		//ui.label_2->setPixmap(buffer);

		//ui.label_2->setScaledContents(true);


		//buffer = QPixmap::fromImage(Img_1_2);   //save in buffer
		//buffer = buffer.scaled(Img_1_2.width(), Img_1_2.height());

		//ui.label_3->setPixmap(buffer);

		//ui.label_3->setScaledContents(true);


		//buffer = QPixmap::fromImage(Img_1_3);   //save in buffer
		//buffer = buffer.scaled(Img_1_3.width(), Img_1_3.height());

		//ui.label_4->setPixmap(buffer);

		//ui.label_4->setScaledContents(true);



		//buffer = QPixmap::fromImage(Img_1_4);   //save in buffer
		//buffer = buffer.scaled(Img_1_4.width(), Img_1_4.height());

		//ui.label_5->setPixmap(buffer);

		//ui.label_5->setScaledContents(true);



	}
}