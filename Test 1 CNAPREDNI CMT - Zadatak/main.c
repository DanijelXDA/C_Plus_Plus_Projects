#include "Kosarkas.h"

int main()
{
    int izbor;
    int n;

    Tkosarkas spisak[DIMENZIJA];
    FILE *ulazFile;


    char imeFajla[DUZINA_IME];


    /* Unesi ime ulaznog fajla */
    printf("Unesi ime fajla: ");
    scanf("%s", imeFajla);


    /* Otvaranje fajla */
    ulazFile  = fopen(imeFajla, "r");



    /* Izlaz iz programa sko nije fajl otvoren uspesno */
    if (ulazFile == NULL )
    {
        printf("Faj se ne moze otvoriti.\n");
        printf("Molimo Vas proverite read/write privilegije.\n");

        exit(EXIT_FAILURE);
    }

    n = ucitajFajl(ulazFile, spisak);

    do
    {
        izbor = Meni();

        switch(izbor)
        {
            case 1:
                dodajKosarkasaUTim(spisak, &n);
                break;

            case 2:
                dodajBrojPoenaKosarkasu(spisak, n);
                break;

            case 3:
                ispisKosarkasaZadatiTim(spisak, n);
                break;

            case 4:
                spisakSortiranihKosarkasaPoBrojuPoena(spisak, n);

        }
    } while(izbor != 5);

    fclose(ulazFile);

    /*  Upis */
    FILE *izlazFile;

    // Otvaranje fajla
    izlazFile  = fopen("Kosarkasi.txt", "w");


    // Izlaz iz programa sko nije fajl otvoren uspesno
    if (izlazFile == NULL )
    {
        printf("Faj se ne moze otvoriti.\n");
        printf("Molimo Vas proverite read/write privilegije.\n");

        exit(EXIT_FAILURE);
    }

    sacuvajFajl(izlazFile, spisak, n);

    fclose(izlazFile);

    return 0;
}
