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
  
  while(true) // Beskonacna petlja
  {
    // Prikaz zahteva
        cout << ">> ";
    
    // Uzimanje unosa
        cin >> unos;
    
    // Provera da li je broj
        double broj;

        if( istringstream(unos) >> broj ) // Kreiranje novog objekta
        {
            stek.push(broj); // Ubacivanje u stek
        }
        // Provera da li je operator
        else if( daLiJeOperator(unos) )
        {
            izvodjenjeOperatora(unos, stek);
        }
        // Prekid rada programa
        else if( unos == "q" )
        {
            return 0;
        }
         else
        {
            cout << endl << "Unos nije vazeci!" << endl;
        }
  }
  
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

void izvodjenjeOperatora(const string& unos, stack<double>& stek)
{
  double vrednostLevo, vrednostDesno, rezultat;
  
  vrednostDesno = stek.top();
    stek.pop();
  
      vrednostLevo = stek.top();
    stek.pop();
  
  if( unos == "-" )
    {
        rezultat = vrednostLevo - vrednostDesno;
    }
    else if( unos == "+" )
    {
        rezultat = vrednostLevo + vrednostDesno;
    }
    else if( unos == "*" )
    {
        rezultat = vrednostLevo * vrednostDesno;
    }
    else
    {
        rezultat = vrednostLevo / vrednostDesno;
    }
  
  cout << "\tRezultat: " << rezultat << endl;
  
  return;
}
