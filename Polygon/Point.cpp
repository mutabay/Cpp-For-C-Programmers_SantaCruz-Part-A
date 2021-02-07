//
// Created by tyyp- on 26.09.2020.
//

#include "Point.h"




//Operator overloading
#pragma region OperatorOverloading

// usual signature for overloading ostream& operator<<
// (ostream& out, const my_type& v)
// both arguments are passed by reference
// my_type is passed with a const modifier
// so as not to be modified.

Point operator+(const Point &p1, const Point &p2) {
    Point sum ( (p1.GetX() + p2.GetX() ) , ( p1.GetY() + p2.GetY() ) );
    return sum;
}

ostream &operator<<(ostream &out, const Point &p1) {
    out << "( " << p1.GetX() << " , " <<  p1.GetY() << " )" ;
    return out;
}
#pragma endregion OperatorOverloading
