#include <iostream>
//#include <iomanip>
using namespace std;

void unosStranicaPravougaonika(float& a, float& b)
{
    do {
        cout << "Unesite stranicu a = ";
        cin >> a;
    } while(a <= 0);

    do {
        cout << "Unesite stranicu b = ";
        cin >> b;
    } while(b <= 0);

    return;
}

float obimPravougaonika(float a, float b)
{
    return 2. *(a + b);
}

float povrsinaPravougaonika(float a, float b)
{
    return a * b;
}

int main(void)
{
    float a, b;

    unosStranicaPravougaonika(a, b);
    cout << endl << "Povrsina pravougaonika stranica " << a << " x " << b << " iznosi: " << povrsinaPravougaonika(a, b) << endl;
    cout << endl << "Obim pravougaonika stranica " << a << " x " << b << " iznosi: " << obimPravougaonika(a, b) << endl;

    return 0;
}
