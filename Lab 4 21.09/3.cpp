#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    float x, y;
    int n;
    cout << "������� � � n" << endl;
    cin >> x >> n;

    float s = 0;
    float t = 1;
    for (int i=0; i<=n; i++)
    {
        s += t;
        t *= x;
    }

    cout << s <<endl;

    cout << "������� �, y, n" << endl;
    cin >> x >> y >> n;
    s = 1;
    t = y;
    float r = x*x;
    for (int i=1; i<=n; i++)
    {
        s += t*r;
        t *= y;
        r *= r;
    }

    cout << s << endl;
    return 0;
}
