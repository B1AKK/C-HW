#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    double a,b,c;
    cin >> a >> b >> c;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0) cout << "all numbers" << endl;
            else cout << "no solutoins" << endl;
        }
        cout << "x = " << -c/b;
    }

    d = b*b - 4*a*c;

    if (d < 0)
    {
        cout << "Решений нет";
    }
    else if (d == 0)
    {
        x = (-b) / (2*a);
        cout << x;
    }
    else
    {
        x1 = (-b - sqrt(d)) / (2*a);
        x2 = (-b + sqrt(d)) / (2*a);
    }

    return 0;
}
