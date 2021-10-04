#include <iostream>

using namespace std;

bool func(int x, int y, int z)
{
    int counter = 0;
    if (x < 1001) counter++;
    if (y < 1001) counter++;
    if (z < 1001) counter++;
    return counter == 1;
}

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    cout << func(x,y,z) << endl;
}
