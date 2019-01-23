#ifndef MOBILNI_HPP_INCLUDED
#define MOBILNI_HPP_INCLUDED

#include <iostream>
using namespace std;

#define CENA_SMS 2.54

struct Poruka
{
    string broj, tekst;
    bool poslata;
};

class Mobilni
{
private:
    int memorija;
    double kredit;
    Poruka **poruka;
public:
    Mobilni(int, double);
    ~Mobilni();
    int kapacitet()const;
    int prostor()const;
    int zauzeto()const;
    bool dopunaKredita(double);
    bool dodajSms(string, string);
    bool dodajSms(Poruka);
    bool obrisiSms(string);
    bool obrisiSms();
    bool obrisiSms(string, string);
    bool azurirajSms(string, string);
    bool azurirajSms(string, string, string);
    bool posaljiSms();
    bool posaljiSms(string);
    friend ostream& operator<<(ostream &, const Mobilni &);

};

#endif // MOBILNI_HPP_INCLUDED
