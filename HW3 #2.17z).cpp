#include <iostream>
#include <cmath>

using namespace std;

double sigmweight(double x)
{
    return x / (1 + exp(-x));
}

double derivative_sigmweight(float x)
{
    const double eps = 0.0000000001;
    unsigned n = 1;
    double a0, a1;
    a1 = sigmweight(x+1) - sigmweight(x);
    do {
        a0 = a1;
        n++;
        a1 = n * (sigmweight(x+ 1.0/n) - sigmweight(x));

    } while (abs(a0-a1) >= eps);

    return a1;
}

int main()
{
    cout << sigmweight(4) << endl << derivative_sigmweight(4) << endl;
}
