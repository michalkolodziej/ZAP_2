/**
 * \file mapa.h
 * \brief Plik nagłówkowy modułu \a mapa.
 *
 * Moduł \a mapa zawiera funkcje obsługujące algorytm A*.
 *
 * \see mapa.cpp
 */
#pragma once
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QApplication>
struct macierz;
using namespace cv;
using namespace std;

/** \brief Przekształcenie obrazu w macierz liczb
 *
 * Funkjca przekształca obraz podany za pomocą typu Mat na macierz liczb.
 * \param image obraz do przekształcenia
 * \param tablica struktura mapy
 */
void imgtoarray(Mat image, macierz **&tablica);

/** \brief Pokaż obraz
 *
 * Funkjca wypełnia wyświetla okno z obrazem podanym za pomocą typu Mat
 * \param nazwa nazwa okna
 * \param img obraz
 */
void showimg(string nazwa, Mat img);


/** \brief Funkcja szukająca najkrótszej drogi na mapie
 *
 * Funkcja ma działanie zlbiżone do działania algorytmu A*.
 * Poszukuje najkrótszej drogi.
 * \param mapa mapa, która ma zostać przeszukana.
 * \param w ilość wierszy mapy
 * \param k ilość kolumn mapy
 * \param ui przekazanie okna do funkcji
 */
void szukaj(macierz **&mapa, int w, int k, Ui::MainWindow *ui);
