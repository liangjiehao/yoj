#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct point
{
    int first;
    int next;
    int rec;
} p[200001];
int out[100001], in[100001], st[100001];
int f[100001];
int dp(int x)
{

    if (f[x])
        return f[x];
    if (out[x] == 0)
        return 1;
    //for (int i = 0; i < out[x]; i++)f[x] += dp(p[st[x] + i].next);
    for (int i = st[x]; i; i=p[i].rec)f[x] += dp(p[i].next);
    return f[x];
}
int n, m;
int main()
{
    int x, y, ans = 0;
    scanf("%d %d", &n, &m);
    //memset(st, -1, sizeof(st));
    memset(st,0,sizeof(st));
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &x, &y);
        in[y]++;
        out[x]++;
        p[i].first = x;
        p[i].next = y;
        p[i].rec=st[x];
        st[x]=i;
        //if (st[x] == -1)st[x] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!in[i] && out[i])
        {
            ans += dp(i);
        }
    }
    printf("%d", ans );
    return 0;
}