#include "IntVector.h"
#include <iostream>
/*
IntVector::IntVector(size_t size){
    this->size = size;
    this->array = new int[size];
}
*/

IntVector::IntVector(size_t size) : size(size), array(new int[size]) {}

IntVector::IntVector(const IntVector &orig): IntVector(orig.size){
    for(int i = 0 ; i < orig.size ; ++i){
       this->array[i] = orig.array[i];
    }
}
int &IntVector::at(size_t idx)
{
    if (idx < 0 || idx >= size)
    {
        throw std::runtime_error("index out of rang");
    }
    else
    {
        return array[idx];
    }
}

void IntVector::out()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << at(i);
    }
    std::cout << std::endl;
}


IntVector &IntVector::operator=(const IntVector &orig)
{
   IntVector erg (orig);
   return erg;
}

int& IntVector::operator[](int index) {
    return index > 0 && index < size ? array[index] : array[0];
}
