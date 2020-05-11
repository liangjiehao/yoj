#include<iostream>
#include<string>
#define male true
#define female false
enum{name,id,number,gender,birthdate};
using namespace std;

class date{
    private:
        int _year,_month,_day;
    public:
        date(){_year=2020,_month=1,_day=1;};
        date(const date &d){_year=d._year,_month=d._month,_day=d._day;};
        void read(){
            cout<<"year: ";
            cin>>_year;
            cout<<"month: ";
            cin>>_month;
            cout<<"day: ";
            cin>>_day;
        };
        inline void show(){
            cout<<_year<<'-'<<_month<<'-'<<_day<<endl;      
        }
};

class People{
    private:
        int _num;
        string _id,_name;
        bool _gender;
        date birth_date;
    public:
        People();
        People(const People &p);
        ~People();
        void read();
        void alter();
        inline void show();
};

People::People():_num(0),_id(),_name(),_gender(true),birth_date(){};
People::People(const People &p):_num(p._num),_id(p._id),_name(p._name),_gender(p._gender),birth_date(p.birth_date){};
People::~People(){cout<<this->_name<<" id:"<<this->_id<<" removed"<<endl;};
void People::read(){
    cout<<"Please enter the name: ";
    cin>>_name;
    cout<<"Please enter the id: ";
    cin>>_id;
    cout<<"Please enter the number: ";
    cin>>_num;
    cout<<"Please enter the gender(male:1,female:0): ";
    cin>>_gender;
    cout<<"Please enter the birthdate: "<<endl;
    birth_date.read();
};
void People::alter(){
    int term;
    cout<<"select the term to alter: "<<endl;
    cout.width(7);
    cout<<0;
    cout.width(7);
    cout<<1;
    cout.width(7);
    cout<<2;
    cout.width(7);
    cout<<3;
    cout.width(7);
    cout<<4<<endl;  
    cout<<"name   id     number gender birthdate"<<endl;
    cin>>term;
    switch(term){
        case name : cout<<"name:";cin>>_name;break;
        case id : cout<<"id:";cin>>_id;break;
        case number : cout<<"number:";cin>>_num;break;
        case gender : cout<<"gender(male:1 female:0):";cin>>_gender;break;
        case  birthdate : cout<<"birthdate:"<<endl;birth_date.read();break;
        default: cout<<"wrong input"<<endl;
    }; 
};
void People::show(){
    cout.setf(std::ios::left);
    cout<<"-----------------------------"<<endl;
    cout.width(12);
    cout<<"name:"<<_name<<endl;
    cout.width(12);
    cout<<"id:"<<_id<<endl;
    cout.width(12);
    cout<<"number:"<<_num<<endl;
    cout.width(12);
    cout<<"gender:"<<(_gender?"male":"female")<<endl;
    cout.width(12);
    cout<<"birthdate:";
    birth_date.show();  
    cout<<"-----------------------------"<<endl;
}
int main(){
    People me;
    me.read();
    me.show();
    People he(me);
    he.show();
    me.show();
    he.alter();
    he.show();
    return 0;
}