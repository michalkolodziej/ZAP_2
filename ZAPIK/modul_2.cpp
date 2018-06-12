#include "modul_2.h"
#include "graf1.h"

void F_g_h(macierz **&tablica, int w, int k) {
	punkt obecny;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < k; j++)
		{
			obecny.x = i;
			obecny.y = j;
			liczG(obecny, tablica, w, k);
			tablica[i][j].h = w - i + k - j;
			tablica[i][j].f = tablica[i][j].g + tablica[i][j].h;
		}
	}

}
void F_f(macierz**& tablica, int w, int k)
{
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < k; j++)
		{
			tablica[i][j].f = tablica[i][j].g + tablica[i][j].h;
		}
	}


}


