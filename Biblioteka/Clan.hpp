#ifndef CLAN_HPP_INCLUDED
#define CLAN_HPP_INCLUDED

/***
Skicirati klasu koja predstavlja člana biblioteke.
Svaki član biblioteke ima svoj članski broj, ime i prezime, i
trenutno stanje računa za naplatu članarine.

Ova klasa treba da ima funkciju za naplatu članarine,
koja će sa računa člana skinuti odgovarajuću konstantnu sumu.
Biblioteka poseduje i posebnu kategoriju počasnih članova,
kojima se ne naplaćuje članarina. Kreirati niz pokazivača na
objekte klase članova biblioteke, i definisati funkciju za naplatu
članarine svim članovima. Ova funkcija treba da prolazi kroz niz članova
i vrši naplatu pozivom funkcije klase za naplatu, bez obzira što se u
nizu mogu nalaziti i "obični" i počasni članovi.

***/

#include <iostream>
using namespace std;

#define CLANARINA 200

#include <iomanip>

class Clan
{
    private:
        int id;
        string ime;
        string prezime;
        float racun;
        bool VIP;
        /// staticke promenljive
        static int instance;
        static int lastPos;
    public:
        /// constructors
        Clan()
        {
            id = 0;
            ime = "";
            prezime = "";
            racun = 0.0;
            VIP = false;
        }
        Clan(int id, string ime, string prezime, float racun, bool VIP)
        {
            this -> id = id;
            this -> ime = ime;
            this -> prezime = prezime;
            this -> racun = racun;
            this -> VIP = VIP;
            instance++;
        }
        /// geters
        int getId() {  return id; }
        string getIme() { return ime; }
        string getPrezime() { return prezime; }
        float getRacun() { return racun; }
        bool getVIP() { return VIP; }
        int getInstance() { return instance; }
        int getLastPos() { return lastPos; }

        /// seters
        void setId(int i) { id = i; }
        void setIme(string i) { ime = i; }
        void setPrezime(string p) { prezime = p; }
        void setRacun(float r) { racun = r; }
        void setVIP(bool v) { VIP = v; }
        void setInstance(int i) { instance = i; }
        void setLastPos(int l) { lastPos = l; }

        /// metode
        void naplati()
        {
            if(VIP == false)/// nije VIP clan
            {
                if(racun < CLANARINA)
                    cout << endl << " ******************** Nema dovoljno sredstava na racunu! ****************" << endl;
                else
                    racun -= CLANARINA;
            }
        }
        void dodajClana()
        {
            if(lastPos == 0)
            {
                cout << endl << "************************* DODAVANJE CLANA **********************" << endl;
                id = instance;
                cout << "\tIme: ";
                cin >> ime;
                cout << "\tPrezime: ";
                cin >> prezime;
                cout << "\tUnesite stanje na racunu: ";
                cin >> racun;

                int izbor;
                do
                {
                    cout << "\tDa li je ovo VIP clan? (1 - Da, 2 - Ne)\n\t>> ";
                    cin >> izbor;
                }
                while(izbor != 1 && izbor != 2);

                if(izbor == 1)
                    VIP = true;
                else
                    VIP = false;

                instance++;
            }
            else
            {
                cout << endl << "************************* DODAVANJE CLANA **********************" << endl;
                id = lastPos;
                cout << "\tIme: ";
                cin >> ime;
                cout << "\tPrezime: ";
                cin >> prezime;
                cout << "\tUnesite stanje na racunu: ";
                cin >> racun;

                int izbor;
                do
                {
                    cout << "\tDa li je ovo VIP clan? (1 - Da, 2 - Ne)\n\t>> ";
                    cin >> izbor;
                }
                while(izbor != 1 && izbor != 2);

                if(izbor == 1)
                    VIP = true;
                else
                    VIP = false;

                setLastPos(0);
            }
        }
        friend int izbrisiClana(Clan c[])
        {
            cout << endl << "*********************** BRISANJE CLANA **********************" << endl;

            if(instance == 0)
                cout << endl << "*********************** NEMA CLANOVA! **********************" << endl << endl;
            else
            {
                int del;
                do {
                    cout << endl << "Unesite ID clana kojeg bi da obrisete\n>> ";
                    cin >> del;
                } while(del < 0 || del > instance - 1);

                c[del].ime = "IZBRISAN";
                c[del].prezime = "IZBRISAN";
                c[del].racun = -1.0;
                c[del].VIP = false;

                lastPos = del;
            }
            return lastPos;
        }
        friend void prikaziClanove(Clan c[])
        {
            cout << endl << "*********************** PRIKAZI CLANOVE **********************" << endl;

            if(instance == 0)
                cout << endl << "*********************** NEMA CLANOVA! **********************" << endl << endl;
            else
            {
                for(int i = 0; i < instance; i++)
                {
                    if(c[i].ime == "IZBRISAN")
                        cout << "";
                    else
                    {
                        cout << "\tId: " << c[i].id << endl;
                        cout << "\tIme: " << c[i].ime << endl;
                        cout << "\tPrezime: " << c[i].prezime << endl;
                        cout << "\tRacun: " << c[i].racun << endl;
                        cout << "\tStatus: " << ((c[i].VIP == true) ? "VIP" : "OBICAN") << endl << endl;
                    }
                }
            }
        }
};

/// init static members
int Clan::instance = 0;
int Clan::lastPos = 0;

void meni()
{
    cout << "1 - Dodaj clana" << endl;
    cout << "2 - Izbrisi clana" << endl;
    cout << "3 - Naplati clanarinu svima" << endl;
    cout << "4 - Prikazi sve clanove" << endl;
    cout << "0 - Izlaz" << endl;
    cout << endl << "Izbor\n>> ";
}

#endif // CLAN_HPP_INCLUDED
