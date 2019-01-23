#include "Valjak.hpp"

int main()
{
    Valjak v1;
    Valjak v2(3, 4);
    Valjak v3(v1);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;

    v2.setR(2);
    v2.setH(-10);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;

    v1 = v2;
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    v1 += v2;
    cout << "v1: " << v1 << endl;

    cout << "v1: " << ++v1 << endl;
    cout << "v2: " << v2++ << endl;

    Valjak v;
    v = v1 + v2;

    cout << "v: " << v << endl;

    return 0;
}
