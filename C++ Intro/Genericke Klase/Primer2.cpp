#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T const &Max (T const &a, T const &b)
{
    return (a < b) ? b : a;
}

int main(void)
{
    cout << endl << "Genericke funkcije" << endl << endl;

    int a = 15, b = 25;
    cout << "Max(a, b): " << Max(a, b) << endl;

    float c = 15.5, d = 4.8;
    cout << "Max(c, d): " << Max(c, d) << endl;

    string s1 = "Hello", s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;

    return 0;
}
