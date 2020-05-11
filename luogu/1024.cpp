#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
int main(){
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d); // 输入
    for(double i=-100;i<=100;i+=0.001){//枚举每个答案
        if(fabs(i*i*i*a+i*i*b+i*c+d)<0.0001)//避免double精度错误
            printf("%.02lf ",i);//两位小数输出
    }
    return 0;
}
