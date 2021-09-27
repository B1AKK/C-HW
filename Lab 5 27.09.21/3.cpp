#include <iostream>
#include <stdint.h>

using namespace std;

int main()
{
    uint16_t n;
    cin >> n;

    n = (n << 8) + (n >> 8);
    cout << n;

    return 0;
}
