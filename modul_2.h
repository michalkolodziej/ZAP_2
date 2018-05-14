#ifndef MODUL_2_H
#define MODUL_2_H
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <fstream>
using namespace cv;
using  namespace std;
struct macierz;
struct punkt;
struct lista;
void **F_g_h(macierz **&tablica, int w, int k);//funkcja liczaca wartosci g i h dla calej macierzy
void **F_f(macierz **&tablica, int w, int k); //funkcja liczaca wartosc f dla ca³ej macierzy

#endif // MODUL_2_H
