#include <iostream>
#include "wisielec_funkcje.h"
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
#include <cstring>
#include <ctype.h>
#include <set>
using namespace std;

#define ILE_SZANS 8

void info()
{
	cout << "Gra: Wisielec" << endl;
	cout << "Sprobuj odgadnac wyraz zgadujac wystepujace w nim litery." << endl;
	cout << "Kazda nietrafiona litera skutkuje rysowaniem sie wisielca.\n\n" << endl;
}

void rysuj_wisielca(int n)
{
	if (n == 0) {
		for (int i = 0; i < 7; i++) {
			cout << "\n";
		}
		cout << " ___|___ \n";
	}
	else if (n == 1) {
		cout << "\n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << " ___|___ \n";
	}
	else if (n == 2) {
		cout << "    _______\n";
		cout << "    |     |\n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << " ___|___ \n";
	}
	else if (n == 3) {
		cout << "    _______\n";
		cout << "    |     |\n";
		cout << "    |     O\n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << " ___|___ \n";
	}
	else if (n == 4) {
		cout << "    _______\n";
		cout << "    |     |\n";
		cout << "    |     O\n";
		cout << "    |     |\n";
		cout << "    |     |\n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << " ___|___ \n";
	}
	else if (n == 5) {
		cout << "    _______\n";
		cout << "    |     |\n";
		cout << "    |     O\n";
		cout << "    |    /|\n";
		cout << "    |     |\n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << " ___|___ \n";
	}
	else if (n == 6) {
		cout << "    _______\n";
		cout << "    |     |\n";
		cout << "    |     O\n";
		cout << "    |    /|\\\n";
		cout << "    |     |\n";
		cout << "    |    \n";
		cout << "    |    \n";
		cout << " ___|___ \n";
	}
	else if (n == 7) {
		cout << "    _______\n";
		cout << "    |     |\n";
		cout << "    |     O\n";
		cout << "    |    /|\\\n";
		cout << "    |     |\n";
		cout << "    |    /\n";
		cout << "    |    \n";
		cout << " ___|___ \n";
	}
	else if (n == 8) {
		cout << "    _______\n";
		cout << "    |     |\n";
		cout << "    |     O\n";
		cout << "    |    /|\\\n";
		cout << "    |     |\n";
		cout << "    |    / \\\n";
		cout << "    |    \n";
		cout << " ___|___ \n";
	}
}

void pokaz_bledne(set<char>& bledne)
{
	cout << "\nGracz podal juz litery:\t";
	for (char litera : bledne) {
		cout << litera << " ";
	}
	cout << '\n';
}

void koniec_gry(string odp, string haslo)
{
	if (odp == haslo) {
		cout << "Brawo! Odgadles haslo: " << haslo << endl;
		cout << "Udalo ci sie uratowac wisielca!\n";
	}
	else {
		cout << "O nie! Wisielec zawisnal! Twoje haslo to: " << haslo << endl;
		cout << "Moze nastepnym razem bedzie lepiej :)\n";
	}
}

int main() 
{
	info();
	ofstream plik1("postep.txt", ostream::app);
	string nazwa_plik1 = "postep.txt";
	string nick = "BRAK DANYCH";
	cout << "Podaj nick:" << endl;
	cin >> nick;
	if (plik1.is_open()) 
	{
		plik1 << '\n' << nick << '\t';
		flush(plik1);
	}
	else {
		cout << "Plik nie zostal otwarty." << endl;
	}
	
	cout << "Chcesz zagrac z komputerem (wylosowac haslo), czy z druga osoba?" << endl;
	cout << "(1) komputer" << endl << "(2) z druga osoba" << endl;
	int y = 0;
	y = wczytywanie_int(1, 2);
	GraczWymyslajacy * wymyslajacy = NULL;
	char kategoria = '?';
	string nazwa_plik_z = "zwierzeta";
	string nazwa_plik_j = "jedzenie";
	string nazwa_plik_r = "rzeczy";
	if (y == 1) // Gracz wybral komputer
	{
		wymyslajacy = new GraczWymyslajacyKomputer();
		cout << "\nWybierz kategorie: (z) zwierzeta, (j) jedzenie, (r) rzeczy:\n";
		kategoria=wczytywanie_char();
		if (kategoria == 'z') {
			wymyslajacy->wymyslHaslo(nazwa_plik_z);
		}
		if (kategoria == 'j') {
			wymyslajacy->wymyslHaslo(nazwa_plik_j);
		}
		if (kategoria == 'r') {
			wymyslajacy->wymyslHaslo(nazwa_plik_r);
		}
	}

	if (y == 2) 
	{
		wymyslajacy = new GraczWymyslajacyCzlowiek();
		cout << "\nZ jakiej kategorii chcesz wymyslic haslo? (z) zwierzeta, (j) jedzenie, (r) rzeczy:\n";
		kategoria = wczytywanie_char();
		if (kategoria == 'z') {
			wymyslajacy->wymyslHaslo(nazwa_plik_z);
		}
		if (kategoria == 'j') {
			wymyslajacy->wymyslHaslo(nazwa_plik_j);
		}
		if (kategoria == 'r') {
			wymyslajacy->wymyslHaslo(nazwa_plik_r);
		}
	}

	GraczZgadujacy zgadujacy = GraczZgadujacy(ILE_SZANS, wymyslajacy->podajDlugosc());
	set<char> bledne; 
	bool wybor = false;
	char litera='a';
	int iloscLiter = 0;
	vector<int> pozycjeLitery;
	while (zgadujacy.getIleOdkrytychLiter() < wymyslajacy->podajDlugosc() && zgadujacy.czyZywy())
	{
		pokaz_bledne(bledne);
		zgadujacy.pokaz_progres();
		cout << "\nPodaj litere: ";
		litera = zgadujacy.podajLitere();
		iloscLiter++;
		if (!bledne.count(litera))
		{
			pozycjeLitery = wymyslajacy->czyJestLitera(litera);
			wybor = pozycjeLitery.size() > 0;
		}
		else
			wybor = false;
		if (wybor) {
			cout << "\nDobry traf!" << endl;
			zgadujacy.dobraLitera(litera, pozycjeLitery);
		}
		else {
			cout << "\nBledny traf :(" << endl;
			zgadujacy.zlaLitera();
		}
		rysuj_wisielca(ILE_SZANS - zgadujacy.getProby());
		bledne.insert(litera);
	}

	if (zgadujacy.getHaslo()==wymyslajacy->getHaslo()) {
		plik1 << "\t" << "wygrana";
		flush(plik1);
	}
	else {
		plik1 << "\t" << "przegrana";
		flush(plik1);
	}
	plik1 << "\t\t" << iloscLiter;
	flush(plik1);

	koniec_gry(zgadujacy.getHaslo(), wymyslajacy->getHaslo());
	cout << "\nBaza graczy:" << endl;
	cout << "Nick";
	cout << "\t\t" << "Status";
	cout << "\t\t" << "Ilosc wpisanych wszystkich liter";
	odczyt(nazwa_plik1);
	delete wymyslajacy;
	plik1.close();
	return 0;
}