/**
 * \file graf1.h
 * \brief Plik nagłówkowy modułu \a graf1.
 *
 * Moduł \a graf zawiera definicję funkcji obsługujących graf.
 *
 * \see graf1.cpp
 */
#pragma once
#ifndef GRAF_H
#define GRAF_H
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iostream>
#include <fstream>
using  namespace std;
using namespace cv;
/** \brief Struktura przetrzymująca mapę.
 *
 * Definicja pojedyńczego pola mapy.
 */
struct macierz {
    /// Koszt wejścia na pole.
    int waga;
    /// czynnik G algorytmu A* (algorytm heurestyczny).
    int g;
    /// Droga pomiędzy wierzchołkiem początkowym a danym.
    int h;
    /// Czynnik f będący sumą czynników g i h.
    int f = g + h;
    /// Czy dane pole zostało odwiedzone?
    int odwiedzony;
    /// Przetrzymuje elementy mapy do wyświetlenia.
    int kolejka;
};
/** \brief Struktura przetrzymująca punkt w układzie współrzędnych
 *
 * Definicja punktu.
 */
struct punkt
{
    /// Współrzędne punktu.
    int x, y;
};

/** \brief Funkcja wypełniająca tablicę z mapą.
 *
 * Funkjca wypełnia określone pola mapy konkretnymi wartościami.
 * \param tablica struktura mapy
 * \param w ilość wierszy.
 * \param k ilość kolumn
 */
void **wypelnij(macierz **&tablica, int w, int k);

/** \brief Funkcja wypełniająca drukująca tablicę z mapą.
 *
 * Funkjca wypełnia określone pola mapy konkretnymi wartościami.
 * \param tablica struktura mapy
 * \param w ilość wierszy.
 * \param k ilość kolumn
 */
void **drukuj(macierz **&tablica, int w, int k);// drukuj(macierz **&tablica, int n)

/** \brief  Funkcja nadająca współrzędne punktów na punkt początkowy i końcowy.
 *
 * Funkcja ustawiająca wartości struktury punkt na początej i koniec
 * \param poczatek punkt poczatkowy.
 * \param koniec punkt końcowy.
 */
void ustawpunkt(punkt &poczatek, punkt &koniec);

/** \brief  Funkcja licząca parametr F
 *
 * Funkcja licząca parametr F - koszt dojścia na pole
 * \param centrum punkt dla którego jest liczony parametr F
 * \param tablica struktura w której jest przechowywana macierz.
 * \param w ilosc wierszy.
 * \param k ilosc kolumn
 */
int liczF(punkt centrum, macierz **&tablica, int w, int k);

/** \brief  Funkcja licząca parametr
 *
 * Funkcja licząca parametr G - koszt algorytmu heurestycznego
 * \param poczatek punkt do ktorego jest liczony parametr G
 * \param tablica struktura w której jest przechowywana macierz.
 * \param w ilosc wierszy.
 * \param k ilosc kolumn
 */
int liczG(punkt poczatek, macierz **&tablica, int w, int k);




 #endif // GRAF_H


