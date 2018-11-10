#include "../Headers/Meni.hpp"

void prikaziMeni() {

    Magacin m;
    Proizvodi p;

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
            case 0: {
                cout << "Napustate program......";
                kraj = false;
                break;
            }
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
            case 3: {
                system("cls");
                m.izbacivanjeIzMagacina();
                break;
            }
            case 4: {
                system("cls");
                m.azuriranjeSirovine();
                break;
            }
            case 5: {
                system("cls");
                p.dodavanjeProizvoda();
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
