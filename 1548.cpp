#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#define INF 0x3fffffff
int t[210],f[210];
int main()
{
	int n,begin,end;
	int jj[3]={0,1,-1};
	queue<int>q;
	while (~scanf("%d",&n) && n)
	{
		//memset(vist,0,sizeof(vist));
		scanf("%d%d",&begin,&end);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
			t[i]=INF;
		}
		t[begin]=0;
		//vist[begin]=1;
		q.push(begin);
		while (!q.empty())
		{
			int now=q.front();
			q.pop();
			for (int j=1;j<=2;j++)
			{
				int k=now+f[now]*jj[j];
				if (k>=1 && k<=n && t[k]>t[now]+1)
				{
					t[k]=t[now]+1;
					q.push(k);
				}
			}
		}
		if (t[end]==INF) printf("-1\n");
		else printf("%d\n",t[end]);
	}
	return 0;
} 
