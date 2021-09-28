#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    float T;
    T = 365 + 1 / (4 + 1 / (7 + 1 / (1 + (float)1 / 3)));
    cout << T;
    return 0;
}
