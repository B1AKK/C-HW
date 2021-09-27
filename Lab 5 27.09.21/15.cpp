#include <iostream>
#include <cmath>

using namespace std;

float sin(float x, float eps)
{
    float t = x, s = 0;
    int n = 1;
    while (abs(t) >= eps)
    {
        s += t;
        t = -t*x*x/(2*n*(2*n+1));
        n++;
    }

    return s;
}

int main()
{
    float x, eps;
    cin >> x;

    do {
        cin >> eps;
    } while (eps <= 0);

    cout << sin(x, eps) << endl << sin(x);
}
