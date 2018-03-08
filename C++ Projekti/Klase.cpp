#include<iostream>
#include<string>

using namespace std;

class mojaKlasa
 {
    public:
        void podesiIme(string x)
        {
            ime = x;
        }
        string prikaziIme()
        {
            return ime;
        }
    private:
        string ime;
 };

 int main(void)
 {
    mojaKlasa klasa;

    klasa.podesiIme("Inicijalizovano ime....");

    cout << klasa.prikaziIme() << endl;

    return 0;
 }
