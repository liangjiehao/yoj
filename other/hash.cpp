#include <iostream>
#include <cstring>
int hash(char* str,int len){
    int sum=0,mul=1,cnt=1;
    char* p=str;
    while(*p != 0){
        sum+=((*p)*cnt*cnt);
        //mul*=(*p);
        p+=1;
        cnt+=1;
    }
    return sum%1000000007;
}
bool not_in_set(int*array,int t,int count){
    for (int i=0;i<=count;i++){
        if (array[i]==t)return false;
    }
    return true;
}
int main (){
    int n,count=0,array[10002]={0},t=0;
    char str[1502];
    std::cin>>n;
    for (int i=0;i<=n-1;i++){
        std::cin>>str;
        t=hash(str,strlen(str));
        if (not_in_set(array,t,count)){
            count+=1;
            array[count]=t;
        }
    }
    std::cout<<count;
    return 0;
}