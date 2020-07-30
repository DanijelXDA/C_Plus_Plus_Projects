#ifndef KOSARKAS_HPP_INCLUDED
#define KOSARKAS_HPP_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DUZINA_IME 20
#define DIMENZIJA 1000

struct Kosarkas
{
    int sifra;
    char ime[DUZINA_IME];
    char prezime[DUZINA_IME];
    char klub[DUZINA_IME];
    int brojPoena;
    int brojUtakmica;

};

typedef struct Kosarkas Tkosarkas;


int Meni();
void dodajKosarkasaUTim(Tkosarkas [], int *);
void dodajBrojPoenaKosarkasu(Tkosarkas [], int);
void ispisKosarkasaZadatiTim(Tkosarkas [], int);
void spisakSortiranihKosarkasaPoBrojuPoena(Tkosarkas [], int);

// DATOTEKE
int ucitajFajl(FILE *, Tkosarkas []);
void sacuvajFajl(FILE *, Tkosarkas [], int);




#endif // KOSARKAS_HPP_INCLUDED
