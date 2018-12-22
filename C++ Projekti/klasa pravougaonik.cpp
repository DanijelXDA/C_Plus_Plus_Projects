#include <iostream>
using namespace std;

class Pravougaonik {
    private:
        int a, b;
    public:
        Pravougaonik();
        Pravougaonik(int, int);
        Pravougaonik(const Pravougaonik &);
        int duzina();
        int sirina();
        void postaviVrednosti(int, int);
        int povrsina();
        int obim();
};

Pravougaonik::Pravougaonik() { a = 1; b = 2; }
Pravougaonik::Pravougaonik(int x, int y) { a = x; b = y; }
Pravougaonik::Pravougaonik(const Pravougaonik &p) { a = p.a; b = p.b; }
int Pravougaonik::duzina() { return a; }
int Pravougaonik::sirina() { return b; }
void Pravougaonik::postaviVrednosti(int x, int y) { a = x; b = y; }
int Pravougaonik::povrsina() { return a * b; }
int Pravougaonik::obim() { return 2 * (a + b); }


void ispisi(Pravougaonik &p)
{
    cout << "a = " << p.duzina() << ", b = " << p.sirina() << endl;
    cout << "Povrsina = " << p.povrsina() << ", Obim = " << p.obim() << endl;
}


int main(void)
{
    Pravougaonik p1;
    Pravougaonik p2(5, 2);
    Pravougaonik p3(p2);

    cout << "p1:" << endl;
    ispisi(p1);

    cout << "p2:" << endl;
    ispisi(p2);

    cout << "p3:" << endl;
    ispisi(p3);

    return 0;
}
