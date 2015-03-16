#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#define LL __int64
#define EPS 1e-8
using namespace std;
int a[50010];
int b[50010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while (~scanf("%d",&n))
	{
		int t=1,k;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		map<int,int>mp;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&k);
			if (k==a[t-1]) continue;
			if (mp[k]==0) mp[k]=t;
			else
			{
				b[mp[k]]=t;
				mp[k]=t;
			}
			a[t++]=k;
		}
		n=t-1;
		LL ans=0;
		for (i=1;i<=n;)
		{
			if (b[i]==0)
			{
				ans++;
				i++;
				continue;
			}
			k=i;
			int id=i+1;
			LL s=1;
			while (b[k] && k<=n)
			{
				t=1;
				int flag=1;
				for (int j=i+1;j<b[k];j++)
				{
					if (b[j]!=0 && b[j]<=b[k]) continue;
					t++;
					if (t*t>b[k]-i+1) 
					{
						flag=0;
						break;
					}
				}
				if (flag)
				{
					s=t*t;
					id=b[k]+1;
				}
				k=b[k];
			}
			ans+=s;
			i=id;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
