#include <iostream>
#include <cmath>

using namespace std;

typedef struct Point
{
    double x1, x2;
    bool type; //0 - cart, 1 - polar
};

Point pol2cart(Point p)
{
    if (!p.type) return p;

    Point res;
    res.type = 0;
    res.x1 = p.x1*cos(p.x2);
    res.x2 = p.x1 * sin(p.x2);
    return res;
}

Point cart2pol(Point p)
{
    if (p.type) return p;

    Point res;
    res.type = 1;
    res.x1 = sqrt(p.x1*p.x1 + p.x2*p.x2);
    if (res.x1 == 0)
    {
        res.x2 = 0;
        return res;
    }
    res.x2 = atan(p.x2/p.x1);
    if (p.x1/res.x1 < 0) res.x2 += M_PI;

    return res;
}

double length(Point a, Point b)
{
    a = pol2cart(a); b = pol2cart(b);
    double dx = a.x1 - b.x1;
    double dy = a.x2 - b.x2;
    return sqrt(dx*dx + dy*dy);
}

double perimeter(Point a, Point b, Point c)
{
    return length(a,b) + length(b,c) + length(a,c);
}

int main()
{
    Point a,b,c;
    a = {3,4,0};
    b = {3,0,1};
    c = {0,0,1};
    cout << perimeter(a,b,c) << endl;
}
