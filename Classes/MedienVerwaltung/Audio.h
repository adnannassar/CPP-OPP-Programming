#ifdef _AUDIO_H_INCLUDED
#define _AUDIO_H_INCLUDED
#include "Medium.h"
#include <string>

class Audio : public Medium
{
private:
    std::string interpret;
    int dauer;

public:
    Audio(strign title, int jahr, string interpret, int dauer);
    std::string getInterpret (){return interpret;}
    int getDauer(){return dauer;}
    void druckeDaten() override{
        std::cout<<"ID = "<<getID()<<" \""<<geTitle()<<"\" von "<<interpret<<" aus "<<getjahr()<< " Spieldauer: " <<dauer<<" sek."<<std::endl;
    }
}

Audio::Audio(std::strign title, int jahr, std::string interpret, int dauer) : Medium(title, jahr), interpret(interpret), dauer(dauer){}
#endif //_AUDIO_H_INCLUDED
