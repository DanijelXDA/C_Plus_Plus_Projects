#ifndef PROIZVODI_HPP_INCLUDED
#define PROIZVODI_HPP_INCLUDED

#include "Magacin.hpp"

class Proizvodi {
    private:
        int ID[100];
        string imeProizvoda[100];
        string tipSirovinePotrebneZaProizvod[100][20]; // maksimum 20 sirovina za svaki proizvod ponaosob; MAX je 100 proizvoda
        float kolicinaSirovinePotrebneZaProizvod[100][20];
    public:
        Proizvodi();
        void dodavanjeProizvoda();
        bool upisProizvodiTXT();
};

#endif // PROIZVODI_HPP_INCLUDED
