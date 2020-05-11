#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Point{
public:
    Point(double x,double y);
    Point(const Point & p);
    double getX();
    double getY();
private:
    double _x;
    double _y;
};
Point::Point(double x,double y){
    this->_x=x;
    this->_y=y;
}
Point::Point(const Point & p){
    this->_x=p._x;
    this->_y=p._y;
}
double Point::getX(){
    return this->_x;
}
double Point::getY(){
    return this->_y;
}

class Line{
public:
    Line(Point pot1,Point pot2);
    Line(const Line & l);
    double getLen();
    double maxX();
    double minX();
    double maxY();
    double minY();
    double xielv();
private:
    Point _pot1;
    Point _pot2;
    double _len;
};
Line::Line(Point pot1,Point pot2):_pot1(pot1),_pot2(pot2){
    double difx=(_pot1.getX()-_pot2.getX())*(_pot1.getX()-_pot2.getX());
    double dify=(_pot1.getY()-_pot2.getY())*(_pot1.getY()-_pot2.getY());
    this->_len=sqrt(difx+dify);
}
Line::Line(const Line & l):_pot1(l._pot1),_pot2(l._pot2){
    this->_len=l._len;
}
double Line::getLen(){
    return this->_len;
}
double Line::maxX(){
    if(_pot1.getX()>_pot2.getX()){
        return _pot1.getX();
    }
    else{
        return _pot2.getX();
    }
}
double Line::minX(){
    if(_pot1.getX()<_pot2.getX()){
        return _pot1.getX();
    }
    else{
        return _pot2.getX();
    }
}
double Line::maxY(){
    if(_pot1.getY()>_pot2.getY()){
        return _pot1.getY();
    }
    else{
        return _pot2.getY();
    }
}
double Line::minY(){
    if(_pot1.getY()<_pot2.getY()){
        return _pot1.getY();
    }
    else{
        return _pot2.getY();
    }
}
double Line::xielv(){
    double difx=_pot1.getX()-_pot2.getY();
    double dify=_pot1.getY()-_pot2.getY();
    if(difx==0||dify==0){
        return 0;
    }
    else{
        return dify/difx;
    }
}

class Quadrilateral{
public:
    Quadrilateral(vector<Point> vertices):_vertices(vertices){}
    double getArea();
    double getPerimeter();
    bool verify();
    //检查构造该对象时输入的四个顶点是否可以构成合法的四边形

private:
    vector<Point> _vertices;
};
double Quadrilateral::getArea(){
    double maxx=_vertices.at(0).getX(),minx=_vertices.at(0).getX();
    double maxy=_vertices.at(0).getY(),miny=_vertices.at(0).getY();
    for(int i=1;i<=3;i++){
        if(_vertices.at(i).getX()>maxx){
            maxx=_vertices.at(i).getX();
        }
        if(_vertices.at(i).getX()<minx){
            minx=_vertices.at(i).getX();
        }
        if(_vertices.at(i).getY()>maxy){
            maxy=_vertices.at(i).getY();
        }
        if(_vertices.at(i).getY()<miny){
            miny=_vertices.at(i).getY();
        }
    }
    return (maxx-minx)*(maxy-miny)/2;
}
double Quadrilateral::getPerimeter(){
    double difx1=_vertices.at(0).getX()-_vertices.at(1).getX();
    double dify1=_vertices.at(0).getY()-_vertices.at(1).getY();
    double len1=sqrt(difx1*difx1+dify1*dify1);
    double difx2=_vertices.at(1).getX()-_vertices.at(2).getX();
    double dify2=_vertices.at(1).getY()-_vertices.at(2).getY();
    double len2=sqrt(difx2*difx2+dify2*dify2);
    double difx3=_vertices.at(2).getX()-_vertices.at(3).getX();
    double dify3=_vertices.at(2).getY()-_vertices.at(3).getY();
    double len3=sqrt(difx3*difx3+dify3*dify3);
    double difx4=_vertices.at(3).getX()-_vertices.at(0).getX();
    double dify4=_vertices.at(3).getY()-_vertices.at(0).getY();
    double len4=sqrt(difx4*difx4+dify4*dify4);
    return len1+len2+len3+len4;
}
bool Quadrilateral::verify(){
    if(_vertices.at(0).getX()==_vertices.at(1).getX()&&_vertices.at(0).getX()==_vertices.at(2).getX()){
        return false;
    }
    else if(_vertices.at(0).getX()==_vertices.at(1).getX()&&_vertices.at(0).getX()==_vertices.at(3).getX()){
        return false;
    }
    else if(_vertices.at(0).getX()==_vertices.at(2).getX()&&_vertices.at(0).getX()==_vertices.at(3).getX()){
        return false;
    }
    else if(_vertices.at(1).getX()==_vertices.at(2).getX()&&_vertices.at(1).getX()==_vertices.at(3).getX()){
        return false;
    }
    else{
        double difx1=_vertices.at(0).getX()-_vertices.at(1).getX();
        double dify1=_vertices.at(0).getY()-_vertices.at(1).getY();
        double k1=dify1/difx1;
        double difx2=_vertices.at(1).getX()-_vertices.at(2).getX();
        double dify2=_vertices.at(1).getY()-_vertices.at(2).getY();
        double k2=dify2/difx2;
        double difx3=_vertices.at(2).getX()-_vertices.at(3).getX();
        double dify3=_vertices.at(2).getY()-_vertices.at(3).getY();
        double k3=dify3/difx3;
        double difx4=_vertices.at(3).getX()-_vertices.at(0).getX();
        double dify4=_vertices.at(3).getY()-_vertices.at(0).getY();
        double k4=dify4/difx4;
        if(k1==k2&&k1==k3){
            return false;
        }
        else if(k1==k2&&k1==k4){
            return false;
        }
        else if(k1==k3&&k1==k4){
            return false;
        }
        else if(k2==k3&&k2==k4){
            return false;
        }
        else{
            return true;
        }
    }
}

class Parallelogram: public Quadrilateral{
public:
    //Parallelogram(vector<Point> vertices):_vertices(vertices){}
    //Parallelogram(vector<Point> vertices1,vector<Point> vertices):Quadrilateral(vertices1),_vertices(vertices){}
    Parallelogram(vector<Point> vertices1):Quadrilateral(vertices1),_vertices(vertices1){}
    
    //double getArea(){
    //    return Quadrilateral::getArea();
    //}
    //double getPerimeter();
    //bool verify();
    //Parallelogram(vector<Point> vertices){
    //    Quadrilateral(vector<Point> vertices);
    //}
    //bool verify();
    //检查构造该对象时输入的四个顶点是否可以构成合法的四边形

private:
    vector<Point> _vertices;
};

int main(){
    double quax1,quay1,quax2,quay2,quax3,quay3,quax4,quay4;
    cin>>quax1>>quay1>>quax2>>quay2>>quax3>>quay3>>quax4>>quay4;
    Point p1(quax1,quay1);
    Point p2(quax2,quay2);
    Point p3(quax3,quay3);
    Point p4(quax4,quay4);
    vector<Point> pot;
    pot.push_back(p1);
    pot.push_back(p2);
    pot.push_back(p3);
    pot.push_back(p4);
    /*
    Quadrilateral sibianxing(pot);
    if(sibianxing.verify()){
        cout<<sibianxing.getArea()<<endl;
        cout<<sibianxing.getPerimeter()<<endl;
    }
    else{
        cout<<"wrong"<<endl;
    }
    */
    Parallelogram pingxing(pot);
    if(pingxing.verify()){
        cout<<pingxing.getArea()<<endl;
        cout<<pingxing.getPerimeter()<<endl;
    }
    else{
        cout<<"wrong"<<endl;
    }
    return 0;
}