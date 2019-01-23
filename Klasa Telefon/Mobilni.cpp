#include "Mobilni.hpp"

Mobilni::Mobilni(int prostor, double dopuna){
    if(prostor < 0){
        memorija = 0;
    }else{
        memorija = prostor;
    }

    if(dopuna < 0){
        kredit = 0;
    }else{
        kredit = dopuna;
    }

    // Moze se napisati i upotrebom ternarnog operatora   ? :
    // (prostor < 0) ? memorija = 0 : memorija = prostor;
    // (dopuna < 0) ? kredit = 0 : memorija = kredit;

    poruke = new Poruka*[memorija]; // dinamicka alokacija za prvu dimenziju, niz memorijskih adresa na kojima se nalaze sadrzaji tipa strukture Poruka
    for(int i = 0; i < memorija; ++i){
        poruke[i] = NULL;
    }
}

Mobilni::~Mobilni(){
    for(int i = 0; i < memorija; ++i){
        delete poruke[i] ;
        poruke[i] = NULL;
    }
    delete[] poruke;
    poruke = NULL;
}

int Mobilni::kapacitet()const{
    return memorija;
}

int Mobilni::prostor()const{
    int br = 0;
    for(int i = 0; i < memorija; ++i){
        if(poruke[i] == NULL){
            ++br;
        }
    }
    return br;
}

int Mobilni::zauzeto()const{
    int br = 0;
    for(int i = 0; i < memorija; ++i){
        if(poruke[i] != NULL){
            ++br;
        }
    }
    return br;
}

bool Mobilni::dopunaKredita(double iznosDopune){
    bool uspesno = false;
    if(kredit + iznosDopune >= 0){ // ne sme se dozvoliti odlazak u minus
        kredit += iznosDopune;
        uspesno = true;
    }

    return uspesno;
}

bool Mobilni::dodajSms(string brojPrimaioca, string tekstPoruke){
    bool uspesno = false;
    if(prostor() <= kapacitet()){
        for(int i = 0; i < memorija; ++i){ // moze i kapacitet(), skuplja operacija
            if(poruke[i] == NULL){
                poruke[i] = new Poruka;
                Poruka temp = {brojPrimaioca, tekstPoruke, false};
                *poruke[i] = temp;
                uspesno = true;
                break;
            }
        }
    }
    return uspesno;
}

bool Mobilni::dodajSms(Poruka novaPoruka){
    bool uspesno = false;
    if(prostor() <= kapacitet()){
        for(int i = 0; i < memorija; ++i){ // moze i kapacitet(), skuplja operacija
            if(poruke[i] == NULL){
                poruke[i] = new Poruka;
                *poruke[i] = novaPoruka;
                uspesno = true;
                break;
            }
        }
    }
    return uspesno;
}

bool Mobilni::obrisiSms(){
    bool uspesno = false;
        for(int i = 0; i < memorija; ++i){
            if(poruke[i] != NULL){
                delete poruke[i];
                poruke[i] = NULL;
                uspesno = true;
            }
        }
    return uspesno;
}

bool Mobilni::obrisiSms(string brojPrimaoca){
    bool uspesno = false;
        for(int i = 0; i < memorija; ++i){
            if(poruke[i] != NULL && poruke[i] -> broj == brojPrimaoca){
                delete poruke[i];
                poruke[i] = NULL;
                uspesno = true;
            }
        }
    return uspesno;
}

bool Mobilni::obrisiSms(string brojPrimaoca, string tekstPoruke){
    bool uspesno = false;
    for(int i = 0; i < memorija; ++i){
        if((poruke[i] != NULL) && (poruke[i] -> broj == brojPrimaoca) && (poruke[i] -> tekst == tekstPoruke)){
            delete poruke[i];
            poruke[i] = NULL;
            uspesno = true;
            break;
        }
    }
    return uspesno;
}

bool Mobilni::azurirajSms(string brojPrimaoca, string noviTekst){
    bool uspesno = false;
    for(int i = 0; i < memorija; ++i){
        if((poruke[i] != NULL) && (poruke[i] -> broj == brojPrimaoca)){
            Poruka *temp = poruke[i];
            temp -> tekst = noviTekst;
            uspesno = true;
        }
    }
    return uspesno;
}


bool Mobilni::azurirajSms(string brojPrimaoca, string stariTekst, string noviTekst){
    bool uspesno = false;
    for(int i = 0; i < memorija; ++i){
        if((poruke[i] != NULL) && (poruke[i] -> broj == brojPrimaoca) && (poruke[i] -> tekst == stariTekst)){
            Poruka *temp = poruke[i];
            temp -> tekst = noviTekst;
            uspesno = true;
            break;
        }
    }
    return uspesno;
}

bool Mobilni::posaljiSms(){
    bool uspesno = false;
    if(zauzeto() > 0){
        int br = 0;
        for(int i = 0; i < memorija; ++i){
            if((poruke[i] != NULL) && (poruke[i] -> poslata == false) ){
                ++br;
            }
        }
        if(kredit >= (br * CENA_SMS)){
            kredit -= (br * CENA_SMS);
            for(int i = 0; i < memorija; ++i){
                if((poruke[i] != NULL) && (poruke[i] -> poslata == false) ){
                    Poruka *temp = poruke[i];
                    temp -> poslata = true;
                    uspesno = true;
                }
            }
        }
    }
    return uspesno;
}

bool Mobilni::posaljiSMs(string brojPrimaoca){
    bool uspesno = false;
    if(zauzeto() > 0){
        int br = 0;
        for(int i = 0; i < memorija; ++i){
            if((poruke[i] != NULL)&& (poruke[i] -> broj == brojPrimaoca)  && (poruke[i] -> poslata == false) ){
                ++br;
            }
        }
        if(kredit >= (br * CENA_SMS)){
            kredit -= (br * CENA_SMS);
            for(int i = 0; i < memorija; ++i){
                if((poruke[i] != NULL)&& (poruke[i] -> broj == brojPrimaoca)  && (poruke[i] -> poslata == false) ){
                    Poruka *temp = poruke[i];
                    temp -> poslata = true;
                    uspesno = true;
                }
            }
        }
    }

    for(int i = 0; i < memorija; ++i){
        if((poruke[i] != NULL) && (poruke[i] -> broj == brojPrimaoca) && (poruke[i] -> poslata == false) ){
            Poruka *temp = poruke[i];
            temp -> poslata = true;
            uspesno = true;
        }
    }
    return uspesno;
}

ostream& operator<<(ostream &out, const Mobilni &mobilniTelefon){
    out << "     Kredit: " << mobilniTelefon.kredit << "rsd" << endl;
    out << "   Memorija: " << mobilniTelefon.memorija << endl;
    out << "Iskorisceno: " << mobilniTelefon.zauzeto() << endl;
    out << "     Poruke:  " << endl;
    if(mobilniTelefon.zauzeto() > 0){
        for(int i = 0, br = 1; i < mobilniTelefon.memorija; ++i){
            if(mobilniTelefon.poruke[i] != NULL){
                out << "              " << br++ << "." << endl;
                out << "              " << "   Broj: " << mobilniTelefon.poruke[i] -> broj << endl;
                out << "              " << "  Tekst: " << mobilniTelefon.poruke[i] -> tekst << endl;
                out << "              " << "Poslata: " << ((mobilniTelefon.poruke[i] -> poslata) ? "DA" : "NE") << endl;
            }
        }
    }else{
        out << "              \t ****** NEMA PORUKA ****** ";
    }
    out << endl;
    return out;
}
