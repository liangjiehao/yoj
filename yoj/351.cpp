#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;

class Point;
class MyCircle;

class Point
{
    //____qcodep____ 

    //
public : 
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double xx, double yy)
    {
        x = xx;
        y = yy;
    }
    double getX0() { return x; }
    double getY0() { return y; }

    //____qcodep____
    friend MyCircle;
    friend double Distance(Point &a, Point &b);
    //
private : 
    double x, y;
};

class MyCircle
{
public:
    MyCircle(double r, int i);
    void setCir(double x, double y, double r);

public:
    double getS()
    {
        m_s = PI * m_r * m_r;
        return m_s;
    };

private:
    //____qcodep____ 
    Point MidP;

    //
    double m_r; //圆半径
    double m_s;
    const int id;
};
MyCircle::MyCircle(double r, int i) : m_r(r), m_s(i),id(i)//____qcodep____
{
    MidP.x = 0;
    MidP.y = 0;
}

void MyCircle::setCir(double x, double y, double r)
{
    MidP.x = x;
    MidP.y = y;
    m_r = r;
}

double Distance(Point &a, Point &b)
{
    //____qcodep____ 
    double dx=a.x-b.x;

    //
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main(void)
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point p1(x1, y1), p2(x2, y2);
    double d = Distance(p1, p2);
    cout << d << endl;
    MyCircle c1(d / 2, 10001);
    cout << c1.getS();
    return 0;
}
