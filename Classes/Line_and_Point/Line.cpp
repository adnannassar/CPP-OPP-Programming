#include "Line.h"

Line::Line() : start(Point()), end(Point()) {}

Line::Line(Point start, Point end) : start(start), end(end) {}

void Line::operator+=(const Line &line)
{
    this->start += line.start;
    this->end += line.end;
}
bool Line::operator==(const Line &line)
{
    return this->start == line.start && this->end == line.end;
}