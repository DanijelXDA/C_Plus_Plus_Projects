#include "../Headers/Proizvodi.hpp"
#include <fstream>

Proizvodi::Proizvodi() // Prazan konstruktor
{

    for(int i = 0; i < 20; i++)
    {
        ID[i] =  i + 1; // ID je u intervalu od 1 do 100

        for(int j = 0; j < 100; j++ )
        {
            tipSirovinePotrebneZaProizvod[i][j] = "NEMA";
            kolicinaSirovinePotrebneZaProizvod[i][j] = 0.0;
        }
    }
}


void Proizvodi::dodavanjeProizvoda()
{
    Magacin m;
    string proizvod;
    // Datotecni tok
    ifstream citanjeMagacin;
    citanjeMagacin.open("Magacin.txt", ios::in | ios::out);

    cout << "********************************************************************************" << endl;
    cout << "\t\t\tDodajete proizvod na listu!" << endl << endl;
    cout << "********************************************************************************" << endl;


    cout << "Ime novog proizvoda: ";
    cin.ignore(); // kao fflush()
    getline(cin, proizvod);

    cout << "Unos kolicine potrebnog materijala za proizvod \"" << proizvod << "\" " << endl;


    system("cls");

    return;
}
