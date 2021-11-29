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
    Poly(): deg(-1), coef(nullptr) {}
    Poly(unsigned n): deg(n), coef(new double[n+1]) {};
    Poly(unsigned n, double* arr): deg(n), coef(new double[n+1]) {memmove(coef, arr, (n+1)*sizeof(double));}

    friend istream& operator>>(istream& inp, Poly& p)
    {
        if (p.deg == -1)
        {
            cout << "Input deg: ";
            cin >> p.deg;
            p.coef = new double[p.deg+1];
        }
        for (int i=0; i<=p.deg; i++)
        {
            printf("coef[%d] = ", i);
            cin >> p.coef[i];
        }

        return inp;
    }

    void set_coef(unsigned n, double val)
    {
        if (n > deg) return;
        coef[n] = val;
    }

    friend ostream& operator<<(ostream& out, const Poly& p)
    {
        char buf[1024];

        for (int i=0; i<=p.deg; i++)
        {
            if (abs(p.coef[i]) < 0.00001) continue;
            sprintf(buf, "+%lfx^%d", p.coef[i], i);
            cout << buf;
        }
        return out;
    }

    double get_coef(unsigned n)
    {
        if (n > deg) return 0.0;
        return coef[n];
    }

    ~Poly() {delete[] coef;}

    friend void input_poly(string filename);

    friend void print_poly(string filename);

    Poly operator+(Poly& other)
    {
        Poly res(max(deg, other.deg));
        for (int i=0; i<=res.deg; i++) res.coef[i] = get_coef(i) + other.get_coef(i);
        return res;
    }

    Poly operator-(Poly& other)
    {
        Poly res(max(deg, other.deg));
        for (int i=0; i<=res.deg; i++) res.coef[i] = get_coef(i) - other.get_coef(i);
        return res;
    }

    Poly operator*(Poly& other)
    {
        Poly res(deg+other.deg);
        double s;
        for (int i=0; i<=res.deg; i++)
        {
            s = 0;
            for (int j=0; j<=i; j++) s += get_coef(j)*other.get_coef(i-j);
            res.coef[i] = s;
        }
        return res;
    }

};

void input_poly(string filename)
{
    Poly p;
    cin >> p;

    FILE* f = fopen(filename.c_str(), "w");
    fwrite(&p.deg, sizeof(unsigned), 1, f);
    fwrite(p.coef, sizeof(*p.coef), p.deg+1, f);
    fclose(f);
}

void print_poly(string filename)
{
    unsigned n;
    double* arr;

    FILE* f = fopen(filename.c_str(), "r");
    fread(&n, sizeof(unsigned), 1, f);
    arr = new double[n+1];
    fread(arr, sizeof(double), n+1, f);
    for (int i=0; i<=n; i++) cout << arr[i] << endl;
    fclose(f);
    cout << Poly(n, arr) << endl;
    delete[] arr;
}

int main()
{
    double arr[4] = {1,2,3.6,28};
    Poly p1, p2(3,arr), p3;
    cin >> p1 >> p3;
    p2.set_coef(1,-0.58);
    cout << p2 << endl;

    cout << p3+p1 << endl << p3-p1 << endl << p3*p1 << endl;
    string filename = "oiajfshijh";
    input_poly(filename);
    print_poly(filename);
}
