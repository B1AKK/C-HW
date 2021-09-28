#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    float a = 1;
    while (1 + a != 1)
    {
        a /= 2;
    }
    cout << a <<  endl << FLT_EPSILON;

    return 0;
}
