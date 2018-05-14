#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "mapa.h"
#include "graf1.h"
#include "modul_2.h"


using namespace cv;
using namespace std;

struct macierz
{
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



int a;
int main( int argc, char** argv )
{
	string nazwa;
	cout << "Podaj nazwe pliku: \n";
	cin >> nazwa;

	Mat image;	//read image
	nazwa = "images/" + nazwa;
	image = imread(nazwa, CV_LOAD_IMAGE_COLOR);

if (!image.data)                              // Check for invalid input
{
	cout << "Could not open or find the image." << endl;
	cin >> nazwa;
	waitKey(0);
	return 0;
}
showimg("Deafult", image);
string echo = "ECHO ";


Mat gray_image; //change color to gray scale
cvtColor(image, gray_image, CV_BGR2GRAY);

macierz **mapa = new macierz*[gray_image.rows];
for (int i = 0; i < gray_image.rows; i++)
{
	mapa[i] = new macierz[gray_image.cols];
}

imgtoarray(gray_image, mapa);

wypelnij(mapa, gray_image.rows, gray_image.cols);

punkt obecny, poczatek, koniec;
ustawpunkt(poczatek, koniec);

int w = gray_image.rows;
int k = gray_image.cols;

obecny.x = 0;
obecny.y = 0;

liczG(poczatek, mapa, w, k);
F_g_h(mapa, w, k);
szukaj(mapa, w, k);
//F_f(mapa, w, k);

	//drukuj(mapa, w, k);

	unsigned char *array_img = new unsigned char[w*k];

	int pomoc = 0;
	for(int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++) {
			array_img[pomoc] = (unsigned char)mapa[i][j].kolejka;
			pomoc++;
		}
	}
	Mat array_img_cv = Mat(w, k, CV_8UC1, array_img);

	array_img_cv = 255 - array_img_cv;
	imshow("array", array_img_cv);

	//no i mog³oby byæ bardziej lokalne szukanie drogi
	imwrite("wyjscie.png", array_img_cv);

	showimg(nazwa, gray_image);
	waitKey();
	//showimg("KONIEC", A);
	
	

	for (int i = 0; i < w; i++) {
		delete mapa[i];	
	}
	delete mapa;
	delete array_img;
	return 0;
}