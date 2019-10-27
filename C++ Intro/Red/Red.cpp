#include "Red.hpp"

#define MAX 50

int redPodataka[MAX];
int vrhReda = 0;

bool redJePun()
{
    return (vrhReda == MAX) ? true : false;
}

bool redJePrazan()
{
    return (vrhReda == 0) ? true : false;
}

void upisiPodatakURed(int broj)
{
    if(redJePun() == true)
        cout << endl << "Red je pun!" << endl;
    else
    {
        for(int i = vrhReda; i > 0; i--)
            redPodataka[i] = redPodataka[i - 1];

        redPodataka[0] = broj;
        vrhReda++;
    }
}

int procitajPodatakIzReda()
{
    if(redJePrazan() == true)
    {
        cout << endl << "Red je prazan!" << endl;
        return INT_MIN;
    }
    else
    {
        vrhReda--;
        return redPodataka[vrhReda];
    }
}
