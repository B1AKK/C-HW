#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    double max = a;
    if (abs(b) > abs(max)) max = b;
    if (abs(c) > abs(max)) max = c;
    cout << max << endl;

    return 0;
}
