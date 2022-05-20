#include <cstdlib>
#include <iostream>
class IntVector{
private:
int* array;
size_t size;

public:
IntVector(size_t size);
IntVector(const IntVector &orig);
~IntVector(){
    std::cout<<"Destruktor "<<std::endl;
    delete array;}
const size_t _size(){return size;}
int& at(size_t idx);
void out();
IntVector& operator=(const IntVector&);
};
   
