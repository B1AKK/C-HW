#include <iostream>

using namespace std;

int main()
{
    double x, eps, t, s;
    unsigned n = 0;
    do {
        cout << "input x!= ";
        cin >> x;
    } while (x==0);
    do {
        cout << "input eps > 0: ";
        cin >> eps;
    } while (eps <= 0);

    s = 0;
    t = x;
    do {
        s += t;
        n++;
        t *= -x*x / (n * 2 * n * (2*n+1));
    } while (abs(t) >= eps);

    cout << s;
}
