#include<stdio.h>
int a[10],cnt=0;
void dfs(int n,int p,int on){
	if (n<0)return;
	if (p==10){
		if (n==0){
			cnt++;
			if(on){
				for (int i=0;i<=9;i++){
					printf("%d",a[i]);
					if (i==9)printf("\n");
					else printf(" ");
				}
			}
			
		}
		return;
	}
	else {
		for (int i=1;i<=3;i++){
			if(on)a[p]=i;
			dfs(n-i,p+1,on);
		}
	}
}
int main (){
	int n;
	scanf("%d",&n);
	if (n>=10&&n<=30)dfs(n,0,0);
	printf("%d\n",cnt);
	if (cnt){
		dfs(n,0,1);
	}
	
	
	return 0;
}
