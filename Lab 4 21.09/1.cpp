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

    for (int i=0; i<n; i++)
    {
        x = sin(x);
    }

    cout << x;

    return 0;
}
