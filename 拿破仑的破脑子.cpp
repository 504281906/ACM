#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int G[31][31],p[31],N,T,M;
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        int x,y;
        for(int i=1;i<=N;i++){
            scanf("%d%d",&x,&y);
            p[x]=y-1;
        }
        memset(G,-1,sizeof(G));
        int z;
        scanf("%d",&M);
        for(;M;M--){
            scanf("%d%d%d",&x,&y,&z);
            G[x][y]=z;
        }
        for(int i=1;i<=N;i++){
            for(int j=i+1;j<=N;j++){
                if(p[i]==p[j]) G[i][j]=G[j][i]=0;
            }
        }
        bool flag=true;
        while(flag)
		{
            flag=false;
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    if(j!=i&&G[j][i]!=-1&&p[i]>p[j]+G[j][i]){
                        p[i]=p[j]+G[j][i];
                        flag=true;
                    }
                }
            }
        }
        int res=0;
        flag=false;
        for(int i=1;i<=N;i++){
            flag=false;
            for(int j=1;j<=N;j++){
                if(j==i) continue;
                for(int k=j+1;k<=N;k++){
                    if(k==i) continue;
                    if(p[i]==p[j]+p[k]){
                         flag=true;
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
            if(flag) res++;
        }
        for(int i=1;i<=N;i++) printf("%d %d\n",i,p[i]);
        printf("%d\n",res);
    }
    return 0;
}
