#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

//下面需要补充多个类的声明及实现代码
//____qcodep____
class Point{
public:
    double getX(){return x;}
    double getY(){return y;}
    Point(double x,double y):x(x),y(y){}
protected:
    double x,y;
};

class Quadrilateral{
public:
    Quadrilateral(vector<Point> vertices):_vertices(vertices){}
    double getArea(){
        if (verify()){
            return getlen(_vertices[0],_vertices[2])*getlen(_vertices[1],_vertices[3])
                    *sqrt(1-getang(_vertices[0],_vertices[2],_vertices[1],_vertices[3])
                    *getang(_vertices[0],_vertices[2],_vertices[1],_vertices[3]))*0.5;
        }
        else return 0;
        
    };
    double getPerimeter(){
        if (verify()){
            return getlen(_vertices[0],_vertices[1])+getlen(_vertices[1],_vertices[2])
                +getlen(_vertices[2],_vertices[3])+getlen(_vertices[3],_vertices[0]);
        }
        else return 0;
    };
    bool verify(){
        return {
        1-abs(getang(_vertices[0],_vertices[1],_vertices[2],_vertices[1])) >=0.000001 && 
        1-abs(getang(_vertices[0],_vertices[1],_vertices[3],_vertices[1])) >=0.000001 && 
        1-abs(getang(_vertices[1],_vertices[2],_vertices[3],_vertices[2])) >=0.000001 &&
        1-abs(getang(_vertices[0],_vertices[2],_vertices[3],_vertices[2])) >=0.000001 &&
        getlen(_vertices[0],_vertices[1])+getlen(_vertices[2],_vertices[3]) < 
        getlen(_vertices[0],_vertices[2])+getlen(_vertices[1],_vertices[3])
        };
    };
    double getlen(Point a,Point b){
        return sqrt((a.getX()-b.getX())*(a.getX()-b.getX())+(a.getY()-b.getY())*(a.getY()-b.getY()));
    }
    double getang(Point a,Point b,Point c,Point d){ //return cosine
        return ((a.getX()-b.getX())*(c.getX()-d.getX())+(a.getY()-b.getY())*(c.getY()-d.getY()))/(getlen(a,b)*getlen(c,d));
    }
protected:
    vector<Point> _vertices;
};

class Parallelogram:public Quadrilateral{
public:
    Parallelogram(vector<Point>vertice):Quadrilateral(vertice){}
    bool verify(){
        return Quadrilateral::verify() && 
            1-Quadrilateral::getang(_vertices[0],_vertices[1],_vertices[3],_vertices[2])<=0.000001
            && 1-Quadrilateral::getang(_vertices[1],_vertices[2],_vertices[0],_vertices[3])<=0.000001;
    }
    double getArea(){
        if (verify()){
            return Quadrilateral::getArea();
        }
        else return 0;
    }
    double getPerimeter(){
        if(verify()){
            return Quadrilateral::getPerimeter();
        }
        else return 0;
    }
};
class Rectangle:public Parallelogram{
public:
    Rectangle(vector<Point>vertice):Parallelogram(vertice){}
    bool verify(){
        return Parallelogram::verify() && abs(Quadrilateral::getang(_vertices[0],_vertices[1],_vertices[2],_vertices[1]))<=0.000001;
    }
    double getArea(){
        if (verify()){
            return Quadrilateral::getArea();
        }
        else return 0;
    }
    double getPerimeter(){
        if(verify()){
            return Quadrilateral::getPerimeter();
        }
        else return 0;
    }

};
//填空结束


int main()
{
    vector<Point> vertices;
    for (int i=0;i<4;i++){
        double x,y;
        cin>>x>>y;
        Point p(x,y);
        vertices.push_back(p);
    }

    Quadrilateral q(vertices);
    Parallelogram pa(vertices);
    Rectangle r(vertices);

    cout<<fixed<<setprecision(2);

    cout<<(q.verify()?1:0)<<endl;
    cout<<q.getArea()<<endl;
    cout<<q.getPerimeter()<<endl;

    cout<<(pa.verify()?1:0)<<endl;
    cout<<pa.getArea()<<endl;
    cout<<pa.getPerimeter()<<endl;

    cout<<(r.verify()?1:0)<<endl;
    cout<<r.getArea()<<endl;
    cout<<r.getPerimeter()<<endl;

    return 0;
}