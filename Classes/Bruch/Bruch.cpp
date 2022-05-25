#include "Bruch.h"
#include <iostream>
Bruch::Bruch(int zaehler, int nenner)
{
    if (nenner == 0)
    {
        nenner = 1;
    }
    if (nenner < 0)
    {
        this->zaehler * = -1;
    }
    this->zaehler = zaehler;
    this->nenner = nenner;
}

bool Bruch::operator==(const Bruch &bruch)
{
    return this->zaehler == bruch.zaehler && this->nenner == bruch.nenner;
}

bool Bruch::operator!=(const Bruch &bruch)
{
    return this->zaehler != bruch.zaehler || this->nenner != bruch.nenner;
}

void Bruch::operator*=(const Bruch &bruch)
{
    this->zaehler *= bruch.zaehler;
    this->nenner *= bruch.nenner;
}
