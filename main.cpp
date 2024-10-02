#include "DynamicArray.h"
#include <iostream>

using namespace std;

int main()
{
    DynamicArray a(5);
    for (int i = 0; i < 5; ++i)
    {
        a = a + 1;
    }

    cout << "array a: ";
    a.print();

    DynamicArray rez = a + 10;
    cout << "a + 10: ";
    rez.print();

    DynamicArray rez1 = a - 2;
    cout << "a - 2: ";
    rez1.print();

    DynamicArray rez2 = a * 2;
    cout << "a * 2: ";
    rez2.print();

    DynamicArray b(5);
    for (int i = 0; i < 5; ++i)
    {
        b = b + (i + 1);
    }

    cout << "array b: ";
    b.print();

    DynamicArray rez3 = a - b;
    cout << "a - b: ";
    rez3.print();

    DynamicArray rez4 = a + b;
    cout << "a + b: ";
    rez4.print();

    ++rez;
    cout << "++rez: ";
    rez.print();

    --rez;
    cout << "--rez: ";
    rez.print();

    return 0;
}
