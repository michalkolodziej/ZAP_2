#ifndef MODUL_2_H
#define MODUL_2_H
#include <iostream>
#include <fstream>
using  namespace std;
struct macierz;
struct punkt;
struct lista;
void **F_g_h(macierz **&tablica, int w, int k);//funkcja liczaca wartosci g i h dla calej macierzy
void **F_f(macierz **&tablica, int w, int k); //funkcja liczaca wartosc f dla ca³ej macierzy

#endif // MODUL_2_H
