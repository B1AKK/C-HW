#include <iostream>
#include <cmath>

using namespace std;

class Point
{
    private:
        double x, y;
        static unsigned counter;

    public:

        Point() {}
        Point(double a, double b): x(a), y(b) {counter++;}

        void input()
        {
            cout << "x coord: ";
            cin >> x;
            cout << "y coord: ";
            cin >> y;
            counter++;
        }

        double getx() {return x;}
        double gety() {return y;}

        static unsigned get_count() {return counter;}
};

double len(Point a, Point b)
{
    double xa = a.getx(), ya = a.gety();
    double xb = b.getx(), yb = b.gety();
    double dx = xa-xb, dy = ya-yb;
    return sqrt(dx*dx + dy*dy);
}

unsigned Point::counter = 0;

int main()
{
    int ans;
    Point first, cur, prev;
    cout << "?" << endl;
    cin >> ans;
    if (!ans)
    {
        cout << "no input";
        return 0;
    }
    first.input();
    prev = first;

    cout << "?" << endl;
    cin >> ans;
    double p = 0;
    while (ans)
    {
        cur.input();
        p += len(cur, prev);
        prev = cur;
        cout << "?" << endl;
        cin >> ans;
    }
    if (Point::get_count() > 1) p += len(cur, first);
    cout << Point::get_count() << endl << p << endl;
}
