#include "DynamicArray.h"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray(int s) : size(s)
{
    data = new int[size];
    for (int i = 0; i < size; ++i)
    {
        data[i] = 0;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size)
{
    data = new int[size];
    for (int i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }
}

DynamicArray::~DynamicArray()
{
    delete[] data;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
    if (this != &other)
    {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

DynamicArray DynamicArray::operator+(int n)
{
    DynamicArray temp(size + n);
    for (int i = 0; i < size; ++i)
    {
        temp.data[i] = data[i];
    }
    return temp;
}

DynamicArray DynamicArray::operator-(int n)
{
    if (size <= n)
    {
        cout << "Error: The size of the array is less than or equal to the number of deleted elements!" << endl;
        return *this;
    }
    DynamicArray temp(size - n);
    for (int i = 0; i < temp.size; ++i)
    {
        temp.data[i] = data[i];
    }
    return temp;
}

DynamicArray DynamicArray::operator*(int factor)
{
    DynamicArray temp(size);
    for (int i = 0; i < size; ++i)
    {
        temp.data[i] = data[i] * factor;
    }
    return temp;
}

DynamicArray DynamicArray::operator-(const DynamicArray& other)
{
    int newSize = size > other.size ? size : other.size;
    DynamicArray temp(newSize);
    for (int i = 0; i < newSize; ++i)
    {
        temp.data[i] = (i < size ? data[i] : 0) - (i < other.size ? other.data[i] : 0);
    }
    return temp;
}

DynamicArray DynamicArray::operator+(const DynamicArray& other)
{
    DynamicArray temp(size + other.size);
    for (int i = 0; i < size; ++i)
    {
        temp.data[i] = data[i];
    }
    for (int i = 0; i < other.size; ++i)
    {
        temp.data[size + i] = other.data[i];
    }
    return temp;
}

DynamicArray& DynamicArray::operator++()
{
    DynamicArray temp(size + 1);
    for (int i = 0; i < size; ++i)
    {
        temp.data[i] = data[i];
    }
    temp.data[size] = 0;
    *this = temp;
    return *this;
}

DynamicArray& DynamicArray::operator--()
{
    if (size <= 0)
    {
        cout << "Error: The size of the array cannot be reduced below 0!" << endl;
        return *this;
    }
    DynamicArray temp(size - 1);
    for (int i = 0; i < temp.size; ++i)
    {
        temp.data[i] = data[i];
    }
    *this = temp;
    return *this;
}

void DynamicArray::print() const
{
    for (int i = 0; i < size; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
