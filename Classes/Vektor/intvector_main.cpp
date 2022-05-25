#include <iostream>
#include <string>
#include "IntVector.h"

/*
IntVector(size_t size); done
IntVector(const IntVector &orig);
~IntVector(){delete array;} done
const size_t _size(){return size;} done
const int& at(size_t idx);
void out();
*/

void klappt();
void crash();
int main(int argc, char **argv)
{

    // klappt();
    /*
    try{
     crash();
    }catch(std::runtime_error &e){
        std::cout<<e.what()<<std::endl;
    }
    */
   /*
    if  (strcmp(argv[1], "--crash") == 0)
    {
        crash();
    }
    */
    IntVector intVector(17); // {1,2 ... 0}
    intVector.at(1);
    intVector[1];


    IntVector intVector2  = intVector;
    return 1;
}
void klappt()
{
    IntVector intVector(17);
    int length = intVector._size();

    std::cout << "Länge: " << length << std::endl;
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            intVector.at(i) += i + 42;
        }
        else
        {
            intVector.at(i) = i;
        }
    }
    std::cout << "Länge: " << length << std::endl;
}

void crash()
{
    IntVector intVector(17);
    intVector.at(42);
}