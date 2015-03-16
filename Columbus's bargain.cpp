#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int a[100],vis[100],d[100][100],n,m;
void ff(int k)
{
	int i;
	for (i=1;i<=n;i++)
		if ( d[i][k]!=-1 )
		{
			if (vis[i]==0)
			{
				vis[i]=1;
				ff(i);
			}
			a[k]=min(a[k],a[i]+d[i][k]);
		}
}
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		memset(d,-1,sizeof(d));
		memset(vis,0,sizeof(vis));
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&j,&a[i]);
			a[i]--;
			for (j=1;j<i;j++)
				if (a[i]==a[j]) d[i][j]=d[j][i]=0;
		}
		scanf("%d",&m);
		for (i=0;i<m;i++)
		{ 
			int q,w,v;
			scanf("%d%d%d",&q,&w,&v);
			if (d[q][w]>v || d[q][w]==-1)
				d[q][w]=v;
		}
		for (i=1;i<=n;i++)
			if (vis[i]==0)
			{
				vis[i]=1;
				ff(i);
			}
		for (i=1;i<=n;i++)
		{
			printf("%d %d\n",i,a[i]);
		}
		int res=0;
        bool flag=false;
        for(int i=1;i<=n;i++){
            flag=false;
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                for(int k=j+1;k<=n;k++){
                    if(k==i) continue;
                    if(a[i]==a[j]+a[k]){
                         flag=true;
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
            if(flag) res++;
        }
		printf("%d\n",res);
	}
	return 0;
}
