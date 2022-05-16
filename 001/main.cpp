#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <iomanip>

using namespace std;
int add(int x, double y);
double add(double x, int y);

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void init(int day, int month, int year);
    void add_year(int n);
    void add_month(int n);
    void add_day(int n);
    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }
};


int main()
{
    Date today;
    
    
    Date* dtr = new Date;
    
    return 1;
}

int add(int x, double y)
{
    return x + y;
}
double add(double x, int y)
{
    return x + y;
}
