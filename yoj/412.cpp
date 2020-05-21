#include <iostream>
#include <string>
using namespace std;

class BirthDate
{
public:
    BirthDate(int y, int m, int d):year(y), month(m), day(d) {}
    void display(){
        cout << "Birthday: " << year << "-" << month << "-" << day << endl;
    }
    void setbirthday(int y, int m, int d){
        year = y, month = m, day = d;
    };
private:
    int year;
    int month;
    int day;
};

class Teacher
{
public:
    Teacher(int id, string nam, char se):num(id), name(nam), sex(se) {}
    void display(){
        cout << "Teacher info: " << num << "/" << name << "/" << sex << endl;
    }
    //
    string getName(){return name;}
    //____qcodep____
private:
    int num;
    string name;
    char sex;
};


class Professor: private Teacher
{
public:
    Professor(int a, string b, char c, BirthDate d):Teacher(a,b,c),birthday(d){}//____qcodep____
    void display(){
        Teacher::display();
        cout<<getName()<<" is a professor whose birthday is ";
        birthday.display();
    }
    void setbirthday(int year,int month,int day){
        birthday.setbirthday(year,month,day);
    }
private:
    BirthDate birthday;
};
//____qcodep____

int main()
{
    int num;
    string name;
    char sex;
    int year,month,day;
    cin>>num>>name>>sex;
    cin>>year>>month>>day;
    Professor prof(num,name,sex,BirthDate(year,month,day));
    prof.display();
    cin>>year>>month>>day;
    prof.setbirthday(year,month,day);
    cout << "\nAfter setbirthday:" << endl;
    prof.display();
    cout << sizeof(prof) << endl;
    return 0;
}
