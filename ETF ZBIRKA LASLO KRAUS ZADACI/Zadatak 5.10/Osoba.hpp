#ifndef OSOBA_HPP_INCLUDED
#define OSOBA_HPP_INCLUDED

class Osoba
{
    private:
        string ime;
        unsigned godine;
    public:
        Osoba()
        {
            ime = "";
            godine = 0;
        }
        Osoba(string i, int j)
        {
            ime = i;
            godine  = j;
        }
        string getIme() { return ime; }
        unsigned getGodine() { return godine; }
        void setIme(string i) { ime = i; }
        void setGodine(int g) { godine  = g; }

        void operator >(const Osoba& o)
        {
            if(godine > o.godine)
            {
                cout << "Osoba " << ime << "(" << godine << ") je starija od "
                     << "Osobe " << o.ime << "(" << o.godine << ")" << endl;
            }
            else
            {
                cout << "Osoba " << o.ime << "(" << o.godine << ") je starija od "
                     << "Osobe " << ime << "(" << godine << ")" << endl;
            }
        }

        friend ostream &operator<<( ostream &out, const Osoba &o)
        {
            /// ISPIS
            cout << o.ime << " (" << o.godine << ")" << endl;

            return out;
        }
};

#endif // OSOBA_HPP_INCLUDED
