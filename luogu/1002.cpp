#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define debug 1
#define inf 100010
#define ll long long
#define INF 0x7fffffff
#define INF_T 9223372036854775807
#define ull unsigned long long
using namespace std;

inline int read(){
	char c=getchar();int num=0;bool b=0;
	for(;c<'0'||c>'9';b=(c=='-'?1:0),c=getchar());
	for(;c>='0'&&c<='9';num=(num<<3)+(num<<1)+(c^'0'),c=getchar());
	return b?-num:num;
}

int row[8]={-2,-2,-1,-1,1,1,2,2};
int line[8]={1,-1,2,-2,2,-2,1,-1};
unsigned long long f[31];
bool s[31][31];

int main(){
	
	int x,y,x1,y1;
	x=read();y=read();x1=read();y1=read();
	++x;++y;++x1;++y1;
	//cout<<x<<y<<x1<<y1;
	
	//memset(f,0,sizeof(ull)*22);
	//memset(s,0,sizeof(bool)*22*22);
	f[1]=1;
	s[x1][y1]=1;
	for (int i=0;i<=7;i++){
		s[x1+row[i]][y1+line[i]]=1;
	}
	for (int i=1;i<=x;i++){
		for (int j=1;j<=y;j++){
		//	cout<<s[i][j]<<'-'<<endl;
			//cout<<f[j]<<endl;
			if (s[i][j]){
				f[j]=0;
				continue;
			}
			
			f[j]+=f[j-1];
			
		}
		/*for (int j=1;j<=y;j++){
			cout<<f[j]<<' ';		
		}
		cout<<endl;*/
	}

	printf("%llu\n",f[y]);
	
	return 0;
}
