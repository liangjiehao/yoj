
#include <iostream>

using namespace std;

class DateTime{
private:
    int year,month,day;
public:
    int getYear() const {return year;}
    void setYear(int y){year = y;}
    //____qcodep____
    DateTime():year(2020){}
    DateTime(int year):year(year){}
    DateTime(const DateTime &dt){
        year = dt.year;
        month= dt.month;
        day = dt.day;
    }
};

class BankID{
public:
    BankID();
    //____qcodep____
    DateTime dt;
    BankID(const DateTime &dt);
    ~BankID();
    int getCount(){return count;}
    string  getClassDescription() const {return classdesc;};
private:
    //____qcodep____
    
    static int count;
    static const string classdesc;

};

//____qcodep____
int BankID::count=0;
const string BankID::classdesc="Bank description class";

BankID::BankID(const DateTime &dt):dt(dt.getYear()){

    count++;
}

BankID::BankID(){
    count++;
}

BankID::~BankID(){
    count--;
}

const DateTime getTime(BankID &bi){
    return bi.dt;
}

int main(int argc, char *argv[])
{
    int user1AddedYear,user2AddedYear;
    cin>>user1AddedYear;
    cin>>user2AddedYear;
    DateTime dt(user1AddedYear);
    BankID user_1(dt);
    DateTime dt2(user2AddedYear);
    BankID user_2(dt2);

    cout<< user_1.getCount()<<endl;
    DateTime t = getTime(user_1);
    cout<<t.getYear()<<endl;

    cout<< user_2.getCount()<<endl;
    DateTime t2 = getTime(user_2);
    cout<<t2.getYear()<<endl;

    cout<<user_2.getClassDescription()<<endl;

    BankID user_3;
    cout<< user_3.getCount()<<endl;
    DateTime t3 = getTime(user_3);
    cout<<t3.getYear()<<endl;

    cout<<user_3.getClassDescription()<<endl;

    return 0;


}