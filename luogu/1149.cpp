#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int ans=0,i,j,a,b,c,n,num;
    int w[10]={6,2,5,5,4,5,6,3,7,6};  //����0~9ÿ�����ְڻ�����Ҫ������
    cin>>n;
    for (i=0;i<=1111;i++)   //ö��ǰ������
      for (j=0;j<=1111;j++)
        {
            a=i;b=j;c=i+j;num=4;
            while (a/10!=0)  //����������õĻ�������
            {
                num+=w[a%10];
                a/=10;
            }
            num+=w[a];
            while (b/10!=0)
            {
                num+=w[b%10];
                b/=10;
            }
            num+=w[b];
            while (c/10!=0)
            {
                num+=w[c%10];
                c/=10;
            }
            num+=w[c];
            if (num==n) ans++;   //��������Ǽ�����ι
        }
        cout<<ans;
  return 0;
}
