#include <iostream>
using namespace std;
int l,r,count=0;
char f[11];
bool flag=false;
int main(){
    int read();
    void dfs(int,char);
    l=read();
    r=read();
    dfs(0,'0');
    cout<<f+1;
    return 0;
}
int pow(int x, int y){
    int t=1;
    for (int i=0;i<=y-1;i++)t*=x;
    return t;
}
int read(){
    int a,b=0;
    for (int i=6;i>=0;i--){
        cin>>a;
        b+= pow(2,i)*a;
    }
    return b;
}
void left(){
    l=((l>>1)+(1&l)*pow(2,6));
}
void right(){
    int pow(int,int);
    r=((r>>1)+(1&r)*pow(2,6));
}
void _left(){
    int pow(int,int);
    int t=l<<1;
    int t1=l>>6;
    l=((l<<1)+(l>>6));
    int t2=(l&(pow(2,7)-1));
    l=(l&(pow(2,7)-1));
}
void _right(){
    int pow(int,int);
    r=((r<<1)+(r>>6));
    r=(r&(pow(2,7)-1));
}
void mid(){
    int pow(int,int);
    int t0,t1,t2;
    t0=pow(2,2)+pow(2,3)+pow(2,4);
    t1=t0;
    t2=t0;
    t1=t1&l;
    t2=t2&r;
    t1=t1^t2;
    t2=t1^t2;
    t1=t1^t2;
    l=((~t0)&l)+t1;
    r=((~t0)&r)+t2;
}
void dfs(int n,char step){
    void left();
    void right();
    void mid();
    void _left();
    void _right();

    if(flag || n==10)return;

    if (l==0 && r==pow(2,7)-1){
        cout<<n<<endl;
        flag=true;
        return;
    }
    
    f[n]=step;
    left();
    dfs(n+1,'a');
    _left();

    mid();
    dfs(n+1,'b');
    mid();

    right();
    dfs(n+1,'c');
    _right();
}