#include <iostream>

void unosDvaBroja(int& b1, int& b2)
{
    std::cout << "Unesite prvi broj: ";
    std::cin >> b1;

    std::cout << "Unesite drugi broj: ";
    std::cin >> b2;

    return;
}

int saberi(int b1, int b2)
{
    return b1 + b2;
}


int main(void)
{
    int b1, b2;

    unosDvaBroja(b1, b2);
    std::cout << std::endl << "Zbir brojeva " << b1 << " + " << b2 << " je: " << saberi(b1, b2);

    return 0;
}
