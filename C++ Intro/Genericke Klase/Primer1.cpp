#include <iostream>
using namespace std;

template <typename T> T veci(T prvi, T drugi)
{
    return (prvi > drugi) ? prvi : drugi;
}

int main(void)
{
    cout << endl << "Genericke funkcije" << endl << endl;

    int a = 15, b = 25;
    cout << "Veci broj od 15 i 25 je: " << veci(a, b) << endl;

    float c = 15.5, d = 4.8;
    cout << "Veci broj od 15.5 i 4.8 je: " << veci(c, d) << endl;

    double e = 18.3, f = 18.3;
    cout << "Veci broj od 18.3 i 19.3 je: " << veci(e, f) << endl;

    char g = 't', h = 'e';
    cout << "Veci broj od 't' i 'e' je: " << veci(g, h) << endl;

    return 0;
}
