#include "Point.h"

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y): x(x), y(y) {}

void Point::operator+=(const Point &point)
{
    this->x += point.x;
    this->y += point.y;
}

bool Point::operator==(const Point &point)
{
    return this->x == point.x && this->y == point.y;
}