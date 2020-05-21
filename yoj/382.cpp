#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const double RATIO = 0.01;
const double SALARY_PER_YEAR = 35;
const double BASE_SALARY = 1000;

//____qcodep____
class person{
public:
    person(int age):age(age){}
protected:
    int age;
};
class Worker:public person{
public:
    Worker(int age):person(age){}
    void setSalaryPerHour(double sph){_sph=sph;}
    void setWorkHour(double wh){_wh=wh;}
    double getPayPerMonth(){return _sph*_wh+35*age;}
private:
    double _sph;
    double _wh;
};
class SalesPerson:public Worker{
public:
    SalesPerson(int age):Worker(age){}
    void setSalesAmount(double sm){_sm=sm;}
    double getPayPerMonth(){return Worker::getPayPerMonth()+_sm*0.01;}
private:
    double _sm;
};
class Manager:public person{
public:
    Manager(int age):person(age){}
    double getPayPerMonth(){return 1000+age*35;}
};
//

int main(){
    //Person* per = 0;
    int workAge1,workAge2,workAge3;
    double salaryPerHour1,salaryPerHour2;
    int workHour1,workHour2;
    double salesAmount;

    cin>>workAge1>>workAge2>>workAge3;
    cin>>salaryPerHour1>>salaryPerHour2;
    cin>>workHour1>>workHour2;
    cin>>salesAmount;

    Worker* p = new Worker(workAge1);
    p->setSalaryPerHour(salaryPerHour1);
    p->setWorkHour(workHour1);
    cout<<p->getPayPerMonth()<<endl;
    delete p;

    SalesPerson* sp = new SalesPerson(workAge2);
    sp->setSalaryPerHour(salaryPerHour2);
    sp->setWorkHour(workHour2);
    sp->setSalesAmount(salesAmount);
    cout<<sp->getPayPerMonth()<<endl;
    delete sp;

    Manager* mgr = new Manager(workAge3);
    cout<<mgr->getPayPerMonth()<<endl;
    delete mgr;
    return 0;
}