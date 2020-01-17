#include <iostream>
using namespace std;

int main(void)
{
    int m = 0, n = 0;
    [&, n] (int a) mutable {
        m = ++n + a;
    }(4);

    cout << m << endl << n << endl;

    return 0;
}
