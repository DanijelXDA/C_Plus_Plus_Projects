#ifndef OSOBA_HPP_INCLUDED
#define OSOBA_HPP_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Osoba
{
    string ime;                             // Ime osobe.
    int god;                                // Godine starosti.
public:
    Osoba(string ii, int gg)                // Stvaranje objekta.
    {
        ime = ii;
        god = gg;
    }
    Osoba(const Osoba&) =delete;            // Ne sme da se kopira.
    Osoba& operator=(const Osoba&) =delete; // Ne sme da se dodeljuje.
    virtual ~Osoba() {}                     // Virtuelan destruktor.
    friend bool operator>(const Osoba& o1,  // Da li je starija?
                          const Osoba& o2)
    {
        return o1.god > o2.god;
    }

protected:
    virtual void pisi(ostream& it) const    // Pisanje osobe.
    {
        it << ime << '(' << god << ')';
    }
    friend ostream& operator<<(ostream& it, const Osoba& oso)
    {
        oso.pisi(it);
        return it;
    }
};
#endif // OSOBA_HPP_INCLUDED
