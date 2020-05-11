#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f1, f2;
    ofstream fout;
    f1.open("A1.DAT");
    f2.open("A2.DAT");
    fout.open("C.DAT");
    int a, b;
    f1 >> a;
    f2 >> b;
    while (true)
    {
        while (a <= b && !f1.eof())
        {
            fout << a << ' ';
            f1 >> a;
        }
        while (b < a && !f2.eof())
        {
            fout << b << ' ';
            f2 >> b;
        }
        if (f1.eof())
        {
            fout << a << ' ';
            do
            {
                fout << b << ' ';
            } while (f2 >> b);
            break;
        }
        if (f2.eof())
        {
            fout << b << ' ';
            do
            {
                fout << a << ' ';
            } while (f1 >> a);
            break;
        }
    }

    f1.close();
    f2.close();
    fout.close();
    return 0;
}