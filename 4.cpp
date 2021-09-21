#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    float x;
    int n;
    cout << "¬ведите х и n" << endl;
    cin >> x >> n;


    float t = x, s = 0;
    for (int i=1; i<=n; i++)
    {
        s += t*i;
        t *= x;
    }

    cout << s;

    return 0;
}
