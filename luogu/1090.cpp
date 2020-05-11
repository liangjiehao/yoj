#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}
int main (){
	int a[10002],n,sum=0;
	scanf("%d",&n);
	for (int i=0;i<=n-1;i++)scanf("%d",a+i);
	qsort(a,n,sizeof(int),cmp);
	for (int i=0;i<=n-2;i++){
		a[i+1]+=a[i];
		sum+=a[i+1];
		qsort(a+1+i,n-i-1,sizeof(int),cmp); 
	}//全用快排会有4个TLE 
	/*for (int i=0;i<=n-2;i++){
		a[i]+=a[i+1];
		sum+=a[i];
		int j=i+2;
		while(a[i]>=a[j]&&j<=n-1)j++;
		int k=i+1;
		for (;k<=j-2;k++)a[k]=a[k+1];
		a[k]=a[i];
	}快排+插排可以AC*/
	printf("%d",sum);
	return 0;
}
