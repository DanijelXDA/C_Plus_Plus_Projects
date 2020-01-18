#ifndef IMENIK_HPP_INCLUDED
#define IMENIK_HPP_INCLUDED

#include "Student.hpp"

class Imenik
{
    Osoba** ljudi;                            // Niz osoba.
    int kap, n;                               // Kapacitet niza i broj osoba.
public:
    explicit Imenik(int k=10)                 // Stvaranje imenika.
    {
        ljudi = new Osoba* [kap = k];
        n = 0;
    }
    Imenik(const Imenik&) =delete;            // Ne sme da se kopira.
    Imenik& operator=(const Imenik&) =delete; // Ne sme da se dodeljuje.
    ~Imenik();                                // Unistavanje imenika.
    Imenik& operator+=(Osoba* oso)            // Dodavanje osobe.
    {
        if (n == kap)
            exit(2);
        ljudi[n++] = oso;
        return *this;
    }
    int kapac() const
    {
        return kap;    // Kapacitet imenika.
    }
    int vel() const
    {
        return n;    // Broj osoba u imeniku.
    }
    Imenik& uredi();                          // Uredjivanje imenika.
    friend ostream& operator<<(ostream& it, const Imenik& imen); // Pisanje.
};

Imenik::~Imenik()                           // Unistavanje imenika.
{
    for (int i=n; i>0; delete ljudi[--i]);
    delete [] ljudi;
}

Imenik& Imenik::uredi()                     // Uredjivanje imenika.
{
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (*ljudi[j] > *ljudi[i])
            {
                Osoba* pom = ljudi[i];
                ljudi[i] = ljudi[j];
                ljudi[j] = pom;
            }
    return *this;
}

ostream& operator<<(ostream& it, const Imenik& imen)   // Pisanje imenika.
{
    for (int i=0; i<imen.n; i++)
        it << *imen.ljudi[i] << endl;
    return it;
}

#endif // IMENIK_HPP_INCLUDED
