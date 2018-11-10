#ifndef MAGACIN_HPP_INCLUDED
#define MAGACIN_HPP_INCLUDED

#include "Logovanje.hpp"
#include "Proizvodi.hpp"
#include <string>

class Magacin {
    private:
        int ID[100];
        string imeSirovine[100];
        float kolicinaSirovine[100]; // Za sto elemenata
        string jedinicaMere[100];
        bool naStanju;
    public:
        Magacin();
        bool proveraStanjaUMagacinu();
        void sadrzajMagacina();
        void dodavanjeUMagacin();
        void izbacivanjeIzMagacina();
        void azuriranjeSirovine();
};

Magacin::Magacin() {

    for(int i = 0; i < 100; i++)
    {
        ID[i] =  i + 1;
        imeSirovine[i] = "NEMA";
        kolicinaSirovine[i] = 0;
        jedinicaMere[i] = "NEMA";
    }

    naStanju = false;
}

bool Magacin::proveraStanjaUMagacinu()
{
        // Magacin je prazan AKO JE PRVO MESTO PRAZNO
        if(imeSirovine[0] == "NEMA")
            return true; // Potvrdno - MAGACIN JE PRAZAN
        else
            return false; // Magacin nije prazan
}
void Magacin::sadrzajMagacina() {
    system("cls");

    int poruka = 1; // Samo jedan ispis

    for(int i = 0; i < 100; i++) {

        // Magacin je prazan AKO JE PRVO MESTO PRAZNO
        if( proveraStanjaUMagacinu() )
            cout << endl << endl << "\t\t\t\tMAGACIN JE PRAZAN!" << endl << endl;
        else if(poruka) {
            cout << "U magacinu se nalaze sledece sirovine: " << endl;
            poruka = 0;
        }

        if(imeSirovine[i] != "NEMA") {
            cout << endl << endl << "ID: " << ID[i];
            cout << endl << "Sirovina: " << imeSirovine[i] << endl;
            cout << "Kolicina: " << kolicinaSirovine[i] << endl;
            cout << "Jedinica mere: " << jedinicaMere[i];
        }
    }
    return;
}

void Magacin::dodavanjeUMagacin() {
    string sirovina;
    string jedMere;
    float kolicina;

    cout << "********************************************************************************" << endl;
    cout << "\t\t\tDodajete sirovinu u magacin!" << endl << endl;
    cout << "********************************************************************************" << endl;


    cout << "Ime nove sirovine: ";
    cin.ignore(); // kao fflush()
    getline(cin, sirovina);

    cout << "Kolicina nove sirovine: ";
    cin >> kolicina;

    cout << "Jedinica mere nove sirovine: ";
    cin >> jedMere;

    // Setovanje
    for(int i = 0; i < 100; i++) // Trazi se prvo slobodno mesto
        if(imeSirovine[i] == "NEMA"){
            imeSirovine[i] = sirovina;
            kolicinaSirovine[i] = kolicina;
            jedinicaMere[i] = jedMere;

            cout << endl << "SIROVINA JE DODATA U MAGACIN!" << endl;

            break;
        }

        system("cls");

    return;
}

void Magacin::izbacivanjeIzMagacina() {

    if( proveraStanjaUMagacinu() ) // BUG: Magacin je uvek prazan!?
        cout << endl << "Magacin je prazan! Izbacivanje onemoguceno!" << endl;
    else {
        int ID;

        cout << "********************************************************************************" << endl;
        cout << "\t\t\tIzbacujete sirovinu iz magacina!" << endl << endl;
        cout << "********************************************************************************" << endl;

        cout << endl << "Unesite ID sirovine koju izbacujete: ";
        cin >> ID;

        for(int i = ID - 1; i < 100; i++) { // Rotiranje niza ulevo za jedno mesto
            if(imeSirovine[i] != "NEMA") {
                imeSirovine[i] = imeSirovine[i + 1];
                kolicinaSirovine[i] = kolicinaSirovine[i + 1];
            }
            else {
                imeSirovine[i] = "NEMA";
                kolicinaSirovine[i] = 0.0;
            }
        }
    }

    return;
}

void Magacin::azuriranjeSirovine() {

    if( proveraStanjaUMagacinu() )
        cout << endl << "Magacin je prazan! Azuriranje onemoguceno" << endl;
    else {

        int ID;

        cout << "********************************************************************************" << endl;
        cout << "\t\t\tAzuriranje sirovine iz magacina!" << endl << endl;
        cout << "********************************************************************************" << endl;

        cout << endl << "Unesite ID sirovine koju azurirate: ";
        cin >> ID;

        if(ID <= 0) {
            cout << endl << "Ne postoji sirovina sa nultim ID-om! (ID++)" << endl;
            ID = 1;
        }

        while(imeSirovine[ID - 1] == "NEMA") {
            cout << endl << endl << "Na unetoj pozicije ne postoji sirovina!";
            cout << endl << "Unesite ID sirovine koju azurirate: ";
            cin >> ID;
        }


        cout << endl << "Azuriranje imena sirovine: ";
        cin.ignore();
        getline(cin, imeSirovine[ID - 1]);

        cout << endl << "Azuriranje kolicine sirovine u magacinu: ";
        cout << endl << "Unesite novu kolicinu sirovine: ";
        cin >> kolicinaSirovine[ID - 1];
    }

    return;
}

#endif // MAGACIN_HPP_INCLUDED
