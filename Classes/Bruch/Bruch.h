#include <iostream>
class Bruch
{
private:
    int zaehler, nenner;

public:
    Bruch(int zaehler, int nenner = 1);

    const int getZaehler()
    {
        return zaehler;
    }
    const int getNenner()
    {
        return nenner;
    }

    void setZaehler(int zaehler)
    {
        this->zaehler = zaehler;
    }
    void setNenner(int nenner)
    {
        this->nenner = nenner;
    }

    bool operator==(const Bruch &bruch);
    bool operator!=(const Bruch &bruch);
    void operator*=(const Bruch &bruch);
    int ggt(int a, int b)
    {
        while (a != 0)
        {
            std::swap(a, b);
            a %= b;
        }
        return b;
    }
};
inline Bruch operator*(int n, Bruch bruch)
{

    Bruch erg(bruch.getZaehler() * n, bruch.getNenner());
    return erg;
}

inline std::ostream &operator<<(std::ostream &out, Bruch bruch)
{
    int ggt = bruch.ggt(bruch.getZaehler(), bruch.getNenner());
    bruch.setZaehler(bruch.getZaehler() / ggt);
    bruch.setNenner(bruch.getNenner() / ggt);

    if (bruch.getNenner() == 1)
    {
        out << bruch.getZaehler();
        return out;
    }
    else if (bruch.getZaehler() == bruch.getNenner())
    {
        out << "1";
        return out;
    }
    else
    {
        out << bruch.getZaehler() << "/" << bruch.getNenner();
        return out;
    }
}