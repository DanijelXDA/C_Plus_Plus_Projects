#include "../Headers/Magacin.hpp"
#include <fstream>
#include <sstream>
#include <string>

Magacin::Magacin()
{

    for(int i = 0; i < 100; i++)
    {
        ID[i] =  i + 1;
        imeSirovine[i] = "NEMA";
        kolicinaSirovine[i] = 0.0;
        jedinicaMere[i] = "NEMA";
    }
}

bool Magacin::proveraStanjaUMagacinu()
{
    // Magacin je prazan AKO JE PRVO MESTO PRAZNO
    if(imeSirovine[0] == "NEMA")
        return true; // Potvrdno - MAGACIN JE PRAZAN
    else
        return false; // Magacin nije prazan
}
void Magacin::sadrzajMagacina()
{
    system("cls");

    // Magacin je prazan AKO JE PRVO MESTO PRAZNO
    if( proveraStanjaUMagacinu() )
        cout << endl << endl << "\t\t\t\tMAGACIN JE PRAZAN!" << endl << endl;
    else
        cout << "U magacinu se nalaze sledece sirovine: " << endl;

    // Citanje iz magacina
        for(int i = 0; i < 100; i++)
    {
        if(imeSirovine[i] != "NEMA")
        {
            cout << endl << endl << "ID: " << ID[i];
            cout << endl << "Sirovina: " << imeSirovine[i] << endl;
            cout << "Kolicina: " << kolicinaSirovine[i] << endl;
            cout << "Jedinica mere: " << jedinicaMere[i];
        }
    }

    return;
}

void Magacin::dodavanjeUMagacin()
{
    string sirovina;
    string jedMere;
    float kolicina;

    cout << "********************************************************************************" << endl;
    cout << "\t\t\tDodajete sirovinu u magacin!" << endl << endl;
    cout << "********************************************************************************" << endl;


    cout << "Ime nove sirovine: ";
    cin.ignore(); // kao fflush()
    getline(cin, sirovina);

    cout << "Kolicina nove sirovine: ";
    cin >> kolicina;

    cout << "Jedinica mere nove sirovine: ";
    cin >> jedMere;

    // Setovanje
    for(int i = 0; i < 100; i++) // Trazi se prvo slobodno mesto
        if(imeSirovine[i] == "NEMA")
        {
            imeSirovine[i] = sirovina;
            kolicinaSirovine[i] = kolicina;
            jedinicaMere[i] = jedMere;

            break;
        }
    if( upisUMagacinTXT() )
        cout << endl << "SIROVINA JE DODATA U MAGACIN!" << endl;

    return;
}

void Magacin::izbacivanjeIzMagacina()
{

    if( proveraStanjaUMagacinu() )
        cout << endl << "Magacin je prazan! Izbacivanje onemoguceno!" << endl;
    else
    {
        int ID;

        cout << "********************************************************************************" << endl;
        cout << "\t\t\tIzbacujete sirovinu iz magacina!" << endl << endl;
        cout << "********************************************************************************" << endl;

        cout << endl << "Unesite ID sirovine koju izbacujete: ";
        cin >> ID;

        while( (ID < 1 || ID > 100) || imeSirovine[ID - 1] == "NEMA" )
        {
            cout << endl << "ID koji ste uneli ne sadrzi nijednu sirovinu!" << endl;
            cout << endl << "Unesite ID sirovine koju izbacujete: ";
            cin >> ID;
        }


        for(int i = ID - 1; i < 100; i++)   // Rotiranje niza ulevo za jedno mesto
        {
            if(imeSirovine[i] != "NEMA")
            {
                imeSirovine[i] = imeSirovine[i + 1];
                kolicinaSirovine[i] = kolicinaSirovine[i + 1];
                jedinicaMere[i] = "NEMA";
            }
            else
            {
                imeSirovine[i] = "NEMA";
                kolicinaSirovine[i] = 0.0;
            }
        }
    }

    if( upisUMagacinTXT() )
        cout << endl << "SIROVINA JE IZBACENA IZ MAGACINA!" << endl;

    return;
}

void Magacin::azuriranjeSirovine()
{

    if( proveraStanjaUMagacinu() )
        cout << endl << "Magacin je prazan! Azuriranje onemoguceno" << endl;
    else
    {

        int ID;

        cout << "********************************************************************************" << endl;
        cout << "\t\t\tAzuriranje sirovine iz magacina!" << endl << endl;
        cout << "********************************************************************************" << endl;

        cout << endl << "Unesite ID sirovine koju azurirate: ";
        cin >> ID;

        // NEMA NEGATIVNOG ID!
        do {
            cout << endl << "Unesite ID sirovine koju azurirate: ";
            cin >> ID;
        } while(ID < 1);


        while(imeSirovine[ID - 1] == "NEMA")
        {
            cout << endl << endl << "Na unetoj pozicije ne postoji sirovina!";
            cout << endl << "Unesite ID sirovine koju azurirate: ";
            cin >> ID;
        }


        cout << endl << "Azuriranje imena sirovine: ";
        cin.ignore();
        getline(cin, imeSirovine[ID - 1]);

        cout << endl << "Azuriranje kolicine sirovine u magacinu: ";
        cout << endl << "Unesite novu kolicinu sirovine: ";
        cin >> kolicinaSirovine[ID - 1];
    }

    if( upisUMagacinTXT() )
        cout << endl << "SIROVINA U MAGACINU JE USPESNO AZURIRANA!" << endl;

    return;
}

bool Magacin::upisUMagacinTXT()
{
    bool uspesanUpis = false;

    ofstream magacin; // UPIS
    magacin.open("Magacin.txt");

    if( magacin.is_open() )
    {

        // UPIS U Magacin.txt
        for(int i = 0; i < 100; i++)
        {
            magacin << ID[i];
            magacin << " " << imeSirovine[i];
            magacin << " " << kolicinaSirovine[i];
            magacin << " " << jedinicaMere[i] << endl;
        }
        magacin.close(); // Zatvranje datoteke

        uspesanUpis = true;
    }
    else
        cout << endl << "DATOTEKA NE POSTOJI!" << endl;

    return uspesanUpis;

}

bool Magacin::citanjeUMagacinTXT()
{
    bool uspesanUpis = false;

      //load the text file and put it into a single string:
    fstream magacin("Magacin.txt");

    if( magacin.is_open() )
    {
        stringstream unos;

        unos << magacin.rdbuf();

        string test = unos.str();

        //create variables that will act as "cursors". we'll take everything between them.
        size_t pos1 = 0;
        size_t pos2;

        //create the array to store the strings.
        string str[100];

        for (int x  = 0; x <= 100; x++){
            pos2 = test.find(" ", pos1);                    //search for the bar " ". pos2 will be where the bar was found.
            str[x] = test.substr(pos1, (pos2 - pos1));      //make a substring, wich is nothing more
                                                            //than a copy of a fragment of the big string.
            pos1 = pos2 + 1;                                // sets pos1 to the next character after pos2.
                                                            //so, it can start searching the next space bar.
        }
        uspesanUpis = true;
    }
    else
        cout << endl << "DATOTEKA NE POSTOJI!" << endl;

    return uspesanUpis;

}
