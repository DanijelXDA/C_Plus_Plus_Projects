#include<iostream>

using namespace std;

int main(void)
{
    const int MAX = 20;
    int *n, *a, *zbir;

    n = new int;
    a = new int[MAX];
    zbir = new int;

    int i;

    do
    {
    cout << "\nUnesite velicinu niza( max = "<< MAX <<") ";
    cin >> *n;
    } while(*n<1 || *n>MAX);

    for(i=0; i<*n;i++)
    {
        cout << "\na["<< i <<"] =";
        cin >> a[i];
    }

    *zbir = 0;

    for(i=0; i<*n;i++)
        *zbir += *(a + i);

        cout << "Zbir iznosi: " << *zbir << endl;

        delete n;
        delete[] a;
        delete zbir;

    return 0;

}
