#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

float* inp_vect(unsigned n)
{
    float* vect = (float*)malloc(sizeof(float) * n);
    for (int i=0; i<n; i++)
    {
        printf("vect[%d] = ", i+1);
        cin >> vect[i];
    }
    return vect;
}

float* subtract(float* a, float* b, unsigned n)
{
    float* res = (float*) malloc(sizeof(float) * n);
    for (int i=0; i<n; i++)
    {
        res[i] = a[i] - b[i];
    }
    return res;
}

int main()
{
    unsigned n;
    cin >> n;
    float *a, *b, *c;
    a = inp_vect(n);
    b = inp_vect(n);
    c = subtract(a,b,n);
    for (int i=0; i<n; i++) printf("c[%d] = %f\n", i+1, c[i]);
    free(a); free(b); free(c);
}
