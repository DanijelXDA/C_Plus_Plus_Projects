//////////////////////////////////////////////////////////////////
//          PROGRAM KOJI CITA SADRZAJ JEDNE TEKSTUALNE DATOTEKE //
//                  NAPOMENA: Datoteka mora postojati!          //
//                  Cita se samo jedna linija teksta!          //
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    string linijaTekstaIzDatoteke;
    ifstream datoteka ("datoteka.txt"); // Otvaranje datoteke u modu citanja

    if( datoteka.is_open() )
    {
        getline(datoteka, linijaTekstaIzDatoteke);

        datoteka.close(); // Zatvaranje datoteènog toka

    }
    else
        cout << "Datoteka ne postoji!" << endl;

    cout << endl << linijaTekstaIzDatoteke << endl;

    return 0;
}
