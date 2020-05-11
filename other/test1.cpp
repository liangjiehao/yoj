#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define len 92680
using namespace std;

struct w
{
    string word;
    string sign;
}d[len];

bool cmp(w a,w b){
    return a.sign<=b.sign;
} 

int main()
{
    ifstream f1;
    ofstream f2;
    f1.open("dic.txt");
    f2.open("result.txt");
    for (int i=0;i<=len-1;i++){
        f1>>d[i].word;
        d[i].sign=d[i].word;
        sort(d[i].sign.begin(),d[i].sign.end());
    }
    sort(d,d+len,cmp);
    f2<<d[0].word<<' ';
    for (int i=1;i<=len-1;i++){
        if (d[i].sign != d[i-1].sign)
            f2<<endl;
        f2<<d[i].word<<' ';
    }

    f1.close();
    f2.close();
    return 0;
}