/* Autor: Danijel Jovanović, Problem: Tuča topova */

#include <iostream>
using namespace std;

int main(void)
{
    string unos;

    cout << "Unesite pozicije 8 topova: ";
    getline(cin, unos);

    if(unos.size() < 23)
    {
        cout << endl << "Uneli ste manje od 8 topova!" << endl;
        return -1;
    }
    else if(unos.size() > 23)
    {
        cout << endl << "Uneli ste vise od 8 topova!" << endl;
        return -1;
    }
    else
    {
        int tabla[8][8] = {0};

        cout << endl << "Uneli ste 8 topova!" << endl << endl << endl;
        cout << "Proveravanje da li se topovi \"tuku\"..." << endl;

        for(unsigned int i = 0; i < unos.size(); i += 3)
        {
            int tmp = unos[i + 1] - '0';

            switch(unos[i])
            {
                case 'a':
                    tabla[tmp - 1][0] = 1;
                    break;
                case 'b':
                    tabla[tmp - 1][1] = 1;
                    break;
                case 'c':
                    tabla[tmp - 1][2] = 1;
                    break;
                case 'd':
                    tabla[tmp - 1][3] = 1;
                    break;
                case 'e':
                    tabla[tmp - 1][4] = 1;
                    break;
                case 'f':
                    tabla[tmp - 1][5] = 1;
                    break;
                case 'g':
                    tabla[tmp - 1][6] = 1;
                    break;
                case 'h':
                    tabla[tmp - 1][7] = 1;
                    break;
            }
        }

        cout << endl << endl << "Prikaz table: " << endl << endl;

        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(tabla[i][j] == 1)
                    cout << " T ";
                else
                    cout << " X ";
            }
            cout << endl;
        }

        int suma[8] = {0}, ukupno = 0;
        int sumaK[8] = {0}, ukupnoK = 0;

        for(int i = 0; i < 8; i++) // da li se tuku po vrsti
            for(int j = 0; j < 8; j++)
                if(tabla[i][j] == 1)
                {
                    suma[i] += 1;
                    ukupno++;
                }
        for(int i = 0; i < 8; i++) // da li se tuku po koloni
            for(int j = 0; j < 8; j++)
                if(tabla[j][i] == 1)
                {
                    sumaK[i] += 1;
                    ukupnoK++;
                }

        if(ukupno == 8)
        {
            bool tukuSe = false;

            for(int i = 0; i < 8; i++)
                if(suma[i] > 1)
                {
                    tukuSe = true;
                    break;
                }

                // po koloni
                for(int i = 0; i < 8; i++)
                if(sumaK[i] > 1)
                {
                    tukuSe = true;
                    break;
                }

            if(tukuSe)
            {
                cout << endl << "Topovi se TUKU!" << endl << endl;
                return -2;
            }
            else
            {
                cout << endl << "Topovi se NE TUKU!" << endl << endl;
                return -2;
            }
        }
        else
            cout << endl << "Niste uneli razlicite pozicije topova!" << endl << endl;
    }

    return 0;
}
