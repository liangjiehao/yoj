#include <bits/stdc++.h>
using namespace std;
int main (){
	int rec[50]={0},_rec[50]={0},i=0,j=0,x[20]={-1},mov,sgn[50]={0},fst=1;
	char c,X;
	for (int i=0;i<=49;i++){
		sgn[i]=1;
	} 
	while(c=getchar()){
		if (c>='0'&&c<='9'){fst=0;rec[i]=rec[i]*10+c-'0';_rec[i]=1;continue;}
		if (c=='-'){if (fst)i--;sgn[++i]=-1;continue;}
		if (c=='+'){sgn[++i]=1;continue;}
		if (c=='='){break;}
		if (c>='a'&&c<='z'){fst=0;x[j++]=i;X=c;continue;} 
		//break;
	}
	int k=0,b=0;
	for (int ii=0,jj=0;ii<=i;ii++){
		if (_rec[ii]==0){rec[ii]=1;}
		if (ii==x[jj]){k+=(rec[ii]*sgn[ii]);jj++;}
		else {b+=(rec[ii]*sgn[ii]);}
	}
	//cout<<k<<' '<<b<<endl;
	int _i=++i,_j=j;
	fst=1;
	while(c=getchar()){
		if (c>='0'&&c<='9'){fst=0;rec[i]=rec[i]*10+c-'0';_rec[i]=1;continue;}
		if (c=='-'){if (fst)i--;sgn[++i]=-1;continue;}
		if (c=='+'){sgn[++i]=1;continue;}
		if (c>='a'&&c<='z'){fst=0;x[j++]=i;X=c;continue;} 
		break;
	}
	for (int ii=_i,jj=_j;ii<=i;ii++){
		if (_rec[ii]==0){rec[ii]=1;}
		if (ii==x[jj]){k-=(rec[ii]*sgn[ii]);jj++;}
		else {b-=(rec[ii]*sgn[ii]);}
	}
	
	//cout<<k<<' '<<b<<endl;
	double sum=-1.0*b/(k*1.0);
	if (abs(sum)<0.00001)sum=0.0;
	printf("%c=%.3lf",X,sum);
	/*cout<<endl; 
	for (int i=0;i<=19;i++){
		cout<<rec[i]<<' ';
	}
	cout<<endl;
	for (int i=0;i<=19;i++){
		cout<<_rec[i]<<' ';
	}
	cout<<endl;
	for (int i=0;i<=19;i++){
		cout<<sgn[i]<<' ';
	}
	cout<<endl;	
	for (int i=0;i<=19;i++){
		cout<<x[i]<<' ';
	}*/
	//cout<<endl<<mov;
	return 0;
}
