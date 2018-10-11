#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    
    cin >> a >> b;
    
    if( (a > 5) && (b  > 5) && (a + b > 25) )
        cout << 1;
    else
        cout << 0;

    return 0;
}
