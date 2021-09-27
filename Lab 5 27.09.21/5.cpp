#include <iostream>

using namespace std;

int main()
{
    int x1,x2,x3, x;
    x1=-99; x2=-99; x3=-99;
    int k = 3;
    do {
        x = x3 + x1 + 100;
        x1 = x2;
        x2 = x3;
        x3 = x;
        k++;
    } while (x <= 0);

    cout << k << endl << x << endl;

    return 0;
}
