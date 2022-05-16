#include <iostream>

#include "Time.h"


int main(){

    Time time{1,4,2}; // 11:01:00
    time.timeAusgabe();

    Time time2{8,20,20}; // 7322
   
    time.add(time2);
    // std::cout << time.diff(time2)<<"sek."<<std::endl;
    time.timeAusgabe();

    return 1;
}