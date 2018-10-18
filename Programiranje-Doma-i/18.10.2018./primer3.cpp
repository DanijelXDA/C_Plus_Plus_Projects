#include <iostream>
using namespace std;

void unosDvaBroja(int& b1, int& b2)
{
    cout << "Unesite prvi broj: ";
    cin >> b1;

    cout << "Unesite drugi broj: ";
    cin >> b2;

    return;
}

int saberi(int b1, int b2)
{
    return b1 + b2;
}


int main(void)
{
    int b1, b2;

    unosDvaBroja(b1, b2);
    cout << endl << "Zbir brojeva " << b1 << " + " << b2 << " je: " << saberi(b1, b2);

    return 0;
}
