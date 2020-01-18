#ifndef STUDENT_HPP_INCLUDED
#define STUDENT_HPP_INCLUDED

#include "Osoba.hpp"
#include <cstdlib>

class Student: public Osoba
{
    int* ocene;                           // Niz ocena.
    int kap, n;                           // Kapacitet niza i broj ocena.
public:                                 // Stvaranje objekta.
    Student(string ime, int god, int k=20): Osoba(ime, god)
    {
        ocene = new int [kap = k];
        n = 0;
    }
    ~Student()
    {
        delete [] ocene;    // Unistavanje objekta.
    }
    Student& operator+=(int oc)           // Dodavanje ocene.
    {
        if (n == kap)
            exit(1);
        ocene[n++] = oc;
        return *this;
    }
    int jos() const
    {
        return kap - n;    // Broj slobodnih mesta.
    }
    double sr_ocena() const;              // Srednja ocena.
private:
    void pisi(ostream& it) const override // Pisanje studenta.
    {
        Osoba::pisi(it);
        it << '/' << sr_ocena();
    }
};

double Student::sr_ocena() const        // Srednja ocena.
{
    double s = 0;
    int k = 0;
    for (int i=0; i<n; i++)
        if (ocene[i] > 5)
        {
            s += ocene[i];
            k++;
        }
    if (k)
        s /= k;
    return s;
}

#endif // STUDENT_HPP_INCLUDED
