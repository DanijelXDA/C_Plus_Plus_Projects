#include "Stek.hpp"

#define MAX 50

int stekPodataka[MAX];
int vrhSteka = 0;

bool stekJePun()
{
    return (vrhSteka == MAX) ? true : false;
}

bool stekJePrazan()
{
    return (vrhSteka == 0) ? true : false;
}

void upisiPodatakUStek(int broj)
{
    if(stekJePun() == true)
        cout << endl << "Stek je pun!" << endl;
    else
    {
        stekPodataka[vrhSteka] = broj;
        vrhSteka++;
    }
}

int procitajPodatakIzSteka()
{
    if(stekJePrazan() == true)
    {
        cout << endl << "Stek je prazan!" << endl;
        return INT_MIN;
    }
    else
    {
        vrhSteka--;
        return stekPodataka[vrhSteka];
    }
}
