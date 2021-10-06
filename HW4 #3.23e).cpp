#include <iostream>
#include <cmath>

using namespace std;

double isReLu(double a, double x)
{
    if (x<0) return x / sqrt(1+a*x*x);
    else return x;
}

double derivative_isReLu(double a, double x)
{
    const double eps = 0.0000000001;
    unsigned n = 1;
    double a0, a1;
    a1 = isReLu(a,x+1) - isReLu(a,x);
    do {
        a0 = a1;
        n++;
        a1 = n * (isReLu(a,x+ 1.0/n) - isReLu(a,x));

    } while (abs(a0-a1) >= eps);

    return a1;
}


int main()
{
    double a,x;
    cin >> a >> x;
    cout << isReLu(a,x) << endl << derivative_isReLu(a,x);
}
