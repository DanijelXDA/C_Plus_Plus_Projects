#include "Clan.hpp"

int main(void)
{
    Clan* c1 = new Clan[50];
    int choose, pokrenuto = 0, del = -1;

    do {
    cout << endl << "*********************** PROGRAM: BIBLIOTEKA **********************" << endl;
        do {
            meni();
            cin >> choose;
        } while(choose < 0 || choose > 4);

        switch(choose)
        {
            case 1:
                if(del == -1) {
                    c1[pokrenuto].dodajClana();
                    pokrenuto++;
                }
                else {
                    c1[del].dodajClana();
                    del = -1;
                }
                break;

            case 2:
                del = izbrisiClana(c1);
                break;

            case 3:
                for(int i = 0; i < pokrenuto; i++)
                    c1[i].naplati();
                break;

            case 4:
                prikaziClanove(c1);
                break;
        }
    } while(choose != 0);

    return 0;
}
