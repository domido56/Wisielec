#include <iostream>
#include "wisielec_funkcje.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <string>
#include <ctype.h>

using namespace std;


int wczytywanie_int(int pom, int pom1) // kontrola poprawnosci danych
{
	int x = 0;
	cout << "->";
	while (scanf_s("%d", &x) != 1 || x>pom1 || x<pom || getchar() != '\n')
	{
		printf("Bledne dane, popraw:\t");
		while (getchar() != '\n')
			;
	}
	return x;
}

char wczytywanie_char() // kontrola poprawnosci danych
{
	char k = 0;
	cout << "->";
	while (scanf_s("%c", &k) != 1 || !isalpha(k) || getchar() != '\n')
	{
		printf("Bledne dane, popraw:\t");
		while (getchar() != '\n')
			;
	}
	return k;
}

bool tylko_litery(const string& haslo) 
{
	for (char c : haslo) {
		if (!isalpha(c)) {
			return false;
		}
	}

	if (haslo.find(' ') !=string::npos) {
		return false;
	}

	return true;
}

string hasloStart(int dlugosc) 
{
	string odp(dlugosc, '_');
	return odp;
}

void odczyt(const string& nazwa_plik1) 
{
	ifstream plik1(nazwa_plik1);

	if (plik1.is_open()) {
		string wiersz;
		while (getline(plik1, wiersz)) 
		{
		    cout << wiersz << endl;
		}
		plik1.close();
	}
	else {
		cout << "Nie mozna otworzyc pliku." << endl;
	}
}
