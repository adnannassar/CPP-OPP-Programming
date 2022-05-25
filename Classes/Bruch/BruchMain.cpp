#include<iostream>
#include"Bruch.h"


int main(){
Bruch b1 (20,20); // 1
Bruch b2 (3,6); // 1 / 2
Bruch b3 (5,4); // 5 / 4
Bruch b4 (10,1); // 10
Bruch b5 (30,0); // 30 / 1 --> 30


std::cout<< b1 <<std::endl;
std::cout<< b2 <<std::endl;
std::cout<< b3 <<std::endl;
std::cout<< b4 <<std::endl;
std::cout<< b5 <<std::endl;

return 1;

}