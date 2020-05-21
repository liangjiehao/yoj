#include <string>
#include <iostream>
using namespace std;

class person
{
public:
    person(string nam, int a, char s, string ad, string t);
    void display();

protected:   
    int age;
    string name;
    string addr;
    char sex;
    string tel;
};
person::person(string nam, int a, char s, string ad, string t)
{
    name = nam;
    age = a;
    sex = s;
    addr = ad;
    //addr.erase(0, 1);
    tel = t;
}
void person::display()
{
    cout << "name:" << name << endl;
    cout << "age:" << age << endl;
    cout << "sex:" << sex << endl;
    cout << "address:" << addr << endl;
    cout << "tel:" << tel << endl;
}

class Teacher : virtual public person
{
public:
    Teacher(string nam, int a, char s, string tit, string ad, string t);
    void display();

protected:
    string title;
};

class Cadre : virtual public person
{
public:
    Cadre(string nam, int a, char s, string p, string ad, string t);
    void display();

protected:
    string post;
};
Teacher::Teacher(string nam, int a, char s, string tit, string ad, string t) : person(nam, a, s, ad, t),title(tit){}

Cadre::Cadre(string nam, int a, char s, string p, string ad, string t) : person(nam, a, s, ad, t),post(p){}

class Teacher_Cadre : public Teacher, public Cadre
{
public:
    Teacher_Cadre(string name, int age, char sex, string title, string post, string address, string tele, double wages);
    void show();
private:
    double wage;
};
Teacher_Cadre::Teacher_Cadre(string name, int age, char sex, string title, string post, string address, string tele, double wages) 
    : person(name, age, sex, address, tele), Teacher(name, age, sex, title, address, tele), Cadre(name, age, sex, post, address, tele),wage(wages){}

//
void Teacher::display()
{
    cout << "name:" << name << endl;
    cout << "age:" << age << endl;
    cout << "sex:" << sex << endl;
    cout << "title:" << title << endl;
    cout << "address:" << addr << endl;
    cout << "tel:" << tel << endl;
}

void Cadre::display()
{
    cout << "name:" << name << endl;
    cout << "age:" << age << endl;
    cout << "sex:" << sex << endl;
    cout << "post:" << post << endl;
    cout << "address:" << addr << endl;
    cout << "tel:" << tel << endl;
}

void Teacher_Cadre ::show()
{
    Teacher::display();
    cout << "post:" << post << endl;
    cout << "wages:" << wage << endl;
}

int main()
{
    string name, title, post, address, tele;
    int age;
    char sex;
    float wages;
    cin >> name >> age;
    cin >> sex >> title >> post;
    getline(cin, address);
    cin >> tele >> wages;
    Teacher_Cadre te_ca(name, age, sex, title, post, address, tele, wages);
    te_ca.show();

    cout << sizeof(Teacher) << endl;
    cout << sizeof(Cadre) << endl;
    cout << sizeof(Teacher_Cadre) << endl;

    return 0;
}