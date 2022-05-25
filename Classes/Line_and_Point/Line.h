#include "Point.h"

class Line{

    Point start, end;


    public:
    Line();
    Line(Point start, Point end);

    Point get_start(){
        return start;
    }

    Point get_end(){
        return end;
    }
    void operator+=(const Line &line);
    bool operator==(const Line &line);
    
};