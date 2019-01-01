/*
Napisati klasu Kocka koja ce da ima jedno polje tipa double koje predstavlja ivicu kocke,
zatim definisati sledece metode: Prazan konstruktor, konstruktor sa parametrima, konstruktor kopije,
metodu koju menja vrednost ivice kocke, metodu koja racuna povrsinu kocke, metodu koja racuna zapreminu kocke,
metodu koja racuna obim jedne stranice kocke (kocka je sastavljenja od 6 kvadrata),
metodu koja racuna povrsinu jedne stranice kocke, metodu koja racuna dijagonalu jedne stranice kocke,
i metodu koja prikazuje za datu ivicu kocke koliko iznosi Obim, povrsina, zapremina, obim jedne stranice kocke,
povrsinu jedne stranice kocke, i dijagonalu jedne stranice kocke.
*/

#include "Kocka.hpp"

int main()
{
    // cout << "Shutting down..." << endl;
    Kocka k1;
    Kocka k2(3.5);
    Kocka k3(k2);

    cout << endl << endl << "KOCKA K1" << endl;
    k1.prikazi();

    cout << endl << endl << "KOCKA K2" << endl;
    k2.prikazi();

    cout << endl << endl << "KOCKA K3" << endl;
    k3.prikazi();

    return 0;
}
