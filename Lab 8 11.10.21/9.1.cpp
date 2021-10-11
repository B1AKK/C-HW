#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void inp_arr(float* arr, unsigned n)
{
    for (int i=0; i<n; i++)
    {
        printf("arr[%d] = ", i);
        cin >> arr[i];
    }
}

float squares_sum(float* arr, unsigned n)
{
    float res = 0;
    for (int i = 0; i < n; i++)
    {
        res += arr[i]*arr[i];
    }
    return res;
}

int main()
{
    unsigned n;
    cin >> n;
    float* arr = (float*)malloc(sizeof(float) * n);
    inp_arr(arr, n);
    cout << squares_sum(arr, n) << endl;
    free(arr);
}
