#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
using namespace std;

class Time
{
public:
    Time(int hour = 0, int minute = 0, int second = 0) : _hour(hour), _minute(minute), _second(second)
    {
        cout << "Created" << endl;
    }
    ~Time() { cout << "Killed!" << endl; }
    int hour() const { return _hour; }
    int minute() const { return _minute; }
    int second() const { return _second; }

    bool add_hours(int hours)
    {
        if (_hour < 23)
        {
            _hour += hours;
        }
        return normalize();
    }
    bool add_minutes(int minutes)
    {
        _minute += minutes;
        return normalize();
    }
    bool add_seconds(int seconds)
    {
        _second += seconds;
        return normalize();
    }
    bool operator==(const Time &other) const
    {
        return _hour == other._hour && _minute == other._minute && _second == other._second;
    }
    void print()
    {
        cout << _hour << ":" << _minute << ":" << _second << endl;
    }

private:
    bool normalize()
    {
        if (_second == 60)
        {
            _second = 0;
            _minute++;
            return true;
        }
        if (_minute == 60)
        {
            _minute = 0;
            _hour++;
            return true;
        }
        if (_hour == 23 && _minute == 59 && _second == 59)
        {
            _second = _minute = _hour = 0;
            return true;
        }

        return false;
    }
    int _hour, _minute, _second;
};

Time operator++(Time &t, int)
{
    Time erg = t;
    erg.add_seconds(1);
    return erg;
}
istream &operator>>(istream &in, Time &t)
{
    int h, m, s;
    cout << "hour: ";
    in >> h;

    cout << "minute: ";
    in >> m;

    cout << "secund: ";
    in >> s;
    t = Time(h, m, s);
    return in;
}
class Uhr
{
private:
    Time t;

public:
    Uhr(Time t) : t(t){};
    virtual void tick()
    {
        t.add_seconds(1);
    }
    Time getTime()
    {
        return t;
    }
};

class Wecker : public Uhr
{
private:
    Time weckzeit;

public:
    Wecker(Time t, Time weckzeit) : Uhr(t), weckzeit(weckzeit) {}
    void tick() override
    {
        Uhr::tick();
        if (getTime() == weckzeit)
        {
            cout << "Alarm!!!" << endl;
        }
    }
};

class Fahrzeug
{
public:
    virtual ~Fahrzeug() {}
    virtual void fahren() = 0;
};

class Rennwagen : public Fahrzeug
{
public:
    void fahren() override
    {
        cout << "Vroooooom." << endl;
    }
};

class Traktor : public Fahrzeug
{
public:
    void fahren() override
    {
        cout << "tuktuktuktuktuk." << endl;
    }
};

enum Type
{
    APFEL,
    BIRNE
};

class Obst
{
public:
    virtual ~Obst(){}; // in dem Fall nicht unbedingt notwendig
    virtual Type typeOf() = 0;
};
class Apfel : public Obst
{
public:
    Type typeOf() override { return APFEL; }
};
class Birne : public Obst
{
public:
    Type typeOf() override { return BIRNE; }
};

void testAufgabe17()
{
    Time t(11, 46, 20);
    t.print();
    // Time t2;
    // cin >> t2;
    // t2.print();
    t = t++;
    t.print();
    Time t2;
    cin >> t2;
    if (t == t2)
    {
        cout << "Equals" << endl;
    }
    else
    {
        cout << "Not Equals" << endl;
    }
}
void testAufgabe18()
{
    Wecker weaker(Time(12, 20, 30), Time(12, 20, 35));
    for (int i = 1; i <= 5; i++)
    {
        weaker.getTime().print();
        weaker.tick();
    }
}

void testAufgabe19()
{
    list<shared_ptr<Fahrzeug>> list;
    list.push_back(make_shared<Rennwagen>());
    list.push_back(make_shared<Rennwagen>());
    list.push_back(make_shared<Traktor>());
    list.push_back(make_shared<Traktor>());

    for (auto fahrzeug : list)
    {
        fahrzeug->fahren();
    }
}

void obst_zaehlen(vector<Obst *> korb)
{
    int anzahlApfel = 0, anzahlBirne = 0;
    for (Obst *o : korb)
    {
        if (o->typeOf() == APFEL)
        {
            anzahlApfel++;
        }
        if (o->typeOf() == BIRNE)
        {
            anzahlBirne++;
        }
    }
    cout << "Es gibt " << anzahlApfel << " Äpfel und " << anzahlBirne << " Birnen" << endl;
}

void testAufgabe21(vector<Obst *> korb)
{
    obst_zaehlen(korb);
}

int main()

{
    vector<Obst *> korb = {
        new Apfel(),
        new Apfel(),
        new Birne(),
        new Birne(),
        new Apfel()};
    testAufgabe21(korb);
    return 1;
}