#include "Valjak.hpp"

Valjak::Valjak()
{
    polje.r = new double(1);
    polje.H = new double(2);
}

Valjak::Valjak(double r, double H)
{
    polje.r = new double(r);
    polje.H = new double(H);
}

Valjak::Valjak(const Valjak &v)
{
    polje.r = new double(*v.polje.r);
    polje.H = new double(*v.polje.H);
}

Valjak::~Valjak()
{
    delete polje.r;
    delete polje.H;
}

bool Valjak::setR(double r)
{
    bool uspesno = false;

    if(r > 0)
    {
        *polje.r = r;
        uspesno = true;
    }
    return uspesno;
}
bool Valjak::setH(double H)
{
    bool uspesno = false;

    if(H > 0)
    {
        *polje.H = H;
        uspesno = true;
    }
    return uspesno;
}

double Valjak::getR()const { return *polje.r; }

double Valjak::getH()const { return *polje.H; }

double Valjak::povrsina()const { return 2.0 * (*polje.r) * 3.14 * ( (*polje.r) + (*polje.H) ); }

double Valjak::zapremina()const { return ((*polje.r) * (*polje.r) * 3.14 * (*polje.H) ); }


Valjak& Valjak::operator=(const Valjak &v)
{
    *polje.r = (*v.polje.r);
    *polje.H = (*v.polje.H);

    return *this;
}

Valjak& Valjak::operator+=(const Valjak &v)
{
    *polje.r += (*v.polje.r);
    *polje.H += (*v.polje.H);

    return *this;
}

Valjak& Valjak::operator++()
{
    ++(*polje.r);
    ++(*polje.H);

    return *this;
}

Valjak Valjak::operator++(int i)
{
    Valjak temp(*polje.r, *polje.H);

    ++(*polje.r);
    ++(*polje.H);

    return temp;
}

Valjak operator+(const Valjak &v1, const Valjak &v2)
{
    Valjak temp( (*v1.polje.r) + (*v2.polje.r),(*v1.polje.H) + (*v2.polje.H) );

    return temp;
}

ostream& operator<<(ostream &out, const Valjak &v)
{
    out << "r: " << *v.polje.r << ", H: " << *v.polje.H
        << ", povrsina: " << v.povrsina() << ", zapremina: " << v.zapremina() << endl;

        return out;
}
