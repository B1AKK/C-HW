#include <iostream>
#include <stdio.h>

using namespace std;

bool input_vect(float* vect, unsigned n)
{
    if (n >= 20)
    {
        cout << "n must be < 20";
        return 1;
    }
    for (int i=0; i<n; i++)
    {
        printf("vect[%d] = ", i+1);
        cin >> vect[i];
    }
    return 0;
}

void show_vect(float* vect, unsigned n)
{
    for (int i=0; i<n; i++)
    {
        cout << vect[i];
    }
}

void add_vectors(const float* a, const float* b, float* sum, unsigned n)
{
    for (int i=0; i<n; i++)
    {
        sum[i] = a[i]+b[i];
    }
}

float dot_prod(const float* a, const float* b, unsigned n)
{
    float res = 0;
    for (int i=0; i<n; i++)
    {
        res += a[i] * b[i];
    }
    return res;
}

int main()
{
    unsigned n = 5;
    float a[n], b[n], sum[n];
    input_vect(a,n);
    input_vect(b,n);
    add_vectors(a,b,sum,n);
    show_vect(sum,n);
}
