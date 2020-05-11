#include <iostream>
using namespace std;

class Datatype {
public:
    void print();
    //____qcodep____
    Datatype(char c):_c(c),_vartype('c'){};
    Datatype(int i):_i(i),_vartype('i'){};
    Datatype(float f):_f(f),_vartype('f'){};
private:
    union {char _c;int _i;float _f;};
    char _vartype;
    static const char character='c',integer='i',floating='f';
};

void Datatype::print() {
    switch (_vartype) {
    case character:
        cout << "char: " << _c << endl;
        break;
    case integer:
        cout << "int: " << _i << endl;
        break;
    case floating:
        cout << "float: " << _f << endl;
        break;
    }
}

int main() {
    char c;
    int i;
    float f;
    cin >> c >> i >> f;
    Datatype ii(i), cc(c), ff(f);
    cout<<sizeof(Datatype)<<endl<<sizeof(cc);
    if(8 == sizeof(ii) &&
       8 == sizeof(cc) &&
       8 == sizeof(ff) ) {
        cc.print();
        ii.print();
        ff.print();       
    }
    
    return 0;
}