#include <iostream>
#include <float.h>

using namespace std;

int main()
{
    float max_negative = -FLT_MAX, min_positive = FLT_MAX, x;


    do {
        cin >> x;
        if (x > 0 and x < min_positive) min_positive = x;
        else if (x < 0 and x > max_negative) max_negative = x;


    } while(x != 0);

    if (max_negative != -FLT_MAX) cout << max_negative;
    else cout << min_positive;
}
