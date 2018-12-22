#include <iostream>
using namespace std;

class Krug {
    private:
        double r;
        static int instanci;
    public:
        Krug() {
            r = 1;
            instanci++;
        }
        Krug(double r) {
            this -> r = r;
            instanci++;
        }
        Krug(const Krug &k) {
            r = k.r;
            instanci++;
        }
        ~Krug() {
            instanci--;
        }
        double getR()const { return r; }
        int getInstanci()const { return instanci; }
        double povrsina()const { return r * r * 3.14159; }
        double obim()const { return 2 * r * 3.14159; }
};

void prikazi(const Krug &k) {
    cout << "\tr = " << k.getR() << endl;
    cout << "\tO = " << k.obim() << endl;
    cout << "\tP = " << k.povrsina() << endl;
    cout << "\tInstanci = " << k.getInstanci() << endl;

    return;
}

int Krug::instanci = 0;

int main(void)
{

    Krug k1;
    cout << "k1: " << endl;
    prikazi(k1);

    Krug k2(5);
    cout << endl << endl << "k2: " << endl;
    prikazi(k2);

    Krug k3(k2);
    cout << endl << endl << "k3: " << endl;
    prikazi(k3);


    return 0;
}
