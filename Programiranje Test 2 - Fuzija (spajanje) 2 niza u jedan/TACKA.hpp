#ifndef TACKA_HPP_INCLUDED
#define TACKA_HPP_INCLUDED

#include <cmath>

class Tacka {
    private:
        double x, y;
    public:
        friend istream& operator >>(istream &ulaz, Tacka &t)
        {
            return ulaz >> t.x >> t.y;
        }
        friend ostream& operator <<(ostream &out, const Tacka &t)
        {
            return out << "T[" << t.x << ", " << t.y << "]" << endl;
        }
        friend int operator <(const Tacka &t1, const Tacka &t2)
        {
            return ( pow(t1.x, 2) + pow(t1.y, 2) ) < ( pow(t2.x, 2) + pow(t2.y, 2) );
        }
};


#endif // TACKA_HPP_INCLUDED
