#include "../Headers/Logovanje.hpp"

Logovanje::Logovanje() {
    username = "EMPTY";
    password = "EMPTY";
}

void Logovanje::ulogujSe() {
    cout << "********************************************************************************" << endl;
    cout << "\t\t     PRISTUPATE ZASTICENOM DELU SISTEMA!!  " << endl;
    cout << "\t\t     Za nastavak potrebno je da se ulogujete..." << endl << endl;
    cout << "********************************************************************************" << endl;

    int pokusaji = 1;

    do {
        cout << "Korisnicko ime: ";
        cin >> username;

        cout << "Lozinka: ";
        cin >> password;

        if( proveraKredetiala(username, password) ) {
            this -> username = username;
            this -> password = password;

            prikaziMeni(); // Meni
        } else {
            cout << endl << "Pogresno korisnicko ime i/ili lozinka!!!" << endl << endl;
            pokusaji++;
        }
    } while(pokusaji <= 3);

    return;

}


bool Logovanje::proveraKredetiala(string username, string password) {
    if(username == "Danijel" && password == "12345") {
        cout << endl << "\t\t\tPrijava na sistem uspesna!" << endl << endl;
        system("cls");
        return true;
    } else {
        cout << endl << "\t\t\tPrijava na sistem neuspesna!" << endl << endl;
        return false;
    }
}
