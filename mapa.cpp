#include "mapa.h"

using namespace cv;
using namespace std;

struct macierz {
	int waga;
	int g;
	int h;
	int f = g + h;
	int odwiedzony;
	int kolejka;
};

struct punkt
{
	int x, y;
};

struct lista
{
	punkt pkt;
	lista *nastepny;

};


void **imgtoarray(Mat image, macierz **&tablica)
{

	//Mat gray_image;
	//cvtColor(image, gray_image, CV_BGR2GRAY);

	//imwrite("Gray_Image.jpg", gray_image);

	//namedWindow("nazwa", CV_WINDOW_AUTOSIZE);
	//namedWindow("Gray image", CV_WINDOW_AUTOSIZE);
	Mat imgconv;
	image.convertTo(imgconv, CV_32S);

	if (imgconv.isContinuous()) {
		imgconv = imgconv.reshape(1, 1);
	}

	int *ptrarray = new int[imgconv.cols];

	for (int i = 0; i < imgconv.rows; ++i) {
		ptrarray = imgconv.ptr<int>(i);
	}
	//int **tablica = new int*[gray_image.rows];
	int k = 0;
	for (int i = 0; i < image.rows; i++)
	{
		//tablica[i] = new int[gray_image.cols];
		for (int j = 0; j < image.cols; j++)
		{
			tablica[i][j].waga = 255-ptrarray[k];
			//cout << tablica[i][j].waga << " ";
			k++;
		}
		//cout << endl;
	}

	return 0;

}

void showimg(string nazwa, Mat img)
{
	namedWindow(nazwa, CV_WINDOW_AUTOSIZE);
	imshow(nazwa, img);
}
