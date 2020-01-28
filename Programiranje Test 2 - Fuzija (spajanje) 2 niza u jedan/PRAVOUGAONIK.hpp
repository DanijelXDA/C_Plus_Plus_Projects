#ifndef PRAVOUGAONIK_HPP_INCLUDED
#define PRAVOUGAONIK_HPP_INCLUDED

class Pravougaonik {
    private:
        double a, b;
    public:
        friend istream& operator >>(istream &ulaz, Pravougaonik &p)
        {
            return ulaz >> p.a >> p.b;
        }
        friend ostream& operator <<(ostream &out, const Pravougaonik &p)
        {
            return out << "P[" << p.a << ", " << p.b << "]" << endl;
        }
        friend int operator <(const Pravougaonik &p1, const Pravougaonik &p2)
        {
            return (p1.a * p1.b) < (p2.a * p2.b);
        }
};

#endif // PRAVOUGAONIK_HPP_INCLUDED
