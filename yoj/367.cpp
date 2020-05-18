#include <iostream>
#include <string>

using namespace std;

class BirthDate
{
public:
    BirthDate(int,int,int);
    void display();
    void setbirthday(int,int,int);
private:
    int year;
    int month;
    int day;
};

class Teacher
{
public:
    Teacher(int,string,char);
    void display();
private:
    int num;
    string name;
    char sex;
};

class Professor:public Teacher
{
public:
    Professor(int,string,char,BirthDate);
    void display();
    void setbirthday(int,int,int);
private:
    BirthDate birthday;
};

//____qcodep____//需要实现多个函数，函数已在类内定义
BirthDate::BirthDate(int y ,int m,int d):year(y),month(m),day(d){}
void BirthDate::display(){
    cout<<"birthday:"<<year<<'/'<<month<<'/'<<day<<endl;
}
void BirthDate::setbirthday(int y,int m ,int d){
    year=y;
    month=m;
    day=d;
}
Teacher::Teacher(int num,string name,char sex):num(num),name(name),sex(sex){}
void Teacher::display(){
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"sex:"<<sex<<endl;
}
Professor::Professor(int num,string name,char sex,BirthDate birthday):Teacher(num,name,sex),birthday(birthday){}
void Professor::display(){
    Teacher::display();
    birthday.display();
}
void Professor::setbirthday(int y,int m,int d){
    birthday.setbirthday(y,m,d);
}

//
int main()
{
    int num;
    string name;
    char sex;
    int year,month,day;
    cin>>num>>name>>sex;
    cin>>year>>month>>day;
    Professor prof(num,name,sex,BirthDate(year,month,day));
    cin>>year>>month>>day;
    prof.setbirthday(year,month,day);
    prof.display();
    return 0;
}
