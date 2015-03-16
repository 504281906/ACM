#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <algorithm>
using namespace std;
const int MM=999999;
const int M=2503;
int lu[M][M];
int dis[M];
int vis[M];
int Q[M];
int SPFA(int n,int s)
{
    int i,j,k,st,en;
    for(i=1;i<=n;i++){
        vis[i]=0;
        dis[i]=MM;
    }
    for(i=0;i<M;i++)
        Q[i]=0;
    vis[s]=1;dis[s]=0;
    st=0;en=1;
    Q[0]=s;
    while(st<en)
    {
        k=Q[st];
        for(i=1;i<=n;i++)
        {
            if(lu[k][i]!=MM&&dis[k]+lu[k][i]<dis[i])
            {
                dis[i]=dis[k]+lu[k][i];
                if(!vis[i]){
                    Q[en++]=i;
                    vis[i]=1;
                }
            }
        }
        vis[k]=0;
        st++;
    }
    return 1;
}
int main()
{
    int T,R,P,S;
    int i,j,k,a,b,c;
    while(scanf("%d%d%d%d",&T,&R,&P,&S)!=EOF)
    {
        for(i=1;i<=T;i++)
            for(j=1;j<=T;j++)
                lu[i][j]=MM;
        for(i=0;i<R;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c<lu[a][b]){
                lu[a][b]=lu[b][a]=c;
            }
        }
        for(i=0;i<P;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c<lu[a][b]){
                lu[a][b]=c;
                lu[b][a]=MM;
            }
        }
        SPFA(T,S);
        for(i=1;i<=T;i++)
        if(dis[i]!=MM)
        printf("%d\n",dis[i]);
        else
            printf("NO PATH\n");
    }
    return 0;
}
