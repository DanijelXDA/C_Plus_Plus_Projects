#ifndef LOGOVANJE_HPP_INCLUDED
#define LOGOVANJE_HPP_INCLUDED

#include <iostream>
using namespace std;
#include "Meni.hpp"

class Logovanje {
    private:
        string username;
        string password;
    public:
        Logovanje();
        void ulogujSe();
        bool proveraKredetiala(string, string);
};

#endif // LOGOVANJE_HPP_INCLUDED
