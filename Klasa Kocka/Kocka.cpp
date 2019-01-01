#include "Kocka.hpp"

Kocka::Kocka()
{
    a = 1.0;
}

Kocka::Kocka(double stranicaA)
{
    a = stranicaA;
}

Kocka::Kocka(const Kocka &k)
{
    a = k.a;
}

void Kocka::setA(double stranicaA)
{
    a = stranicaA;
}

double Kocka::zapreminaKocke()
{
    return pow(a, 3);
}

double Kocka::povrsinaKocke()
{
    return 6 * pow(a, 2);
}

double Kocka::povrsinaStraniceKocke()
{
    return pow(a, 2);
}

double Kocka::obimStraniceKocke()
{
    return 4.0 * a;
}

double Kocka::dijagonalaStraniceKocke()
{
    return a * sqrt(a);
}

void Kocka::prikazi()
{
    cout << "\tStranica a: " << a << endl << "\tPovrsina: " << povrsinaKocke() << endl
         << "\tZapremina kocke: " << zapreminaKocke() << endl;

    cout << "\tObim stranice kocke: " << obimStraniceKocke() << endl
         << "\tPovrsina stranice kocke: " << povrsinaStraniceKocke() << endl
         << "\tDijagonala stranice kocke: " << dijagonalaStraniceKocke() << endl << endl << endl << endl;
}
