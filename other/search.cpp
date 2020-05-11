#include <iostream>
#include <cstring>
int n,m;
int map[10][10]={0};
int ans=0;
int step0=1;
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={-1,-2,-2,-1,1,2,2,1};
void go(int step,int x,int y){
    if(step==n*m){
        ans++;
        return;
    }
    //step++;
    int k,xx,yy;
    for (k=0;k<=7;k++){
        xx=x+dx[k];
        yy=y+dy[k];
        if (xx>=0 && xx<n && yy>=0 && yy<m && map[xx][yy]==0){
            map[xx][yy]=step;
            go(step+1,xx,yy);
            map[xx][yy]=0;
        }
    }
    //step--;

}
int main(){
    int t,x,y,i;
    std::cin>>t;
    for (i=0;i<t;i++){
        ans=0;
        step0=1;
        memset(map,0,sizeof(map));
        std::cin>>n>>m>>x>>y;
        map[x][y]=1;
        go(step0,x,y);
        std::cout<<ans;
    }
}