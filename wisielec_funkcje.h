#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
#include <ctype.h>

using namespace std;

// deklaracja funkcji

int wczytywanie_int(int pom, int pom1);
char wczytywanie_char();
bool tylko_litery(const string& haslo);
void koniec_gry(string odp, string haslo);
string hasloStart(int dlugosc);
void odczyt(const string& nazwa_plik1);

// klasa abstrakcyjna
class Gracz
{
protected:
	string haslo;
	Gracz(string haslo) : haslo(haslo) {}

public:
	string getHaslo() {
		return haslo;
	}
};


// zawsze cz³owiek
class GraczZgadujacy : public Gracz {
private:
	int proby; // ile jeszcze mo¿liwych pomy³ek
	int ileOdkrytychLiter;
public:

	bool czyZywy() {
		return proby > 0;
	}

	void zlaLitera() {
		proby--;
	}

	void pokaz_progres() {
		cout << haslo << endl;
	}

	char podajLitere() {
		return wczytywanie_char();
	}

	// pierwsza litera ma pozycje 0
	void dobraLitera(char litera, vector<int>& pozycje) {
		for(int pozycja : pozycje)
			haslo[pozycja] = litera;
		ileOdkrytychLiter += pozycje.size();
	}

	int getIleOdkrytychLiter() {
		return ileOdkrytychLiter;
	}

	int getProby() {
		return proby;
	}

	GraczZgadujacy(int proby, int dlugoscHasla) : Gracz(hasloStart(dlugoscHasla)), proby(proby), ileOdkrytychLiter(0) {}
};

// klasa abstrakcyjna
class GraczWymyslajacy : public Gracz {
public:
	virtual void wymyslHaslo(string& kategoria) = 0;

	vector<int> czyJestLitera(char litera) {
		vector<int> pozycje = {};
		for (int i = 0; i < haslo.size(); i++) {
			if (haslo[i] == litera)
				pozycje.push_back(i);
		}
		return pozycje;
	}

	int podajDlugosc() {
		return haslo.size();
	}

	GraczWymyslajacy() : Gracz("") {}
};

class GraczWymyslajacyCzlowiek : public GraczWymyslajacy {
public:
	void wymyslHaslo(string& kategoria) override {
		cout << "\nPodaj haslo z kategorii " << kategoria << " - jedno slowo - do odgadniecia dla drugiego gracza : \t";
		char c;
		haslo = "";
		while ((c = _getch()) != '\r') {
			cout << '*';
			haslo.push_back(c);
		}
		if (!tylko_litery(haslo))
		{
			cout << "Bledne haslo!\n";
			this->wymyslHaslo(kategoria);
		}
	}

	GraczWymyslajacyCzlowiek() : GraczWymyslajacy() {}
};

class GraczWymyslajacyKomputer : public GraczWymyslajacy {
public:
	void wymyslHaslo(string& kategoria) override {
		string nazwa_plik = kategoria + ".txt";
		ifstream plik(nazwa_plik);
		vector<string> slowa;
		string haslo;
		while (plik >> haslo)
		{
			slowa.push_back(haslo);
		}
		srand(static_cast<unsigned int>(time(nullptr)));
		int losowe = rand() % slowa.size();

		this->haslo = slowa[losowe];
	}
};
