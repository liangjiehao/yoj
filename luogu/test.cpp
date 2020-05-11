#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void*b){
	char *s1=(char*)a;
	char *s2=(char*)b;
	//printf("%s %s\n",*s1,*s2);
	return strcmp(s1,s2);
}
int main (){
	char x[5][20]={"wwwwI","Love","You","Too"};
	char *t[5]={x[0],x[1],x[2],x[3]};
	qsort(x[0],4,sizeof(x[0]),cmp);
	printf("%s %s %s %s",t[0],t[1],t[2],t[3]);
	return 0;
}
