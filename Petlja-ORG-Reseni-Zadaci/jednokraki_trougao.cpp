#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c;
    
    cin >> a >> b >> c;
    
    if( (a == b || b == c || c == a) && ( a != 0 && b != 0 && c != 0) && (a > 0 && b > 0 && c > 0) && (a != b != c) && ( a != 1 && b != 1 && c != 1))
        cout << 1;
    else
        cout << 0;

    return 0;
}
