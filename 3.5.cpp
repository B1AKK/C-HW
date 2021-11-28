#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;

    int maxab = (a + b + abs(a-b)) / 2;
    int minab = (a + b - abs(a-b)) / 2;

    cout << "Max: " << maxab << endl << "Min: " << minab;

    return 0;
}
