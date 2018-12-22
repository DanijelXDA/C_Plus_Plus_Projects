#include <iostream>
using namespace std;

class Osoba {
    private:
        string ime;
        int godine;
    public:
        Osoba(); // prazan konstruktor
        Osoba(string, int); // konstruktor sa parametrima
        Osoba(const Osoba &); // konstruktor kppije
        // geteri i seteri za polja klase - omogucava pristup privatnim clanovima klasa preko slobodnih funkcija!
        string getIme(); // geter za polje ime tipa string
        int getGodine(); // geter za polje godine tipa int
        void setIme(string); // seter za polje ime tipa string
        void setGodine(int); // seter  za polje godine tipa int
        // funkcije metode clanice koje imaju pristup privatnom delu klase!
        void predstaviSe(); // metoda clanica klase koja prika
};

// Definicije metoda klase Osoba
Osoba::Osoba() // prazan konstruktor
{
    ime = "";
    godine = 0;
}

Osoba::Osoba(string i, int g) // konstruktor sa parametrima
{
    ime = i;
    godine = g;
}

Osoba::Osoba(const Osoba &o) // konstrukor kopije
{
    ime = o.ime;
    godine = o.godine;
}

string Osoba::getIme() { return ime; } // geter za polje ime tipa string
int Osoba::getGodine() { return godine; } // geter za polje godine tipa int
void Osoba::setIme(string i) { ime = i; }   // seter za polje ime tipa string
void Osoba::setGodine(int g) { godine = g; }  // seter  za polje godine tipa int

void Osoba::predstaviSe()
{
    cout << "\t\tZovem se: " << ime << ", i imam " << godine << " godina/e." << endl;
}

// slobodna funkcija
void predstaviSeVanKlase(Osoba &o)
{
    cout << "\t\tZovem se: " << o.getIme() << ", i imam " << o.getGodine() << " godina/e." << endl;
}

int main(void)
{
    Osoba o1; // poziva se prazan konstruktor
    Osoba o2("Danijel", 17); // poziva se kosntrukor sa parametrima!
    Osoba o3(o2); // poziva se konstruktor kopije

    // ispis pomocu metode iz klase Osoba
    cout << "Ovo je metoda klase Osoba!" << endl << "Ona ime pristup direktno privatnom delu klase!" << endl;
    cout << "Ispis podataka za polja klase: " << endl << endl;
    o1.predstaviSe();
    o2.predstaviSe();
    o3.predstaviSe();

    // ipsis pomocu slobodne funkcije izvan klase Osoba
    cout << endl << endl<< endl << "Ovo je slobodna funkcija!" << endl << "Nema pristup direktno privatnom delu klase!" << endl;
    cout << "Ispis podataka pomocu getera za polja klase: " << endl << endl;
    predstaviSeVanKlase(o1);
    predstaviSeVanKlase(o2);
    predstaviSeVanKlase(o3);

    return 0;
}
