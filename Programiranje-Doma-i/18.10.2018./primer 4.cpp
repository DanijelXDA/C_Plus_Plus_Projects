#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    double broj;
    int stepen;

    cout << "Unesite koji broj stepenujete: ";
    cin >> broj;

    do {
        cout << endl << "Unesite na koji stepen bi da stepenujete broj: ";
        cin >> stepen;
    } while( stepen < 0);


    cout << endl << "Stepen broja " << broj << " je " << pow(broj, stepen);

    return 0;
}
