#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "¬ведите n" << endl;
    cin >> n;

    int i = n;
    int res = 1;
    while (i>0)
    {
        res *= i;
        i -= 2;
    }

    cout << res;

    return 0;
}
