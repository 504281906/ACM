#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
const int maxn=100005;
vector<int>V[maxn];
int Num[maxn],ans[maxn][2];
int  maxv(int a,int b)
{ 
	return a>b?a:b;
}
void dp(int L,int G)
{
    int tv;
	for(int i=0;i<V[L].size();i++)
	{
        tv=V[L][i];
    	if(G!=tv)
		{
            dp(tv,L);
            ans[L][1]+=ans[tv][0];
    		ans[L][0]+=(ans[tv][0]>ans[tv][1]?ans[tv][0]:ans[tv][1]);
        }
	}
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
	{
        for(int i=1;i<=n;i++)
            V[i].clear();
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
            scanf("%d",&ans[i][1]);
        int u,v;
        for(int i=1;i<n;i++)
		{
           scanf("%d%d",&u,&v);
            V[u].push_back(v);
            V[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
		{
            if(V[i].size()==1)
			{
                dp(i,-1);
                int an=ans[i][0]>ans[i][1]?ans[i][0]:ans[i][1];
                printf("%d\n",an);
				break;
            }
        }
    }
    return 0;
}
