#ifdef _BILD_H_INCLUDED
#define _BILD_H_INCLUDED

#include "Medium.h"
#include <string>

class Bild : public Medium
{
private:
    std::string ort;

public:
    Bild(std::strign title, int jahr, std::string ort);
    std::string getOrt (){return ort;}
    void druckeDaten() override{
        std::cout<<"ID = "<<getID()<<" \""<<geTitle()<<"\" aufgenommen im Jahr "<<getjahr()<< " in " <<ort<<std::endl;
    }
}

Bild::Bild(std::strign title, int jahr, std::string ort) : Medium(title, jahr), ort(ort){}
#endif //_BILD_H_INCLUDED
