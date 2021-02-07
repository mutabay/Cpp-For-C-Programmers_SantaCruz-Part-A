#include <iostream>

using namespace std;

typedef enum days{SUN, MON, TUE, WED, THU, FRI, SAT}
days;
//We can say "days" instead of "enum days".

// Operator overloading.
//adding 1 to the days. So day will begin 1 index.
//The prefix auto-increment is being overloaded. The expectation is the argument is changed to be one greater and its value returned.
inline days operator++( days day)
{
    return static_cast<days>( ( (static_cast<int>(day) + 1 )% 7 ) );
}

//Writing days on the enums
ostream& operator<< (ostream& out, days day)
{
    switch (day)
    {
        case SUN: out << "SUN" ;
            break;
        case MON: out << "MON" ;
            break;
        case TUE: out << "TUE" ;
            break;
        case WED: out << "WED" ;
            break;
        case THU: out << "THU" ;
            break;
        case FRI: out << "FRI" ;
            break;
        case SAT: out << "SAT" ;
            break;
    }
    return out;
}


int main() {

    days d = MON;
    days e;
    //using operator++ overload
    e = ++d;
    //using operator<< overload
    cout << e << endl;
    //same ´,
    operator<<(cout ,MON);

    return 0;
}
