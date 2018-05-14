#include "graf.h"
struct macierz {
	int waga;
	int g;
	int h;
	int f = g + h;
	int odwiedzony;
	Mat kolejka;
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

void **wypelnij(macierz **&tablica, int w, int k) {

	
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < k; j++) {
			tablica[i][j].g = 0;
			tablica[i][j].odwiedzony = 0;
			tablica[i][j].f = 0;
			tablica[i][j].h = 0;
			tablica[i][j].kolejka = tablica[i][j].waga;
		}
	}
	tablica[0][0].odwiedzony = 1;
	return 0;
}

void **drukuj(macierz **&tablica, int w, int k) {
	ofstream G, H, F, TAB, DROGA;
	G.open("txt/G.txt");
	H.open("txt/H.txt");
	F.open("txt/F.txt");
	TAB.open("txt/TAB.txt");
	DROGA.open("txt/DROGA.txt");
	for (int i = 0; i < w; i++)
	{  // cout<<endl;
		for (int j = 0; j < k; j++)
		{
			//cout<<tablica[i][j].waga<<" ";
			G << tablica[i][j].g << " ";
			H << tablica[i][j].h << " ";
			F << tablica[i][j].f << " ";
			TAB << tablica[i][j].waga << " ";
			DROGA << tablica[i][j].kolejka << " ";
			//cout << tablica[i][j].kolejka;
		}
		G << endl;
		H << endl;
		F << endl;
		TAB << endl;
		DROGA << endl;
		//cout << endl;

	}
	return 0;

}

void ustawpunkt(punkt &poczatek, punkt &koniec)
{
	poczatek.x = 0;
	poczatek.y = 0;
	koniec.x = 9;
	koniec.y = 9;
}

int liczG(punkt poczatek, macierz**& tablica, int w, int k)
{
	int i = poczatek.x;
	int j = poczatek.y;

	if (i < w - 1)
	{
		//odwiedzony 1, nieodwiedzony -1
		if (tablica[i + 1][j].odwiedzony == 0) {
			tablica[i + 1][j].g = tablica[i][j].g + tablica[i + 1][j].waga + 1;
			tablica[i + 1][j].odwiedzony = 1;
		}
		else
		{
			if (tablica[i + 1][j].g > tablica[i][j].g + tablica[i + 1][j].waga + 1 && tablica[i + 1][j].g != 0) tablica[i + 1][j].g = tablica[i][j].g + tablica[i + 1][j].waga + 1;
		}
	}

	if (j < k - 1)
	{
		if (tablica[i][j + 1].odwiedzony == 0) {
			tablica[i][j + 1].g = tablica[i][j].g + tablica[i][j + 1].waga + 1;
			tablica[i][j + 1].odwiedzony = 1;
		}
		else
		{

			if (tablica[i][j + 1].g > tablica[i][j].g + tablica[i][j + 1].waga + 1 && tablica[i][j + 1].g != 0) tablica[i][j + 1].g = tablica[i][j].g + tablica[i][j + 1].waga + 1;
		}
	}
	if (i > 0)
	{
		if (tablica[i - 1][j].odwiedzony == 0) {
			tablica[i - 1][j].g = tablica[i][j].g + tablica[i - 1][j].waga + 1;
			tablica[i - 1][j].odwiedzony = 1;
		}
		else
		{

			if (tablica[i - 1][j].g > tablica[i][j].g + tablica[i - 1][j].waga + 1 && tablica[i - 1][j].g != 0) tablica[i - 1][j].g = tablica[i][j].g + tablica[i - 1][j].waga + 1;
		}
	}
	return 0;
}

int liczF(punkt centrum, macierz **&tablica, int w, int k)
{
	int i = centrum.x;
	int j = centrum.y;
	tablica[i][j].h = (k - j) + (w - i);
	centrum.x--;
	liczG(centrum, tablica, w,k);
	centrum.x++;
	tablica[i][j].f = tablica[i][j].h + tablica[i][j].g;
	return 0;
}

punkt znajdznajmniejszy(lista *ciag, macierz **&tablica, int w, int k)
{
	punkt obecny, minimalny;
	minimalny = ciag->pkt;
	int minimum = liczF(minimalny, tablica, w, k);
	while (ciag)
	{
		obecny = ciag->pkt;
		int nowy = liczF(obecny, tablica, w, k);
		if (nowy < minimum)
		{
			minimum = nowy;
			minimalny = obecny;
		}
		ciag = ciag->nastepny;
	}
	return minimalny;
}
