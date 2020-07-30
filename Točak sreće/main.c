#include <stdio.h>
#include <string.h>

int rotirajUlevo(int niz[], int n, int k)
{
    int temp, i, j;

    for(j = 0; j < k; j++)
    {
        temp = niz[0];

        for(i = 1; i < n; i++)
            niz[i - 1] = niz[i];

        niz[n - 1] = temp;
    }

    return niz[0];
}
int rotirajUdesno(int niz[], int n, int k)
{
    int temp, i, j;

    for(j = 0; j < k; j++)
    {
        temp = niz[n - 1];

        for(i = n - 2; i >= 0; i--)
            niz[i + 1] = niz[i];

        niz[0] = temp;
    }

    return niz[0];
}

int main()
{
    int n, p, i, j;
    FILE *ulaz = fopen("Ulaz.txt", "r");

    fscanf(ulaz, "%d", &n);
    fscanf(ulaz, "%d", &p);

    int drugiRed[n], treciRed[p][2];
    char matricaZnakova[n][n]; // cuvanje matrice znakova

    for(i = 0; i < n; i++)
        fscanf(ulaz, "%d", &drugiRed[i]);

    for(i = 0; i < p; i++)
        for(j = 0; j < 2; j++)
            fscanf(ulaz, "%d%*c", &treciRed[i][j]);

    // UCITAVANJE MATRICE ZNAKOVA
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if( (j == n - 1) ) // izbegavavanje ucitavanja znaka za novi red
                fscanf(ulaz, "%c\n", &matricaZnakova[i][j]);
            else
                fscanf(ulaz, "%c", &matricaZnakova[i][j]);

    char nagrade[10][20]; // niz od 10 nagrada
    i = 0;

    do {
        char tmpNag[20];

        fscanf(ulaz, "%s", tmpNag);
        strcpy(nagrade[i], tmpNag);

        i++;

    } while(i < 10);

    fclose(ulaz);
    /* UCITAVANJE KRAJ */
    int velNagrada = 0;

    for(i = 0; i < 10; i++)
        if (strcmp(nagrade[i], nagrade[i + 1]))
            velNagrada++;

    int drugiRed2[n]; // za rotiranje udesno
    for(i = 0; i < n; i++)
        drugiRed2[i] = drugiRed[i]; // koopiranje niza

    ulaz = fopen("Izlaz.txt", "w+");

    int brojac = 1, ng = 0, uzetaNagrada[p];
    i = 0;
    do {

        int p1 = (rotirajUlevo(drugiRed, n, treciRed[brojac - 1][0]));
        int p2 = (rotirajUdesno(drugiRed2, n, treciRed[brojac - 1][1]));

        for(j = 0; j < velNagrada; j++)
            if( (matricaZnakova[p1][p2] == nagrade[j][0]) &&  (j != uzetaNagrada[j]) )
            {
                char nagrada[25];

                strcpy(nagrada, nagrade[j]);
                fputs(nagrada, ulaz);
                fputs("\n", ulaz);
                uzetaNagrada[ng] = j;

                ng++;
                break;
            }
            else if( (matricaZnakova[p1][p2] == nagrade[j][0]) && (j == uzetaNagrada[j]) )
            {
                fputs("Nema nagrade.\n", ulaz);
                break;
            }

        brojac++;
        i += 2;
    } while(brojac <= p);

    fclose(ulaz);

    return 0;
}
