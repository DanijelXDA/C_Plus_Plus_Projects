#ifndef KOCKA_HPP_INCLUDED
#define KOCKA_HPP_INCLUDED

#include <iostream>
#include <cmath>
using namespace std;

class Kocka {
    private:
        double a;
    public:
        Kocka();
        Kocka(double);
        Kocka(const Kocka &);
        void setA(double);
        double zapreminaKocke();
        double povrsinaKocke();
        double povrsinaStraniceKocke();
        double obimStraniceKocke();
        double dijagonalaStraniceKocke();
        void prikazi();

};

#endif // KOCKA_HPP_INCLUDED
