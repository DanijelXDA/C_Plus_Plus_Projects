#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack {
    private:
        vector <T> elementi;
    public:
        void push(T const &);
        void pop();
        T top() const;
        bool empty() const;
};

template <class T>
void Stack <T>::push(T const &elem)
{
    elementi.push_back(elem);
}

template <class T>
void Stack <T>::pop()
{
    if(elementi.empty())
        throw out_of_range("Stack <>::pop(): empty stack");

    elementi.pop_back();
}

template <class T>
T Stack <T>::top() const
{
    if(elementi.empty())
        throw out_of_range("Stack <>::pop(): empty stack");

    return elementi.back();
}

template <class T>
bool Stack <T>::empty() const
{
    return elementi.empty();
}


int main(void)
{
    try
    {
        Stack <int> intStack;
        Stack <string> stringStack;

        intStack.push(7);
        cout << intStack.top() << endl;

        stringStack.push("Hello");
        cout << stringStack.top() << endl;

        stringStack.pop();
        stringStack.pop();
    }
    catch(exception const &ex)
    {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }
}
