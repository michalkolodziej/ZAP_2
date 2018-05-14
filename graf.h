#ifndef GRAF_H
#define GRAF_H
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <fstream>
using  namespace std;
struct macierz;
struct punkt;
struct lista;
void **wypelnij(macierz **&tablica, int w, int k);
void **drukuj(macierz **&tablica, int w, int k);
void ustawpunkt(punkt &poczatek, punkt &koniec);
int liczF(punkt centrum, macierz **&tablica, int w, int k);
int liczG(punkt poczatek, macierz **&tablica, int w, int k);
punkt znajdznajmniejszyF(lista *& ciag, macierz **&tablica, int w, int k);
#endif // GRAF_H
