#include "Imenik.hpp"

int main(void)
{
    Imenik imen;
    while (true)
    {
        cout << "Vrsta (O, S, .)? ";
        char vrs;
        cin >> vrs;
        if (vrs == '.')
            break;
        cout << "Ime? ";
        string ime;
        cin >> ime;
        cout << "Godine? ";
        int god;
        cin >> god;
        if (vrs == 'o')
            imen +=  new Osoba(ime, god);
        else
        {
            Student* stud = new Student(ime, god);
            while (true)
            {
                cout << "Ocena? ";
                int oce;
                cin >> oce;
                if (oce == 0)
                    break;
                *stud += oce;
            }
            imen += stud;
        }
    }
    cout << endl << imen.uredi();
}
