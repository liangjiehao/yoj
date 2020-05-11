#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class StringUtils
{
public:
    double str2Double(const string & s);
        //字符串转double，以下类似
    string double2Str(double d);
    int str2Int(const string & s);
    string int2Str(int i);
};

string StringUtils::double2Str(double d){
    string res = "";
    stringstream ss;
    ss << d;
    ss >> res;
    return res;
}

string StringUtils::int2Str(int i){
    string res = "";
    stringstream ss;
    ss << i;
    ss >> res;
    return res;
}

double StringUtils::str2Double(const string &s){
    stringstream ss;
    ss << s;
    double d = 0;
    ss >> d;
    return d;
}


int StringUtils::str2Int(const string &s){
    stringstream ss;
    ss << s;
    int i = 0;
    ss >> i;
    return i;
}

//以下部分定义并实现DoubleNumber类
//____qcodep____ 
class DoubleNumber{
    private:
        string s1;
        StringUtils s;
    public:
        DoubleNumber(string s):s1(s){};
        void add(const DoubleNumber &n2){s1=s.double2Str(s.str2Double(s1)+s.str2Double(n2.s1));}
        double getVal(){return s.str2Double(s1);}
        void setVal(string s2){s1=s2;}
        void subtract(const DoubleNumber &n2){s1=s.double2Str(s.str2Double(s1)-s.str2Double(n2.s1));}
};



int main()
{
    //读入两个浮点数；
    //输出两行；第一行是两个浮点数的相加的结果
    //第二行是第一个浮点数减去第二个浮点数的结果

    string s1, s2;
    cin>>s1;
    cin>>s2;

    DoubleNumber n1(s1);
    DoubleNumber n2(s2);
    n1.add(n2);
    cout<<n1.getVal()<<endl;

    n1.setVal(s1);
    n1.subtract(n2);
        //n1 减去 n2，结果存储于 n1
    cout<<n1.getVal()<<endl;

    return 0;
}