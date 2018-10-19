#include <iostream>
using namespace std;

int main(void)
{
    int N;
    int X[50];

    do {
        cout << "Unesite broj elemenata niza: ";
        cin >> N;
    } while(N <= 0);

    // Unos elemenata niza
    cout << endl << "Unos elemenata niza:  ";
    for(int i = 0; i < N; i++)
        cin >> *(X + i);

    // Trazenje najmanjeg elementa u nizu
    int najmanji = *X;
    for(int i = 0; i < N; i++)
        if( *(X + i) < najmanji )
            najmanji = *(X + i);

    cout << "Najmanji element u nizu je: " << najmanji << endl;

    return 0;
}
