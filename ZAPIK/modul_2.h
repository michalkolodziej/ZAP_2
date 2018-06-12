/**
 * \file modul_2.h
 * \brief Plik nag?ówkowy modu?u \a modul2.
 *
 * Modu? \a mapa zawiera funkcje obs?uguj?ce pomocnicze w algorytmie A*.
 *
 * \see modul_2.cpp
 */
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

/** \brief Funkcja licz?ca warto?ci g i h
 *
 * funkcja liczaca wartosci g i h dla calej macierzy
 *
 *
 * \param tablica tablica, dla której warto?ci g i h maj? zosta? policzone
 * \param w ile wierszy mapy
 * \param k ile kolumn mapy
 */
void F_g_h(macierz **&tablica, int w, int k);//funkcja liczaca wartosci g i h dla calej macierzy

/** \brief Funkcja licz?ca warto?? f
 *
 * funkcja liczaca wartos? f dla calej macierzy
 *
 * \param tablica tablica, dla której warto?? parametru f ma zosta? policzona
 * \param w ile wierszy mapy
 * \param k ile kolumn mapy
 */
void F_f(macierz **&tablica, int w, int k); //funkcja liczaca wartosc f dla ca³ej macierzy

#endif // MODUL_2_H
