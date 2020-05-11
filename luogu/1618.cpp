#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int A,B,C,cnt=0;
int cmp(const void*a,const void *b){
	return (*(int*)a-*(int*)b);
}
void perm(int*s,int n,int k){
	if (k==n-1){
		int a=s[0]*100+s[1]*10+s[2],b=s[3]*100+s[4]*10+s[5],c=s[6]*100+s[7]*10+s[8];
		int z=a*B*C;
		if (z==b*A*C&&z==c*A*B){
			printf("%d %d %d\n",a,b,c);
			cnt++;
		}
	}
	else {
		//qsort(s+k,n-k,sizeof(int),cmp);
		for (int i=k;i<=n-1;i++){
			int t=s[k];s[k]=s[i];s[i]=t;
			perm(s,n,k+1);
			t=s[k];s[k]=s[i];s[i]=t;
		}
	}
}
int main (){
	scanf("%d%d%d",&A,&B,&C);
	int s[9]={1,2,3,4,5,6,7,8,9};
	perm(s,9,0);
	if(!cnt)printf("No!!!");
	//printf("iii");
	return 0;
}
