#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
int main(){
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d); // ����
    for(double i=-100;i<=100;i+=0.001){//ö��ÿ����
        if(fabs(i*i*i*a+i*i*b+i*c+d)<0.0001)//����double���ȴ���
            printf("%.02lf ",i);//��λС�����
    }
    return 0;
}
