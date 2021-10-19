#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

struct Rational
{
    int num;
    unsigned int denom;
};

void reduce(Rational* a)
{
    int d = gcd(a->num, a->denom);
    a->num /= d;
    a->denom /= d;
}

void inp_rational(Rational* a)
{
    cout << "Numerator: ";
    cin >> a->num;
    cout << "Denominator: ";
    cin >> a->denom;
}

void print_rational(Rational a)
{
    if (a.denom == 1) cout << a.num;
    else printf("%d/%u\n", a.num, a.denom);
}

Rational sum(Rational a, Rational b)
{
    Rational res;
    res.num = a.num * b.denom + a.denom * b.num;
    res.denom = a.denom * b.denom;
    reduce(&res);
    return res;
}

Rational prod(Rational a, Rational b)
{
    Rational res;
    res.num = a.num*b.num;
    res.denom = a.denom*b.denom;
    reduce(&res);
    return res;
}

bool cmp_abs(Rational a, Rational b)
{
    return abs(a.num) * b.denom > abs(b.num) * a.denom;
}

bool cmp_rational(Rational a, Rational b)
{
    if (a.num > 0 && b.num > 0) return cmp_abs(a,b);
    else if (a.num > 0 && b.num < 0) return 1;
    else if (a.num < 0 && b.num > 0) return 0;
    else return !cmp_abs(a,b);
}

int main()
{
    Rational a,b;
    inp_rational(&a); inp_rational(&b);
    print_rational(sum(a,b));
    print_rational(prod(a,b));

    cout << cmp_rational(a,b) << endl;
}
