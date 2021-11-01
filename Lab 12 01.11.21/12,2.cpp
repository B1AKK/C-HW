#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    unsigned long tmp;
    unsigned long long res;
    char str[2];
    for (int i=0; i<n; i++)
    {
        tmp = 0;
        for (int j=0; j<10; j++)
        {
            cin.get(str, 1);
            tmp = tmp*10 + atoi(str);
        }
        res += tmp;
    }
    cout << res << endl;
}
