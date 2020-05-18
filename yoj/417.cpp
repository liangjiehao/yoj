#include<string>
#include <iostream>
using namespace std;

class person
{
public:
    person(string nam,int a,char s,string ad,string t);
    void display();
private:  string name;
    int age;
    char sex;
    string addr;
    string tel;
};
person::person(string nam, int a, char s, string ad, string t)
{    name=nam;    age=a;    sex=s;    addr=ad;    tel=t;}
void person::display(){    cout<<"name:"<<name<<endl;    cout<<"age:"<<age<<endl;    cout<<"sex:"<<sex<<endl;
    cout<<"address:"<<addr<<endl;    cout<<"tel:"<<tel<<endl;}

class Teacher:virtual public person
{
public:
    Teacher(string nam,int a,char s,string tit,string ad,string t);
    void display();
protected:
    string name;
    int age;
    char sex;
    string title;
    string addr;
    string tel;
};

class Cadre:virtual public person
{
public:
    Cadre(string nam,int a,char s,string p,string ad,string t);
    void display();
protected:
    string name;
    int age;
    char sex;
    string post;
    string addr;
    string tel;
};
Teacher::Teacher(string nam,int a,char s,string tit,string ad,string t):person(nam,a,s,ad,t)
{
    name=nam;
    age=a;
    sex=s;
    title=tit;
    addr=ad;
    tel=t;
    addr.erase(0,1);
}

Cadre::Cadre(string nam,int a,char s,string p,string ad,string t):person(nam,a,s,ad,t)
{
    name=nam;
    age=a;
    sex=s;
    post=p;
    addr=ad;
    tel=t;
}
class Teacher_Cadre: public Teacher, public Cadre
{
public:
    Teacher_Cadre(string name, int age, char sex,  string title, string post,string address, string tele, float wages);

    void show();
private:
    double wage;

};
Teacher_Cadre::Teacher_Cadre(string name, int age, char sex,  string title, string post, string address, string tele,float wages):
    person(name,age,sex,address,tele),Teacher(name, age, sex, title, address, tele),Cadre(name, age, sex, post, address, tele)
{
    wage=(double)wages;
}


void Teacher::display()
{
    cout<<"name:"<<name<<endl;
    cout<<"age:"<<age<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"title:"<<title<<endl;
    cout<<"address:"<<addr<<endl;
    cout<<"tel:"<<tel<<endl;
}

void Cadre::display()
{
    cout<<"name:"<<name<<endl;
    cout<<"age:"<<age<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"post:"<<post<<endl;
    cout<<"address:"<<addr<<endl;
    cout<<"tel:"<<tel<<endl;
}

void Teacher_Cadre ::show()
{
    Teacher::display();
    cout<<"post:"<<post<<endl;
    cout<<"wages:"<<wage<<endl;
}

int main()
{
    string name,title,post,address,tele;
    int age;
    char sex;
    float wages;
    cin>>name>>age;
    cin>>sex>>title>>post;
    getline(cin,address);
    cin>>tele>>wages;
    Teacher_Cadre te_ca(name,age,sex,title,post,address,tele,wages);
    te_ca.show();
    
    cout << sizeof(Teacher) << endl;
    cout << sizeof(Cadre) << endl;
    cout << sizeof(Teacher_Cadre) << endl;

    return 0;
}