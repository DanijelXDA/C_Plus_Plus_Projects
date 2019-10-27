#include <stdio.h>

typedef struct cvor* PCVOR;

typedef struct cvor
{
    int info;
    PCVOR sledeci;
} CVOR;

void ubaciNaKraj (PCVOR* glava,PCVOR* rep,int a)
{
    PCVOR novi;
    novi=malloc(sizeof(CVOR));

    novi->info=a;
    novi->sledeci=NULL;
    if (*glava==NULL)
    {
        *glava=novi;
        *rep=novi;
    }
    else
    {
        (*rep)->sledeci=novi;
        *rep=novi;
    }
}

void prikaziListu (PCVOR glava)
{
    PCVOR tek=glava;
    printf ("\nLista:");

    while (tek!=NULL)
    {
        printf ("%5d",tek->info);
        tek=tek->sledeci;
    }
}

void sortiranjeListe (PCVOR glava,PCVOR rep)
{
    PCVOR spori;
    PCVOR brzi;
    int promena;

    spori=glava;
    while (spori!=rep)
    {
        brzi=spori->sledeci;
        while (brzi!=NULL)
        {
            if (spori->info > brzi->info)
            {
                promena=brzi->info;
                brzi->info=spori->info;
                spori->info=promena;
            }
            brzi=brzi->sledeci;
        }
        spori=spori->sledeci;
    }

}

void ubaciUSortiranu (PCVOR *glava,PCVOR *rep,int a)
{
    PCVOR novi;
    PCVOR brzi;
    PCVOR spori;
    int signal;

    brzi=*glava;
    signal=0;
    spori=NULL;

    while (brzi!=NULL && signal==0)
    {
        if (brzi->info > a)
            signal=1;
        else
        {
            spori=brzi;
            brzi=brzi->sledeci;
        }
    }

    if (signal==0)   // Nije nadjena pozicija
    {
        ubaciNaKraj (glava,rep,a);
    }
    else     // Pozicija je nadjena
    {
        novi=malloc(sizeof (CVOR));
        novi->info = a;
        novi->sledeci= NULL;
        if (spori==NULL)
        {
            novi->sledeci=*glava;
            *glava=novi;
        }
        else
        {
            novi->sledeci=brzi;
            spori->sledeci=novi;
        }
    }
}

double srednjaVrednost(PCVOR glava)
{
    PCVOR tek=glava;
    int suma=0;
    int brojac=0;
    double srv;

    while (tek!=NULL)
    {
        suma=suma+tek->info;
        brojac++;
        tek=tek->sledeci;
    }
    if (brojac==0)
        return 0;

    srv=(double)suma/brojac;

    return srv;
}

int brElVeciOd (PCVOR glava,double vr)
{
    PCVOR tek=glava;
    int brojac=0;

    while (tek!=NULL)
    {
        if (tek->info > vr)
            brojac++;
        tek=tek->sledeci;
    }
    return brojac;
}

int main (void)
{
    int a;
    double srv;
    PCVOR glava=NULL;
    PCVOR rep=NULL;

    ubaciNaKraj (&glava,&rep,6);
    ubaciNaKraj (&glava,&rep,8);
    ubaciNaKraj (&glava,&rep,11);
    ubaciNaKraj (&glava,&rep,3);
    ubaciNaKraj (&glava,&rep,0);
    ubaciNaKraj (&glava,&rep,1);
    ubaciNaKraj (&glava,&rep,5);

    prikaziListu(glava);
    sortiranjeListe (glava,rep);
    prikaziListu(glava);

    ubaciUSortiranu (&glava,&rep,4);
    ubaciUSortiranu (&glava,&rep,0);
    ubaciUSortiranu (&glava,&rep,17);

    prikaziListu(glava);

    srv=srednjaVrednost(glava);
    a=brElVeciOd(glava,srv);

    printf ("\nSrednja vrednost je %.2lf, a broj elemenata veci od SRV je %d",srv,a);

    return 0;
}
