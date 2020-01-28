#include <iostream>
using namespace std;

#include "FUZIJA.hpp"
#include "PRAVOUGAONIK.hpp"
#include "TACKA.hpp"

int main()
{
    int na, nb, nc, i;

    {
        cout << "\n---------------------- <int> ----------------------\n";
        cout << endl << "Unos dimenzije za prvi niz: ";
        cin >> na;

        int* a = new int [na];

        cout << "Unos elemenata prvog niza: ";
        for (i = 0; i < na; i++)
            cin >> a[i];

        cout << endl << "\nUnos dimenzije za drugi niz: ";
        cin >> nb;

        int* b = new int [nb];

        cout << "Unos elemenata drugog niza: ";
        for (i = 0; i < nb; i++)
            cin >> b[i];

        int* c;

        fuzija <int> (a, na, b, nb, c, nc);

        cout << endl << "Fuzija: \n";
        for (i = 0; i < nc; i++)
            cout << " " << c[i];

        delete [] a;
        delete [] b;
        delete [] c;

        cout << "\n---------------------- <int> ----------------------\n";
    }

    {
        cout << "\n\n\n\n---------------------- <Tacka> --------------------\n";
        cout << endl << "Unos dimenzije za prvi niz: ";
        cin >> na;

        Tacka* a = new Tacka [na];

        cout << "Unos elemenata prvog niza: ";
        for (i = 0; i < na; i++)
            cin >> a[i];

        cout << endl << "\nUnos dimenzije za drugi niz: ";
        cin >> nb;

        Tacka* b = new Tacka [nb];

        cout << "Unos elemenata drugog niza: ";
        for (i = 0; i < nb; i++)
            cin >> b[i];

        Tacka* c;

        fuzija <Tacka> (a, na, b, nb, c, nc);

        cout << endl << "Fuzija: \n";
        for (i = 0; i < nc; i++)
            cout << " " << c[i];

        delete [] a;
        delete [] b;
        delete [] c;

        cout << "\n---------------------- <Tacka> ---------------------\n";
    }

    {
        cout << "\n\n\n\n----------------- <Pravougaonik> -----------------\n";
        cout << endl << "Unos dimenzije za prvi niz: ";
        cin >> na;

        Pravougaonik* a = new Pravougaonik [na];

        cout << "Unos elemenata prvog niza: ";
        for (i = 0; i < na; i++)
            cin >> a[i];

        cout << endl << "\nUnos dimenzije za drugi niz: ";
        cin >> nb;

        Pravougaonik* b = new Pravougaonik [nb];

        cout << "Unos elemenata drugog niza: ";
        for (i = 0; i < nb; i++)
            cin >> b[i];

        Pravougaonik* c;

        fuzija <Pravougaonik> (a, na, b, nb, c, nc);

        cout << endl << "Fuzija: \n";
        for (i = 0; i < nc; i++)
            cout << " " << c[i];

        delete [] a;
        delete [] b;
        delete [] c;

        cout << "\n------------------- <Pravougaonik> -----------------\n";
    }

    return 0;
}
