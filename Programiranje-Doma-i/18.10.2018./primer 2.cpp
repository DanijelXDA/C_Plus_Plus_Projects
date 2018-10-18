#include <iostream>
using namespace std;

class Broj {
    private:
        int broj1, broj2, broj3;
    public:
        void unosBrojeva()
        {
            int b1, b2, b3;

            cout << "Unesite 1. broj: ";
            cin >> b1;
            broj1 = b1;

            cout << "Unesite 2. broj: ";
            cin >> b2;
            broj2 = b2;

            cout << "Unesite 3. broj: ";
            cin >> b3;
            broj3 = b3;

            return;
        }
        int najmanjiOdTriBrojaV1()
        {
            int b1 = broj1, b2 = broj2, b3 = broj3;

            int minimum;

            if(b1 < b2)
                minimum = b1;
            else
                minimum = b2;

            if(b3 < minimum)
                minimum = b3;

            return minimum;
        }
        int najmanjiOdTriBrojaV2()
        {
            int b1 = broj1, b2 = broj2, b3 = broj3;
            int m;

            return ( m = (b1 < b2) ? b1 : b2 ) < b3 ? m : b3;
        }

};

int main(void)
{
    Broj b;

    b.unosBrojeva();

    cout << endl << "Najmanji broj je: " << b.najmanjiOdTriBrojaV1();
    cout << endl << "Najmanji broj je: " << b.najmanjiOdTriBrojaV2();

    return 0;
}
