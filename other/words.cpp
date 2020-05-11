#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
const int len = 113809;
using namespace std;

class wd
{
public:
    string word;
    string sign;
};

bool cmp(wd &a, wd &b)
{
    return a.sign < b.sign;
}

int main()
{
    ifstream f1;
    ofstream f2;
    f1.open("dictionary.txt");
    f2.open("rec_dic.txt");
    wd *d=new wd[len];
    for (int i = 0; i <= len - 1; i++)
    {
        f1 >> d[i].word;
        d[i].sign = d[i].word;
        sort(d[i].sign.begin(), d[i].sign.end());
    }
    sort(d, d + len, cmp);
    f2 << d[0].word << ' ';
    for (int i = 1; i <= len - 1; i++)
    {
        if (d[i].sign != d[i - 1].sign)
            f2 << endl;
        f2 << d[i].word << ' ';
    }
    delete [] d;
    f1.close();
    f2.close();
    return 0;
}