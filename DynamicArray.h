#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray
{
private:
    int* data;
    int size;

public:
    DynamicArray(int s = 0);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray operator+(int n);
    DynamicArray operator-(int n);
    DynamicArray operator*(int factor);
    DynamicArray operator-(const DynamicArray& other);
    DynamicArray operator+(const DynamicArray& other);
    DynamicArray& operator++();
    DynamicArray& operator--();

    void print() const;
};

#endif 

