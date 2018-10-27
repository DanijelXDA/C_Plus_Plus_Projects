#ifndef MENI_HPP_INCLUDED
#define MENI_HPP_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#include "Magacin.hpp"

void prikaziMeni() {

    Magacin m;

    int izbor = 0;
    bool kraj = true;

    // UI nadogradnja
    if(izbor != 0)
        system("cls");

    while(kraj) {
        cout << "********************************************************************************" << endl;
        cout << "\t\t\tDobrodosli u aplikaciju PEKARA" << endl << endl;
        cout << "********************************************************************************" << endl;
        cout << endl << "\t\t\t\tMOGUCE OPERACIJE: " << endl << endl;
        cout << "     1. Pregled sadrzaja magacina     \t2. Dodavanje sirovine u magacin" << endl << endl;
        cout << "     3. Izbacivanje sirovine iz mag.    4. Azuriranje kolicine sirovine" << endl << endl;
        cout << "     5. Dodavanje novog proizvoda     \t6. Izbacivanje proizvoda" << endl << endl;
        cout << "     7. Dodavanje dobavljaca (pekara)   8. Brisanje dobavljaca (pekara)" << endl << endl;
        cout << "     9. Dodavanje porudzbine pekara     10. Racunanje nestalih peciva" << endl << endl;


        cout << endl << "Vas izbor je: ";
        cin >> izbor;
        cout << endl << endl;

        switch(izbor) {
            case 1: {
                system("cls");
                m.sadrzajMagacina();
                break;
            }
            case 2: {
                system("cls");
                m.dodavanjeUMagacin();
                break;
            }

            default:
                cout << endl << endl << "Izabrana opcija nije validna!" << endl << endl;
        }
        cout << endl << endl << "Pritisnite bilo koji taster za nastavak..." << endl;
        getchar();
        getchar();
        system("cls");
    }

    return;
}



#endif // MENI_HPP_INCLUDED
