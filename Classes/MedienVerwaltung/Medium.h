#ifdef  _MEDIUM_H_INCLUDED
#define _MEDIUM_H_INCLUDED
#include <string>
#include <iostream>
#define aktuellesJahr 2022

class Medium{
private:
    int id = 0;
    std::string title;
    int jahr;

public:
    Medium(std::strign title, int jahr);
    virtual ~Medium();
    int alter();
    void virtual druckeDaten() = 0; // pure virtual methode
    int getID()  { return id; }
    std::string geTitle()  { return title; }
    int getJahr(){return jahr;} 
};

Medium::Medium(std::strign title, int jahr) : title(title), jahr(jahr){
    id++;
}
Medium::~Medium(){std::cout<<"Destructor"<<std::endl;}
int Medium::alter() { return aktuellesJahr  - jahr;}


#endif //_MEDIUM_H_INCLUDED