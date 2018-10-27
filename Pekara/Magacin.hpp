#ifndef MAGACIN_HPP_INCLUDED
#define MAGACIN_HPP_INCLUDED

#include "Logovanje.hpp"
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
        void sadrzajMagacina();
        void dodavanjeUMagacin();
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

void Magacin::sadrzajMagacina() {
    system("cls");

    int prvoPojavljivanje = 0;

    for(int i = 0; i < 100; i++) {
        if(i == 99 && imeSirovine[99] == "NEMA")
            cout << endl << endl << "\t\t\t\tMAGACIN JE PRAZAN!" << endl << endl;

        if( prvoPojavljivanje == 1 )
            cout << "U magacinu se nalaze sledece sirovine: " << endl;

        if(imeSirovine[i] != "NEMA") {
            prvoPojavljivanje++;
            cout << endl << endl << "ID: " << ID[i];
            cout << endl << "Sirovina: " << imeSirovine[i] << endl;
            cout << "Kolicina: " << kolicinaSirovine[i] << endl;
            cout << "Jedinica mere: " << jedinicaMere[i];
        }
        else {
            cout << "";
            break;
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
#endif // MAGACIN_HPP_INCLUDED
