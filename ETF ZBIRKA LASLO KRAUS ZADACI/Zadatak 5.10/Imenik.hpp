#ifndef IMENIK_HPP_INCLUDED
#define IMENIK_HPP_INCLUDED

#include "Student.hpp"

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

#endif // IMENIK_HPP_INCLUDED
