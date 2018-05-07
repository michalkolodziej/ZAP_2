#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "mapa.h"
#include "graf.h"
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
	cout << "Gib me name: \n";
	cin >> nazwa;

	Mat image;	//read image
	nazwa = "images/" + nazwa;
	image = imread(nazwa, CV_LOAD_IMAGE_COLOR);

	if (!image.data)                              // Check for invalid input
	{
		cout << "Could not open or find the image." << endl;
		waitKey(0);
		return 0;
	}
	showimg("Deafult", image);

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
	F_f(mapa, w, k);

	int wi = 0;
	int ko = 0;
	int suma = mapa[0][0].f;

	while (1)
	{
		if (wi == w-1 && ko == k-1) break;
		if (wi == w - 1)
		{
			suma = suma + mapa[wi][ko + 1].f;
			mapa[wi][ko].kolejka = 0;
			ko++;
		}
		else if (ko == k - 1)
		{
			suma = suma + mapa[wi + 1][ko].f;
			mapa[wi][ko].kolejka = 0;
			wi++;

		}
		else
		{
			suma = suma + min(mapa[wi][ko + 1].f, mapa[wi + 1][ko].f);
			//cout<<" "<<tablica[w][k+1].f<<" "<<tablica[w+1][k].f<<endl;
			if (mapa[wi][ko + 1].f < mapa[wi + 1][ko].f)
			{
				mapa[wi][ko].kolejka = 0;
				ko++;
				//cout<<"k++"<<endl;
			}
			else if (mapa[wi][ko + 1].f >= mapa[wi + 1][ko].f)
			{
				mapa[wi][ko].kolejka = 0;
				wi++;
				// cout<<"w++"<<endl;
			}
		}
		if(wi == w - 1)
			if (ko == k - 1)
			{
				mapa[wi][ko].kolejka = 0;
				break;
			}
	}
	drukuj(mapa, w, k);
	
	int *array_img = new int[w*k];
	cout << "ECHOOOO";
	int pomoc = 0;
	for(int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++) {
			array_img[pomoc] = mapa[i][j].kolejka;
			pomoc++;
		}
	}

	//Mat A = (Mat_<int>(w, k) << array_img );
	//Mat A(w, k, CV_8UC3, array_img);
	//imwrite("wyjscie.png", A);
	cout << A;

	//niby wszystko fajnie tylko te jebane przerabianie macierzy na obrazek mnie wkurwia
	//no i mog³oby byæ bardziej lokalne szukanie drogi


	showimg(nazwa, gray_image);
	waitKey(0);
	//showimg("KONIEC", A);
	
	

	for (int i = 0; i < w; i++) {
		delete mapa[i];	
	}
	delete mapa;
	delete array_img;
	return 0;
}