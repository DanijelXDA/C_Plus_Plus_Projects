#ifndef VALJAK_HPP_INCLUDED
#define VALJAK_HPP_INCLUDED

#include <iostream>
using namespace std;

struct Polja {
    double *r, *H;
};

class Valjak
{
    private:
        Polja polje;
    public:
        Valjak();
        Valjak(double, double);
        Valjak(const Valjak &);
        ~Valjak();
        bool setR(double);
        bool setH(double);
        double getR()const;
        double getH()const;
        double povrsina()const;
        double zapremina()const;

        // redefinisanje operatora
        Valjak& operator=(const Valjak &);
        Valjak& operator+=(const Valjak &);

        Valjak& operator++();
        Valjak operator++(int); // postfiksni

        friend Valjak operator+(const Valjak &, const Valjak &);

        friend ostream& operator<<(ostream &, const Valjak &);
};

#endif // VALJAK_HPP_INCLUDED
