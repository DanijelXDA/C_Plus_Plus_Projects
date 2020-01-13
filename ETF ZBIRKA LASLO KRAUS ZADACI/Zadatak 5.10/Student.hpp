#ifndef STUDENT_HPP_INCLUDED
#define STUDENT_HPP_INCLUDED

class Student : public Osoba
{
    private:
        float ocene;
        int polozeno;
    public:
        Student() : Osoba()
        {
            polozeno = 1;
            ocene = 0.0;
        }
        Student(string i, int g) : Osoba(i, g)
        {
            polozeno = 1;
            ocene = 0.0;
        }
        Student& operator+=(const float oc)
        {
            if(polozeno <= MAX_ISPITA) {
                this -> ocene = ( this -> ocene + oc);
                polozeno++;
            }
            else {
                cout << endl << "POPUNJENA MESTA ZA SVE OCENE! (" << MAX_ISPITA << ")" << endl;
            }

            return *this;
        }
        int slobodnoOcena()
        {
            return (MAX_ISPITA - polozeno);
        }
        float avgOcene() { return ocene / (polozeno - 1); }

        friend ostream &operator<<(ostream &out, Student &s)
        {
            /// ISPIS
            cout << s.getIme() << " (" << s.getGodine() << ") / " << s.avgOcene() << endl;

            return out;
        }
};

#endif // STUDENT_HPP_INCLUDED
