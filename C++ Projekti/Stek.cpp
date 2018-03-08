#include <iostream>
#include <stack>

using namespace std;

int main()
{

    stack<int> mojStek;
    int sp=0;
    int a, b;


do
{
    cout << "1. Upis u stek." << endl << "2. Prikaz iz steka." << endl << "3. Izlaz iz programa." << endl << endl;
    cin >> a;
    cout << endl;


        if(a == 1)
        {

           if (sp > 5)
           {
               cout << "Stek je pun." ;
           }
           else
           {
               cout << "Upisite element:" << endl;
               cin >> b;
               mojStek.push(b);
               sp++;
               cout << "Stack pointer: " << sp << endl << endl;
           }
        }
        else if(a == 2)
        {
            if(mojStek.empty())
                cout << "Stek je prazan!" << endl;
            else
            {
                cout << "Poslednji element: " << mojStek.top() << endl << endl;
                mojStek.pop();
                sp--;
                cout << "Stack pointer: " << sp << endl << endl;
            }
        }
        else if (a == 3)
        {
            return 0;
        }
}while(1);

}
