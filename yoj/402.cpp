/*
Point类的设计与完善
问题描述：二维坐标类Point重载"++"(自增)、"--"（自减）运算符，
"++"运算符使横坐标与纵坐标都加1，"--""运算符使横坐标与纵坐标都减1，
要求同时重载前缀和后缀的形式。
*/
#include <iostream>
using namespace std;

// Point类
class Point
{
    // 构造函数与析构函数
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    ~Point() {}
    // 普通成员函数
public:
    // 输出点的坐标
    void showPosition() { cout << "(" << x << ", " << y << ")" << endl; }
    
public:
    //此处填空，补充必要的运算符重载函数
    Point& operator ++();
    Point operator ++(int);
    Point& operator --();
    Point operator --(int);
    //____qcodep____
private:
    int x;
    int y;
};

//-------------------------------------- 
// 请补充缺少的类实现代码
Point& Point::operator ++(){
    ++x;
    ++y;
    return (*this);
}
Point Point::operator ++(int){
    Point p(x,y);
    ++x;
    ++y;
    return p;
}
Point& Point::operator --(){
    --x;
    --y;
    return (*this);
}
Point Point::operator --(int){
    Point p(x,y);
    --x;
    --y;
    return p;
}

//____qcodep____

int main()
{
    int x, y;
    cin >> x >> y;
    Point po(x, y);
    Point po1, po2;

    // 后置运算后的坐标
    po1 = po;
    
    po2 = po++;
    po2.showPosition();
    po.showPosition();
    po = po1;
    po2 = po--;
    po2.showPosition();
    po.showPosition();
    cout << endl;
    
    // 前置运算后的坐标 参见主函数 
    po = po1;
    po2 = --po;
    po2.showPosition();
    po.showPosition();
    cout << endl;
        
    po = po1;
    po2 = ++(++po);
    po.showPosition();
    po2.showPosition();

    return 0;
}