#include "../Headers/Proizvodi.hpp"
#include <fstream>

Proizvodi::Proizvodi() // Prazan konstruktor
{

    for(int i = 0; i < 20; i++)
    {
        ID[i] =  i + 1; // ID je u intervalu od 1 do 100
        imeProizvoda[i] = "NEMA";
        for(int j = 0; j < 100; j++ )
        {
            tipSirovinePotrebneZaProizvod[i][j] = "NEMA";
            kolicinaSirovinePotrebneZaProizvod[i][j] = 0.0;
        }
    }
}


void Proizvodi::dodavanjeProizvoda()
{
    string proizvod;
    // Datotecni tok
    ifstream citanjeMagacin;
    citanjeMagacin.open("Magacin.txt");

    cout << "********************************************************************************" << endl;
    cout << "\t\t\tDodajete proizvod na listu!" << endl << endl;
    cout << "********************************************************************************" << endl;


    cout << "Ime novog proizvoda: ";
    cin.ignore(); // kao fflush()
    getline(cin, proizvod);

    cout << "Unos kolicine potrebnog materijala za proizvod \"" << proizvod << "\" " << endl;

    // Setovanje
    for(int i = 1; i < 100; i += 3) // Trazi se prvo slobodno mesto
        for(int j = 0; j < 20; j++)
        {
            cout << "\t" << str[i] << ": ";
            cin >> kolicinaSirovinePotrebneZaProizvod[i][j];

            cout << endl << "Jedinica mere: ";
            cin >> tipSirovinePotrebneZaProizvod[i][j];
        }

    if( upisProizvodiTXT() )
        cout << endl << "PROIZVOD JE DODAT NA LISTU!" << endl;

    return;
}

bool Proizvodi::upisProizvodiTXT()
{
    bool uspesanUpis = false;

    ofstream proizvodi; // UPIS
    proizvodi.open("Proizvodi.txt");

    if( proizvodi.is_open() )
    {

        // UPIS U Proizvodi.txt
        for(int i = 0; i < 100; i++)
            for(int j = 0; j < 20; j++)
            {
                proizvodi << ID[i];
                proizvodi << " " << imeProizvoda[i];
                proizvodi << " " << tipSirovinePotrebneZaProizvod[i][j];
                proizvodi << " " << kolicinaSirovinePotrebneZaProizvod[i][j] << endl;
            }
        proizvodi.close(); // Zatvranje datoteke

        uspesanUpis = true;
    }
    else
        cout << endl << "DATOTEKA NE POSTOJI!" << endl;

    return uspesanUpis;

}
