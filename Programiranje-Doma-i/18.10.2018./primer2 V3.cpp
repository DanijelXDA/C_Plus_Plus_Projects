#include <iostream>
using namespace std;

int najmanjiOdTriBroja(int b1, int b2, int b3)
{
    int m;

    return ( m = (b1 < b2) ? b1 : b2 ) < b3 ? m : b3;
}

void unosTriBroja(int& b1, int& b2, int& b3)
{
    cout << "Unesite 1. broj: ";
    cin >> b1;

    cout << "Unesite 2. broj: ";
    cin >> b2;

    cout << "Unesite 3. broj: ";
    cin >> b3;

    return;
}

int main(void)
{
    int b1, b2, b3;

    unosTriBroja(b1, b2, b3);

    cout << endl << "Najmanji broj je: " << najmanjiOdTriBroja(b1, b2, b3);

    return 0;
}
