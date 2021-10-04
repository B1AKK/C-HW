#include <iostream>
#include <stdio.h>
#include <cmath>

#define LEN 10

using namespace std;

void input_arr(unsigned* arr, int len)
{
    for (int i=0; i<len; i++)
    {
        printf("arr[%d] = ", i+1);
        cin >> arr[i];
    }
}

int even_sum(unsigned arr[], int len)
{
    int res = 0;
    for (int i=0; i<len; i++)
    {
        if (arr[i] % 2 == 0) res += arr[i];
    }
    return res;
}

int odd_sum(unsigned arr[], int len)
{
    int res = 0;
    for (int i=0; i<len; i++)
    {
        if (arr[i] % 2 != 0) res += arr[i];
    }
    return res;
}

int main()
{
    unsigned arr[LEN];
    input_arr(arr, LEN);
    cout << "Number of even numbers: " << even_sum(arr, LEN) << endl;
    cout << "Number of odd numbers: " << odd_sum(arr, LEN) << endl;
}
