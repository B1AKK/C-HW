#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "������� n" << endl;
    cin >> n;

    float res = 0;
    for (int i = 3*n; i > 0; i -= 3)
    {
        res = sqrt(i + res);
    }

    cout << res;

    return 0;
}
