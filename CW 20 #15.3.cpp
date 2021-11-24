#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

void cpy_arr(double* dest, double* inp, unsigned n)
{
    for (int i=0; i<n; i++) dest[i] = inp[i];
}

class Poly
{
    unsigned deg;
    double* coef;

public:
    Poly(): deg(0), coef(nullptr) {}
    Poly(unsigned n): deg(n), coef(new double[n]) {};
    Poly(unsigned n, double* arr): deg(n), coef(new double[n]) {cpy_arr(coef, arr, n);}

    void input()
    {
        if (!deg)
        {
            cout << "Input N: ";
            cin >> deg;
            coef = new double[deg];
        }
        for (int i=0; i<deg; i++)
        {
            printf("coef[%d] = ", i);
            cin >> coef[i];
        }
    }

    void set_coef(unsigned n, double val)
    {
        coef[n] = val;
    }

    void show()
    {
        for (int i=0; i<deg; i++) printf("+%lfx^%d", coef[i], i);
        cout << endl;
    }

    ~Poly() {delete[] coef;}

    friend void input_poly(string filename);


    friend void print_poly(string filename);

};

void input_poly(string filename)
{
    Poly p;
    p.input();

    FILE* f = fopen(filename.c_str(), "w");
    fwrite(&p.deg, sizeof(unsigned), 1, f);
    fwrite(p.coef, sizeof(*p.coef), p.deg, f);
    fclose(f);
}

void print_poly(string filename)
{
    unsigned n;
    double* arr;

    FILE* f = fopen(filename.c_str(), "r");
    fread(&n, sizeof(unsigned), 1, f);
    arr = new double[n];
    fread(arr, sizeof(double), n, f);
    for (int i=0; i<n; i++) cout << arr[i] << endl;
    fclose(f);
    Poly(n, arr).show();
    delete[] arr;
}

int main()
{
    double arr[4] = {1,2,3.6,28};
    Poly p1, p2(4,arr);
    p1.input();
    p2.set_coef(1,-0.58);
    p2.show();
    p1.show();
    string filename = "oiajfshijh";
    input_poly(filename);
    print_poly(filename);
}
