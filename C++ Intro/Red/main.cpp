#include "Red.hpp"

int main(void)
{
    int broj, izbor;

    cout << endl << "Ovaj program demonstrira rad sa redom." << endl << endl;

    do {
        do {
            cout << endl << "1 - Upisivanje podatka u red" << endl;
            cout << "2 - Citanje podatka iz reda" << endl;
            cout << endl << "Vas izbor je: ";
            cin >> izbor;
        } while(izbor != 1 && izbor != 2);

        if(izbor == 1)
        {
            cout << endl << "Unesite jedan ceo broj: ";
            cin >> broj;
            upisiPodatakURed(broj);
        }
        else
        {
            cout << procitajPodatakIzReda();
            cout << endl << endl;
            cout << "Nastaviti rad sa redom? (1 - Da, 0 - Ne)\n>> ";
            cin >> izbor;
        }
    } while(izbor == 1);

    return 0;
}
