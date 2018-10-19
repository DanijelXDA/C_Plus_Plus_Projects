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

    // Ispis elemenata niza
    cout << endl << "Elementi niza:  ";
    for(int i = 0; i < N; i++)
        cout << *(X + i) << " ";

    return 0;
}
