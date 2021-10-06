#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long double a0, a1, a, b0, b1, b, s;
    unsigned n;
    a0 = 1;
    a1 = 2;
    b0 = 5;
    b1 = 5;
    s = a1/b1;
    cin >> n;
    for (int k=2; k<=n; k++)
    {
        b = b0*b0 - a1;
        a = b0 + b/2;
        s += pow(a/b, k);
        a0 = a1;
        a1 = a;
        b0 = b1;
        b1 = b;
    }

    cout << s;
}
