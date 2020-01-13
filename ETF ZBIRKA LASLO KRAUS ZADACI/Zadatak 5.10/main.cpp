#include <iostream>
using namespace std;

#include "Osoba.hpp"
#include "Student.hpp"
#include "Imenik.hpp"

#define MAX_ISPITA 20



class Imenik : Osoba
{
    private: unsigned kapacitet;
    public:
    Imenik() { kapacitet = 0; }
    /*Imenik& operator+=(const Osoba &o)
    {
        if(kapacitet < 10) {
            this -> ocene = ( this -> ocene + oc);
            kapacitet++;
        }
        else {
            cout << endl << "POPUNJENA MESTA ZA SVE OCENE! (" << MAX_ISPITA << ")" << endl;
        }

        return *this;

    } */
};

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
