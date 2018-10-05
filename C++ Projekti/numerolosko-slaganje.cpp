#include <iostream>
#include <algorithm> // Brisanje tački iz stringa
using namespace std;

int racunanjeStringToZbir(string *p)
{
    int sum = 0;
    string datum = *p;
    for(unsigned i = 0; i < datum.size(); i++)
            sum += datum[i] - '0'; // Konverzija cifre u int

    return sum;
}


int main(void)
{
    string ime1, ime2;
    string datum1, datum2;
    unsigned procSlaganjaO1 = 0, procSlaganjaO2 = 0;

    cout << "Dobrodosli u aplikaciju \"Numerolosko slaganje\" " << endl;

    cout << endl << "Unos podataka za Osobu 1.";
    cout << endl << "\tUnesite ime prve osobe: ";
    cin >> ime1;

    cout << "\tUnesite datum rodjenja prve osobe (u formatu DD.MM.YYYY): ";
    cin >> datum1;

    cout << endl << "Unos podataka za Osobu 2.";
    cout << endl << "\tUnesite ime druge osobe: ";
    cin >> ime2;

    cout << "\tUnesite datum rodjenja druge osobe (u formatu DD.MM.YYYY): ";
    cin >> datum2;

    // Brisanje tački unutar stringa
    datum1.erase(std::remove(datum1.begin(), datum1.end(), '.'), datum1.end());

    // Brisanje tački unutar stringa
    datum2.erase(std::remove(datum2.begin(), datum2.end(), '.'), datum2.end());

    // Prvo računanje
    string *pok = &datum1;
    procSlaganjaO1 = racunanjeStringToZbir(pok);

    datum1 = ( (procSlaganjaO1 / 10) + '0' );
    datum1 += (procSlaganjaO1 - ( (procSlaganjaO1 / 10) * 10 ) + '0' );

    // Drugo računanje
    procSlaganjaO1 = racunanjeStringToZbir(pok);


    // Za drugu osobu //

    // Prvo računanje
    string *pok2 = &datum2;
    procSlaganjaO2 = racunanjeStringToZbir(pok2);

    datum2 = ( (procSlaganjaO2 / 10) + '0' );
    datum2 += (procSlaganjaO2 - ( (procSlaganjaO2 / 10) * 10 ) + '0' );

    // Drugo računanje
    procSlaganjaO2 = racunanjeStringToZbir(pok2);

    /* Test ispis
    cout << endl << procSlaganjaO1;
    cout << endl << procSlaganjaO2;
    /* KRAJ TEST ISPISA */

    float slaganje = ( (float)procSlaganjaO1 / (float)procSlaganjaO2)  * 100 ; // Cast numbers to float

    if( slaganje > 100.)
        slaganje -= 100.;

    cout << endl << "Procenat slaganja osoba " << ime1 << " i " << ime2 << " je: ";
    cout << slaganje << "%" << endl;

    return 0;
}
