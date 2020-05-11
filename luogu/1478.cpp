#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b){
	
	return (*((int*)a+1)-*((int*)b+1));
}
int main (){
	int n,s,a,b,xt,yt,x[5001][2],j=0,*t[5001];
	scanf("%d%d%d%d",&n,&s,&a,&b);
	for (int i=0;i<=n-1;i++){
		scanf("%d%d",&xt,&yt);
		if (a+b>=xt){
			x[j][0]=xt;x[j][1]=yt;t[j]=x[j]+1;j++;
		}
	}
	/*for (int i=0;i<=j-1;i++){
		printf("%d ",*(t[i]-1));
	}*/	
	//printf("\n");
	qsort(x,j,sizeof(x[0]),cmp);
	/*for (int i=0;i<=j-1;i++){
		printf("%d %d\n",*(t[i]-1),*(t[i]));
	}*/
	int p=0;
	for (int i=0;i<=j-1;i++){
		if (s>=x[i][1]){
			p++;
			s-=x[i][1];
		}
	}
	printf("%d",p);
	return 0;
}
