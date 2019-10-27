#include "Stek.hpp"

int main(void)
{
    int broj, izbor;

    cout << endl << "Ovaj program demonstrira rad sa stekom." << endl << endl;

    do {
        do {
            cout << endl << "1 - Upisivanje podatka u stek" << endl;
            cout << "2 - Citanje podatka iz steka" << endl;
            cout << endl << "Vas izbor je: ";
            cin >> izbor;
        } while(izbor != 1 && izbor != 2);

        if(izbor == 1)
        {
            cout << endl << "Unesite jedan ceo broj: ";
            cin >> broj;
            upisiPodatakUStek(broj);
        }
        else
        {
            cout << procitajPodatakIzSteka();
            cout << endl << endl;
            cout << "Nastaviti rad sa stekom? (1 - Da, 0 - Ne)\n>> ";
            cin >> izbor;
        }
    } while(izbor == 1);

    return 0;
}
