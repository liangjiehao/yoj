#include <iostream>
#include <math.h>

using namespace std;

class Point
{
public:
    Point(double x, double y);
    Point(const Point &p);
    double getX() const;
    double getY() const;
protected:
    double _x, _y;
};

Point::Point(double x, double y):_x(x), _y(y){
}

Point::Point(const Point &p):_x(p._x), _y(p._y){
}

double Point::getX() const
{
    return this->_x;
}

double Point::getY() const
{
    return this->_y;
}

class Rectangle{
public:
    Rectangle(const Point & lb, const Point & rt);
    //____qcodep____
    Point getLB() const {return _lb;}
    Point getRT() const {return _rt;}
    Rectangle operator + (const Rectangle & r2);
    //

 private:
    Point _lb, _rt;
};
//____qcodep____

Rectangle::Rectangle(const Point & lb, const Point & rt):_lb(lb),_rt(rt){};

Rectangle Rectangle::operator+(const Rectangle & r2){
    double x1,y1,x2,y2;
    x1=getRT().getX() >= r2.getRT().getX() ? getRT().getX() : r2.getRT().getX();
    y1=getRT().getY() >= r2.getRT().getY() ? getRT().getY() : r2.getRT().getY();
    x2=getLB().getX() <= r2.getLB().getX() ? getLB().getX() : r2.getLB().getX();
    y2=getLB().getY() <= r2.getLB().getY() ? getLB().getY() : r2.getLB().getY();
    return Rectangle(Point (x2,y2),Point (x1,y1));
}

//
 
void printRectangle(Rectangle rec){
    cout<<rec.getLB().getX()<<" "<<rec.getLB().getY()<<endl;
    cout<<rec.getRT().getX()<<" "<<rec.getRT().getY()<<endl;
}

int main()
{
    double x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    Rectangle r1(Point(x1,y1), Point(x2,y2));
    cin>>x1>>y1>>x2>>y2;
    Rectangle r2(Point(x1,y1), Point(x2,y2));
    Rectangle r3 = r1 + r2;
    printRectangle(r3);
    return 0;
}
