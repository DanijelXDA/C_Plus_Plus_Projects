#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

// Prototip funkcije
bool daLiJeOperator(const string&);
// Prototip funkcije
void izvodjenjeOperatora(const string& , stack<double>&);

int main(void)
{
  stack <double> stek; // Stek
  string unos;
  
  cout << "Kalkulator: Obrnuta poljska notacaija" << endl;
  
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
