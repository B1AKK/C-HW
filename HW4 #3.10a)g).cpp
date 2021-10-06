#include <iostream>

using namespace std;



int main()
{
    float x,y,z;
    cin >> x >> y >> z;
    int res;
    if (x==y && y==z) res=1;
    else if ( (x==y && y!=z) || (x==z && z!=y) || (y==z && y!=x) ) res=2;
    else res=3;
    cout << "a) " << res << endl << "input a: ";
    float a;
    cin >> a;
    res = 0;
    if (x>a) res++;
    if (y>a) res++;
    if (z>a) res++;
    cout << "b) " << res;
}
