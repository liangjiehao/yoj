#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//____qcodep____
#include <string.h>
class Matrix{
public:
    Matrix (int,int);
    friend istream & operator >> (istream &in, Matrix &a);
    friend ostream & operator << (ostream &out, const Matrix &a);
    Matrix operator + (const Matrix & b);
    Matrix operator - (const Matrix & b);
    Matrix operator * (const Matrix & b);
private:
    int r,c;
    double m[10][10];
    bool veri;
};

Matrix::Matrix(int r,int c):r(r),c(c){
    memset(m,0,sizeof(double)*10*10);
    veri=r && c ? true :false;
}
istream & operator >> (istream & in, Matrix &a){//const
    for (int i=0;i<=a.r-1;i++){
        for (int j=0;j<=a.c-1;j++){
            in >> a.m[i][j];
        }
    }
    return in;
}
ostream & operator << (ostream &out, const Matrix &a){//const
    if (a.veri){
        for (int i=0;i<=a.r-1;i++){
            for (int j=0;j<=a.c-1;j++){
                out <<setw(6)<< a.m[i][j];
            }
            out<<endl;
        }
    }
    else out<<"invalid operation!"<<endl;
    return out;
}
Matrix Matrix::operator + (const Matrix & b){
    if(r!=b.r || c!=b.c){
        Matrix t(0,0);
        return t;
    }
    else{
        Matrix t(r,c);
        for (int i=0;i<=r-1;i++)
            for(int j=0;j<=c-1;j++){
                t.m[i][j]=m[i][j]+b.m[i][j];
            }
        return t;
    }
}
Matrix Matrix::operator - (const Matrix & b){
    if(r!=b.r || c!=b.c){
        Matrix t(0,0);
        return t;
    }
    else{
        Matrix t(r,c);
        for (int i=0;i<=r-1;i++)
            for(int j=0;j<=c-1;j++){
                t.m[i][j]=m[i][j]-b.m[i][j];
            }
        return t;
    }
}
Matrix Matrix::operator * (const Matrix & b){
    if(c!=b.r){
        Matrix t(0,0);
        return t;
    }
    else{
        Matrix t(r,b.c);
        for (int i=0;i<=r-1;i++)
            for(int j=0;j<=b.c-1;j++){
                for (int k=0;k<=c-1;k++)
                t.m[i][j]+=(m[i][k]*b.m[k][j]);
            }
        return t;
    }
}

//
int main() {
    int r,c;
    cin>>r>>c;
    if(r<1 || c<1){
    cout<<"Input error."<<endl;
    exit(1);
    }
    Matrix A(r,c);
    cin >> A;
    
    cin>>r>>c;
    if(r<1 || c<1){
    cout<<"Input error."<<endl;
    exit(1);
    }
    Matrix B(r,c);
    cin >> B;
    
    cout<<"A + B:"<<endl;
    cout << A + B <<endl;

    cout<<"A - B:"<<endl;
    cout << A - B <<endl;
    
    cout<<"A * B:"<<endl;
    cout << A * B <<endl;

    return 0;
}