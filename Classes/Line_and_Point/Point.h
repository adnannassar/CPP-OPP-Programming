#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x, y;

public:
    Point(); 
    Point(int x, int y);

    const int getX()
    {
        return x;
    }
    const int getY()
    {
        return y;
    }

    void operator+=(const Point &point);
    bool operator==(const Point &point);
};

#endif
