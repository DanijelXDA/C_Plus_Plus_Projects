#include <iostream>
using namespace std;

class Trougao {
    private:
        int a;
    public:
        Trougao() { a = 1; }
        Trougao(int x) { a = x; }
        Trougao(const Trougao &t) { a = t.a; }
        int stranicaTrougla() { return a; }
        int obim() { return 3 * a; }
        int povrsina() { (a * a * 1.73) / 4; }
        int visina() { return (a * 1.73) / 2; }
};

void ispisi(Trougao &t) { cout << "a = " << t.stranicaTrougla() << endl
                               << "Povrsina: " << t.povrsina() << ", Obim = " << t.obim()
                               << ", Visina = " << t.visina() << endl << endl;
                        }

int main(void)
{
    Trougao t1;
    Trougao t2(5);
    Trougao t3(t2);

    ispisi(t1);
    ispisi(t2);
    ispisi(t3);

    return 0;
}
