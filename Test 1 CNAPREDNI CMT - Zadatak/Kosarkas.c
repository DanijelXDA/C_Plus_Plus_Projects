#include "Kosarkas.h"

int Meni()
{
    //Meni: ispisuje opcije
    int izbor, i=0;
    do
    {

        if(i>0)
        {
            printf("\nNevazeca komanda \n");
        }
        printf("\n\t\tMENI\n--------------------------------------------\n");

        printf("1 \t Dodavanje novog kosarkasa u tim\n");

        printf("2 \t Dodavanje poena na prethodnoj utakmici zeljenom kosarkasu\n");
        printf("3 \t Ispisivanje svih podataka o kosarkasima zadatog tima\n");
        printf("4 \t Spisak kosarkasa sortiranih po broju poena\n");

        printf("5 \t Kraj rada programa\n");
        printf("\nPritisnite neki od brojeva da nastavite\n>> ");
        scanf("%d",&izbor);
        i++;
    }
    while(izbor < 0 || izbor > 5);

    return izbor;
}

void dodajKosarkasaUTim(Tkosarkas spisak[], int *n)
{
    if (*n < DIMENZIJA )
    {
        printf("\t\t UNOS  NOVOG KOSARKASA  \n--------------------------------------------------------------\n");

        printf("\nUnesi sifru kosarkasa: ");
        scanf("%d", &spisak[*n].sifra);

        int i = 0;

        while (spisak[*n].sifra != spisak[i].sifra && i < *n )
            ++i;

        if (i == *n)
        {
            printf("\nUnesite ime  kosarkasa\n>> ");
            scanf("%s",spisak[*n].ime);
            printf("\nUnesite prezime kosarkasa\n>> ");
            scanf("%s",spisak[*n].prezime);
            printf("\nUnesite klub kosarkasa\n>> ");
            scanf("%s",spisak[*n].klub);

            do {
                printf("\nUnesite broj poena kosarkasa\n>> ");
                scanf("%d", &spisak[*n].brojPoena);
            } while(spisak[*n].brojPoena <= 0);

            do {
                printf("\nUnesite broj utakmica kosarkasa\n>> ");
                scanf("%d", &spisak[*n].brojUtakmica);
            } while(spisak[*n].brojUtakmica <= 0);


            (*n)++;
        }
        else
            printf("\nUpozorenje> Korisnik sa unetom sifrom postoji!\n");
    }
    else
        printf("\n Greska!! Popunjen kapacitet!!!");

    return;
}

void dodajBrojPoenaKosarkasu(Tkosarkas spisak[], int n)
{
    int Sifra, noviPoeni;

    do {
        printf("\nUnesite sifru kosarkasa ciji broj poena menjate\n>> ");
        scanf("%d", &Sifra);
    } while(Sifra < 1 || Sifra > n); // sifra mora biti u opsegu!

    do {
        printf("\nTrenutni broj poena: %d\nTrenutni broj utakmica: %d\n", spisak[Sifra - 1].brojPoena, spisak[Sifra - 1].brojUtakmica);
        printf("\nUnesite novi broj poena\n>> ");
        scanf("%d", &noviPoeni);
    } while(noviPoeni <= 0);

    // izmena podataka
    spisak[Sifra - 1].brojPoena = noviPoeni;
    spisak[Sifra - 1].brojUtakmica++;

    return;
}

void ispisKosarkasaZadatiTim(Tkosarkas spisak[], int n)
{
    Tkosarkas timovi[DIMENZIJA];
    int i, upisano = 0;
    char tim[DUZINA_IME];

    printf("\nUnesite ime tima\n>> ");
    scanf("%s", tim);

    for(i = 0; i < n; i++)
        if(strcmp(spisak[i].klub, tim) == 0) // stringovi se poklapaju, upis Kosarkasa  sa indeksom i u datoteku tim.txt
        {
            timovi[upisano].sifra = spisak[i].sifra;
            strcpy(timovi[upisano].ime, spisak[i].ime);
            strcpy(timovi[upisano].prezime, spisak[i].prezime);
            strcpy(timovi[upisano].klub, spisak[i].klub);
            timovi[upisano].brojPoena = spisak[i].brojPoena;
            timovi[upisano].brojUtakmica = spisak[i].brojUtakmica;

            upisano++;
        }

    if(upisano == 0)
        printf("\nNe postoji kosarkas sa unetim imenom kluba\n");
    else
    {
        FILE *izlazTim = fopen(strcat(tim, ".txt"), "w");

        sacuvajFajl(izlazTim, timovi, upisano); // upis u datoteku!
        printf("\n\nPodaci kosarkasa za tim %s su upisanu u datoteku \"%s\n", tim, tim);
    }

    return;
}


void spisakSortiranihKosarkasaPoBrojuPoena(Tkosarkas spisak[], int n) /* SORTIRA SE OPADAJUCE */
{
    int i, j;
    Tkosarkas pom, ispis[n];

    for(i = 0; i < n; i++) // kopija originala zbog ispisa
        ispis[i] = spisak[i];


    for(i = 0; i < n-1; ++i)
        for(j= i + 1; j < n; ++j)
            if(ispis[i].brojPoena < ispis[j].brojPoena)
            {
                pom = ispis[i];
                ispis[i] = ispis[j];
                ispis[j] = pom;

            }

    printf("\nIspis kosarkasa - SORTIRANI OPADAJUCE -\n\n");
    for(i = 0; i < n; i++)
    {
        printf("\n\nKosarkasas[%d]\n\tSifra: %d", i + 1, ispis[i].sifra);
        printf("\n\tIme: %s", ispis[i].ime);
        printf("\n\tPrezime: %s", ispis[i].prezime);
        printf("\n\tKlub: %s", ispis[i].klub);
        printf("\n\tBroj poena: %d", ispis[i].brojPoena);
        printf("\n\tBroj utakmica: %d\n\n", ispis[i].brojUtakmica);
    }


    return;
}


// DEO ZA DATOTEKU
int ucitajFajl(FILE *ulazFile, Tkosarkas Kosarkas[])
{

    char kraj;
    int i =0;

    while (1)
    {
        /* Citanje Kosarkasa*/
        kraj = fscanf(ulazFile, "%d%s%s%s%d%d ", &Kosarkas[i].sifra, Kosarkas[i].ime, Kosarkas[i].prezime, Kosarkas[i].klub, &Kosarkas[i].brojPoena, &Kosarkas[i].brojUtakmica);

        if (kraj == EOF)
        {
            printf("\n\nNAPOMENA: Ucitana je ulazna datoteka.\n\n");

            break;
        }
        i++;
    }

    return i;

}

void sacuvajFajl(FILE *ulazFile, Tkosarkas Kosarkas[], int n)
{
    int i = 0;

    for(i = 0; i < n; ++i)
    {
        /* Citanje kosarkasa*/
        fprintf(ulazFile, "%d %s %s %s %d %d\n", Kosarkas[i].sifra, Kosarkas[i].ime, Kosarkas[i].prezime, Kosarkas[i].klub, Kosarkas[i].brojPoena, Kosarkas[i].brojUtakmica);
    }


}
