#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

// Prototip funkcije
bool daLiJeOperator(const string&);

int main(void)
{

  return 0;
  
}

bool daLiJeOperator(const string& unos)
{
    string operatori[] = {"-", "+", "*", "/"};

    for(int i = 0; i < 4; i++)
    {
        if( unos == operatori[i] )
        {
            return true;
        }
    }
    return false;
}
