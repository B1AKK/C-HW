#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

class Triangle
{
    double alpha, b, c;

private:
    double betha, gamma, a, perimeter, area;

    void solve()
    {
        a = sqrt(b*b + c*c - 2*b*c*cos(alpha));
        betha = acos( (a*a + c*c - b*b) / (2*a*c) );
        gamma = acos( (a*a + b*b - c*c) / (2*a*b) );
        perimeter = a+b+c;
        area = a*b*sin(gamma)/2;
    }

public:
    Triangle(double angle, double s1, double s2): alpha(angle), b(s1), c(s2)
    {
        this->solve();
    }

    double get_a() {return a;}
    double get_b() {return b;}
    double get_c() {return b;}
    double get_alpha() {return alpha;}
    double get_betha() {return betha;}
    double get_gamma() {return gamma;}
    double get_perimeter() {return perimeter;}
    double get_area() {return area;}
    void print_angles()
    {
        printf("%lf\n%lf\n%lf\n", alpha,betha, gamma);
    }

    void print_sides()
    {
        printf("%lf\n%lf\n%lf\n", a,b,c);
    }
};

int main()
{
    Triangle tr(M_PI/3,20,20);
    cout << tr.get_a() << endl;
    cout << tr.get_perimeter() << endl;
    tr.print_angles();
    tr.print_sides();
}
