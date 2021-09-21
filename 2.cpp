#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cout << "¬ведите n" << endl;
    cin >> n;

    printf("%d! = ", n);

    for (int i=1; i<n; i++)
    {
        printf("%d*", i);
    }
    cout << n << endl;


    printf("%d! = ", n);

    for (int i=n; i>1; i--)
    {
        printf("%d*", i);
    }
    cout << 1;
}
