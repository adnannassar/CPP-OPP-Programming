#include <string>

class Time
{
private:
    int stunden, minuten, sekunden;

public:
    Time(int stund = 0, int min = 0, int sek = 0);

    const int hour() { return stunden; }
    const int minute() { return minuten; }
    const int second() { return sekunden; }

    void add(Time time);
    void add_hours(int hours);
    void add_minutes(int minutes);
    void add_seconds(int seconds);
    const int justseconds();
    const int diff(Time time);
    void timeAusgabe();
    void reformatTime();

};
