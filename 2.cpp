#include <iostream>

using namespace std;

int main()
{
    int n;
    unsigned int k;
    cin >> n >> k;
    n = n >> (k-1) | 1 << (k-1) | n;
    cout << n;

    return 0;
}
