#include <iostream>
#include "Point.h"

using namespace std;

int main() {

    Point p1 = Point(2,4);
    Point p2 = Point(4,5);
    Point sum = p1 + p2;


    cout << "First point is -> "<< p1 << endl;
    cout << "Second point is -> "<< p2 << endl;
    cout << "Sum point is -> "<< sum << endl;
    cout << "Distance between p1 and p2 is  "<< p1.FindDistance(p2) << endl;


    return 0;
}
