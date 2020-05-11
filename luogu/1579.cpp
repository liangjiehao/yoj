#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main (){
	int a[20000]={0},prime[3000]={0};
	for (int i=2,cnt=0;i<=20000;i++){
		if (!a[i]){prime[cnt++]=i;}//先默认全部是素数 0是素 
		for (int j=0;j<=cnt-1&&i*prime[j]<=20000;j++){
				a[i*prime[j]]=1;
				if (i%prime[j]==0)break;
		}

	}
	/*for (int i=0;i<=2999;i++){
		printf("%d\n",prime[i]);
	}*/
	//printf("%d\n",a[3]);
	int flag=0,n;
	scanf("%d",&n);
	for (int i=2;i<=n-6;i++){
		for (int j=2;j<=n-4;j++){
			if (n-i-j>=2&&!a[i]&&!a[j]&&!a[n-i-j]){
				printf("%d %d %d",i,j,n-i-j);
				flag=1;
				break;
			}
		}
		if(flag)break;
	}
	return 0;
}
