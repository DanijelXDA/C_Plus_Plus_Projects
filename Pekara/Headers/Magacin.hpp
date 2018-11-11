#ifndef MAGACIN_HPP_INCLUDED
#define MAGACIN_HPP_INCLUDED

#include "Logovanje.hpp"
#include "Proizvodi.hpp"
#include <string>

class Magacin
{
    protected:
        int ID[100];
        string imeSirovine[100];
        float kolicinaSirovine[100]; // Za sto elemenata
        string jedinicaMere[100];
        bool naStanju;
    public:
        Magacin();
        bool proveraStanjaUMagacinu();
        void sadrzajMagacina();
        void dodavanjeUMagacin();
        void izbacivanjeIzMagacina();
        void azuriranjeSirovine();
        bool upisUMagacinTXT();
        bool citanjeUMagacinTXT();
};

#endif // MAGACIN_HPP_INCLUDED
