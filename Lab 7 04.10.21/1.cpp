#include <iostream>

using namespace std;

int main()
{
    int arr[] = {5,6,9,8,7};
    int n;
    cin >> n;
    int counter = 0;
    for (int i=0; i<5; i++)
    {
        if (arr[i] < n) counter++;
    }
    cout << counter;
    return 0;
}
