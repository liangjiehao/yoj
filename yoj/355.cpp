#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
class MyStr{
public:
    MyStr(const char * s);
    ~MyStr();    
    //将输入的字符串加到当前字符串末尾
    void myStrcat(const MyStr & str1);
    char * getStr() const;

    //此处可补充代码
    MyStr(const MyStr & s);

    //____qcodep____ 

private:
    int size;
    char * data;
};

MyStr::~MyStr(){
    delete [] data;
}

char * MyStr::getStr() const{
    return this->data;
}

//此处可补充代码
MyStr::MyStr(const char * s){
    size=strlen(s);
    data = new char [size+1];
    strcpy(data,s);
}
MyStr::MyStr(const MyStr & s){
    size=s.size;
    data = new char [s.size+1];
    strcpy(data,s.data);
}

//MyStr::MyStr(const char & s){}

void MyStr::myStrcat(const MyStr & str1){
    char * temp= new char[size+1];
    strcpy(temp,data);
    delete [] data;
    data = new char[size+str1.size+1];
    strcpy(data,temp);
    strcat(data,str1.data);
    //cout<<data<<endl;
}
//____qcodep____ 

int main(){
    char tempStr[20];
    cin>>tempStr;
    MyStr * s0 = new MyStr(tempStr);
    MyStr * s1 = new MyStr(*s0);
    s1->myStrcat(*s0);
    cout<<s1->getStr()<<endl;
    s1->~MyStr();
    cout<<s0->getStr()<<endl;
    s0->~MyStr();
    return 0;
}