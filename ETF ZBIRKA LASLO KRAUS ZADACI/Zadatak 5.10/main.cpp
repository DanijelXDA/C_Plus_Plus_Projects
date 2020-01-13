#include "Imenik.hpp"

int main(void)
{
    Osoba o1("Danijel", 22), o2("Mau", 25);
    o1 > o2;
    cout << o1 << o2;

    Student s1("Daaa", 63), s2("lldslda", 20);
    cout << s1 << s2 << endl;

    s1 += 5.6;
    s1 += 4.4;
    s2 += 10;
    s2 += 9;

    cout << s1 << s2 << endl;

    return 0;
}
