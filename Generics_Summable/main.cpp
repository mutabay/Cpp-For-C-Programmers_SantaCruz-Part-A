#include <iostream>
using namespace std;

template <class summable> //summable is a generic type
summable sum(const summable data[] ,int countOfSummables, summable s )
{
    s = 0;
    for (int i = 0; i < countOfSummables; ++i) {
        s+= data[i];
    }
    return s;
}
int main() {
    int countOfSummables = 5;
    int arr[countOfSummables];
    cout << "Please enter the summable numbers" << endl;
    for (int i = 0; i < countOfSummables; ++i) {
        cin >> arr[i];
    }

    int summation = sum(arr , countOfSummables, summation);

    cout << "summation is -> " << summation << endl;

    return 0;
}
