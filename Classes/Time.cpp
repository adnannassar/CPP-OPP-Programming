#include "Time.h"
#include <iostream>

// Element initialisierungslist
Time::Time(int stund, int min, int sek)
{
    if (stund < 0)
    {
        stund = 0;
    }
    if (min < 0)
    {
        min = 0;
    }
    if (sek < 0)
    {
        sek = 0;
    }
    if (min > 59)
    {
        min = 0;
        stund++;
    }

    if (sek > 59)
    {
        sek = 0;
        min++;
    }

    stunden = stund;
    minuten = min;
    sekunden = sek;
}
void Time::add(Time time)
{
    this->stunden += time.hour();
    this->minuten += time.minute();
    if (this->minuten > 59)
    {
        this->stunden++;
        this->minuten = 0;
    }
    this->sekunden += time.second();
    if (this->sekunden > 59)
    {
        this->minuten++;
        this->sekunden = 0;
    }
}
void Time::add_hours(int hours)
{
    this->stunden += hours;
}
void Time::add_minutes(int minutes)
{
    this->minuten += minutes;
    if (this->minuten > 59)
    {
        this->stunden++;
        this->minuten = 0;
    }
}
void Time::add_seconds(int seconds)
{
    this->sekunden += seconds;
    if (this->sekunden > 59)
    {
        this->minuten++;
        this->sekunden = 0;
    }
}
const int Time::justseconds()
{
    return (this->stunden * 3600) + (this->minuten * 60) + this->sekunden;
}
const int Time::diff(Time time)
{
    return this->justseconds() - time.justseconds();
}
void Time::timeAusgabe()
{
    std::string hourInString = std::to_string(hour());
    std::string minutsInString = std::to_string(minute());
    std::string secondsInString = std::to_string(second());
    if (hourInString.length() < 2)
    {
        hourInString = "0" + hourInString;
    }

     if (minutsInString.length() < 2)
    {
        minutsInString = "0" + minutsInString;
    }

     if (secondsInString.length() < 2)
    {
        secondsInString = "0" + secondsInString;
    }

    std::cout <<  hourInString << ":" << minutsInString << ":" << secondsInString << std::endl;
}
