#include "Mobilni.hpp"

Mobilni::Mobilni(int prostor, double dopuna)
{
    if(prostor < 0)
        memorija = 0;
    else
        memorija = prostor;

    if(dopuna < 0)
        kredit = 0;
    else
        kredit = dopuna;

    poruka = new Poruka*[memorija];

    for(int i = 0; i < memorija; i++)
        poruka[i] = NULL;
}

Mobilni::~Mobilni()
{
    for(int i = 0; i < memorija; i++)
    {   delete poruka[i];
        poruka[i] = NULL;
    }

    delete[] poruka;
    poruka = NULL;
}

int Mobilni::kapacitet()const
{
    return memorija;
}

int Mobilni::prostor()const
{
    int br = 0;

    for(int i = 0; i < memorija; i++)
        if(poruka[i] == NULL)
            ++br;

    return br;
}

int Mobilni::zauzeto()const
{
    return kapacitet() - prostor();
}

bool Mobilni::dopunaKredita(double iznosDopune)
{
    bool uspesno = false;

    if(kredit + iznosDopune >= 0)
    {
        kredit += iznosDopune;
        uspesno = true;
    }

    return uspesno;
}

bool Mobilni::dodajSms(string brojPrimaoca, string tekstPoruke)
{
    bool uspesno = false;

    if(prostor() < kapacitet())
        for(int i = 0; i < memorija; i++)
            if(poruka[i] == NULL)
            {
                poruka[i] = new Poruka;
                Poruka temp = {brojPrimaoca, tekstPoruke, false};
                *poruka[i] = temp;
                uspesno = true;
                break;
            }
    return uspesno;
}

bool Mobilni::dodajSms(Poruka novaPoruka)
{
    bool uspesno = false;

    if(prostor() <= kapacitet())
        for(int i = 0; i < memorija; i++)
            if(poruka[i] == NULL)
            {
                poruka[i] = new Poruka;
                *poruka[i] = novaPoruka;
                uspesno = true;
                break;
            }
    return uspesno;
}


bool Mobilni::obrisiSms()
{
    bool uspesno = false;

    for(int i = 0; i < memorija; i++)
        if(poruka[i] != NULL)
        {
            delete poruka[i];
            poruka[i] = NULL;
            uspesno = true;
        }
    return uspesno;
}

bool Mobilni::obrisiSms(string brojPrimaoca)
{
    bool uspesno = false;

    for(int i = 0; i < memorija; i++)
        if(poruka[i] != NULL && poruka[i] -> broj == brojPrimaoca)
        {
            delete poruka[i];
            poruka[i] = NULL;

            uspesno = true;
        }
    return uspesno;
}

bool Mobilni::obrisiSms(string brojPrimaoca, string tekstPoruke)
{
    bool uspesno = false;

    for(int i = 0; i < memorija; i++)
        if(poruka[i] != NULL && poruka[i] -> broj == brojPrimaoca && poruka[i] -> tekst == tekstPoruke)
        {
            delete poruka[i];
            poruka[i] = NULL;

            uspesno = true;
        }
    return uspesno;
}

bool Mobilni::azurirajSms(string brojPrimaoca, string noviTekst)
{
    bool uspesno = false;

    for(int i = 0; i < memorija; i++)
        if( (poruka[i] != NULL) && (poruka[i] -> broj == brojPrimaoca) )
        {
            poruka[i] -> tekst = noviTekst;
            uspesno = true;
        }
        return uspesno;
}

bool Mobilni::azurirajSms(string brojPrimaoca, string stariTekst, string noviTekst)
{
    bool uspesno = false;

    for(int i = 0; i < memorija; i++)
        if( (poruka[i] != NULL) && (poruka[i] -> broj == brojPrimaoca) && (poruka[i] -> tekst == stariTekst) )
        {
            poruka[i] -> tekst = noviTekst;
            uspesno = true;
        }
        return uspesno;
}

bool Mobilni::posaljiSms()
{
    bool uspesno = false;

    if(zauzeto() > 0)
    {
        int br = 0;

        for(int i = 0; i < memorija; i++)
        {
            if( (poruka[i] != NULL) && (poruka[i] -> poslata == true) )
            {
                ++br;
            }
        }

        if(kredit >= (br * CENA_SMS))
        {
            kredit -= (br * CENA_SMS);

            for(int i = 0; i < memorija; i++)
                if( (poruka[i] != NULL) && (poruka[i] -> poslata == false) )
                {
                    poruka[i] -> poslata = true;
                    uspesno = true;
                }
        }
    }

    return uspesno;
}
