//
// Created by tyyp- on 26.09.2020.
//

#ifndef POLYGON_POINT_H
#define POLYGON_POINT_H

#include <ostream>
#include <math.h>
using namespace std;


class Point {
private:
    int x,y;

public:
    Point()
    {
        x = 0;y = 0;
    }
    Point(int x, int y )
    {
        this->x = x;
        this->y = y;
    }

    int GetX() const { return x;}
    void SetX(int x){ this->x = x;}

    int GetY() const { return y;}
    void SetY(int y){ this->y = y;}

    //Finds distance between two points.
    double FindDistance( Point& p2)
    {
        int xDifference = abs(this->x - p2.x);
        int yDifference = abs( this->y - p2.y);

        double distance =  sqrt( pow(xDifference,2) + pow( yDifference, 2)) ;
        return distance;
    }
};

Point operator+(const Point &p1, const Point &p2);
ostream &operator<<(ostream &out, const Point &p1);

#endif //POLYGON_POINT_H
