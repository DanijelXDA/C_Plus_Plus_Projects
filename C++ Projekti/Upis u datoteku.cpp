//////////////////////////////////////////////////////////////////
//          PROGRAM KOJI UPISUJE STRING U TEKSTUALNU DATOTEKU   //
//                  NAPOMENA: Datoteka ne mora postojati!        //
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    string tekst;
    ofstream datoteka;

    cout << "Unesite neku recenicu: ";
    getline(cin, tekst); // Jedan red teksta - citanje sa ulaza

    datoteka.open("datoteka.txt"); // Otvaranje datoteke
    datoteka << tekst; // Upis u datoteku

    datoteka.close(); // Zatvaranje datoteke

    cout << endl << "UPIS U DATOTEKU USPESAN!" << endl;

    return 0;
}
