#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

unsigned inp_arr(int* arr)
{
    unsigned n;
    int tmp;
    for (n = 0; n<100; n++)
    {
        cin >> tmp;
        if (!tmp) return n;
        arr[n] = tmp;
    }
    return n;
}

bool is_cube(int n)
{
    n = abs(n);
    int a = 0;
    while (a*a*a < n) a++;
    return a*a*a == n;
}

bool is_square(int n)
{
    if (n < 0) return 0;

    int a=0;
    while (a*a < n) a++;
    return a*a == n;
}

unsigned cubes(int* arr, unsigned n)
{
    unsigned res = 0;
    for (int i=0; i<n; i++)
    {
        if (is_cube(arr[i])) res++;
    }
    return res;
}

unsigned squares(int* arr, unsigned n)
{
    unsigned res = 0;
    for (int i=0; i<n; i++)
    {
        if (is_square(arr[i])) res++;
    }
    return res;
}

int main()
{
    int* arr = (int*)malloc(sizeof(int)*100);
    unsigned n = inp_arr(arr);
    cout << "Cubes: " << cubes(arr, n) << endl << "Squares: " << squares(arr, n) << endl;
    free(arr);
}
