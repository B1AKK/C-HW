#include <iostream>
#include <float.h>
#include <cmath>

using namespace std;

float func(unsigned n, float x)
{
    if (x<=0 or x>=1)
    {
        cout << "Forbidden value for x" << endl;
        return FLT_MAX;
    }
    float t = x*pow(1-x, n-1);
    float s = 0;
    for (int i = 1; i<=n; i++)
    {
        s += i*t;
        t *= x/(1-x);
    }
    return s;
}

int main()
{
    cout << func(10,0.3) << endl << func(26,0.27);
}
