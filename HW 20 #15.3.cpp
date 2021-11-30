#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

class Poly
{
    unsigned deg;
    double* coef;

public:
    Poly(): deg(0), coef(nullptr) {}
    Poly(unsigned n): deg(n), coef(new double[n]) {};
    Poly(unsigned n, double* arr): deg(n), coef(new double[n]) {memmove(coef, arr, n*sizeof(double));}

    friend istream& operator>>(istream& inp, Poly& p)
    {
        if (!p.deg)
        {
            cout << "Input N: ";
            cin >> p.deg;
            p.coef = new double[p.deg];
        }
        for (int i=0; i<p.deg; i++)
        {
            printf("coef[%d] = ", i);
            cin >> p.coef[i];
        }

        return inp;
    }

    void set_coef(unsigned n, double val)
    {
        coef[n] = val;
    }

    friend ostream& operator<<(ostream& out, const Poly& p)
    {
        char buf[1024];

        for (int i=0; i<p.deg; i++)
        {
            sprintf(buf, "+%lfx^%d", p.coef[i], i);
            cout << buf;
        }
        return out;
    }

    ~Poly() {delete[] coef;}

    friend void input_poly(string filename);


    friend void print_poly(string filename);

};

void input_poly(string filename)
{
    Poly p;
    cin >> p;

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
    cout << Poly(n, arr) << endl;
    delete[] arr;
}

int main()
{
    double arr[4] = {1,2,3.6,28};
    Poly p1, p2(4,arr);
    cin >> p1;
    p2.set_coef(1,-0.58);
    cout << p2 << endl;
    cout << p1 << endl;
    string filename = "oiajfshijh";
    input_poly(filename);
    print_poly(filename);
}
