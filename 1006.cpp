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
using namespace std;
#define LL __int64
#define M 100
int a[3010];
LL c[300],ans[300],cc[300];
void MUL(LL x)
{
	for (int i=1;i<=ans[0];i++)
		ans[i]=ans[i]*x;
	for (int i=1;i<=ans[0];i++)
	{
		ans[i+1]+=ans[i]/M;
		ans[i]=ans[i]%M;
	}
	while (ans[ans[0]+1])
	{
		ans[0]++;
		ans[ans[0]+1]=ans[ans[0]]/M;
		ans[ans[0]]%=M;	
	}
}
void ADD()
{
	int f=-1,i;
	if (ans[0]<0)
	{
		if (-ans[0]>c[0]) f=1;
		else if (-ans[0]<c[0]) f=0;
		else
		{
			for (i=c[0];i>0;i--)
				if (ans[i]>c[i])
				{
					f=1;
					break;
				}
				else if (ans[i]<c[i])
				{
					f=0;
					break;
				}
			if (i==0)
			{
				memset(ans,0,sizeof(ans));
				ans[0]=1;
				return;
			}
		}
	}
	else
	{
		int l=max(ans[0],c[0]);
		for (i=1;i<=l;i++)
		{
			ans[i+1]+=(ans[i]+c[i])/M;
			ans[i]=(ans[i]+c[i])%M;
		}
		while (ans[ans[0]+1])
		{
			ans[0]++;
			ans[ans[0]+1]+=ans[ans[0]]/M;
			ans[ans[0]]%=M;
		}
		return;
	}
	if (f!=-1)
	{
		if (f)
		{
			for (i=1;i<=-ans[0];i++)
			{
				ans[i]-=c[i];
				if (ans[i]<0)
				{
					ans[i]+=M;
					ans[i+1]-=1;
				}
			}
			while (ans[-ans[0]]==0) ans[0]++;
		}
		else
		{
			for (i=1;i<=c[0];i++)
			{
				ans[i]=c[i]-ans[i];
				if (ans[i]<0)
				{
					ans[i]+=M;
					c[i+1]--;
				}
			}
			ans[0]=c[0];
			while (ans[ans[0]]==0) ans[0]--;
		}
	}
}
void SUB()
{
	int i;
	if (ans[0]<0)
	{
		int l=max(-ans[0],c[0]);
		for (i=1;i<=l;i++)
		{
			ans[i+1]+=(ans[i]+c[i])/M;
			ans[i]=(ans[i]+c[i])%M;
		}
		while (ans[-ans[0]+1]) 
		{
			ans[0]--;
			ans[-ans[0]+1]+=ans[-ans[0]]/M;
			ans[-ans[0]]%=M;
		}
	}
	else 
	{
		int f=0;
		if (ans[0]>c[0]) f=1;
		else if (ans[0]<c[0]) f=0;
		else
		{
			for (i=ans[0];i>0;i--)
			if (ans[i]>c[i])
			{
				f=1;
				break;
			}
			else if (ans[i]<c[i])
			{
				f=0;
				break;
			}
			if (i==0)
			{
				memset(ans,0,sizeof(ans));
				ans[0]=1;
				return;
			}
		}
		if (f)
		{
			for (i=1;i<=ans[0];i++)
			{
				ans[i]-=c[i];
				if (ans[i]<0)
				{
					ans[i+1]--;
					ans[i]+=M;
				}
			}
			while (ans[ans[0]]==0) ans[0]--;
		}
		else
		{
			for (i=1;i<=c[0];i++)
			{
				ans[i]=c[i]-ans[i];
				if (ans[i]<0)
				{
					ans[i]+=M;
					c[i+1]--;
				}
			}
			ans[0]=-c[0];
			while (ans[-ans[0]]==0) ans[0]++;
		}
	}
}
int main()
{
	int T,i;
	__int64 n;
	int cas=1;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%I64d",&n);
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		int j=0;   //0- 1+ 
		c[0]=1;
		c[1]=7;
		ans[0]=1;
		ans[1]=n;
		LL x=n;
		MUL(8);
		SUB();
		MUL(x);
		c[1]=1;
		ADD();
		printf("Case #%d: ",cas++);
		printf("%I64d",ans[ans[0]]);
		for (i=ans[0]-1;i>0;i--)
			printf("%02I64d",ans[i]);
		printf("\n");
	}
	return 0;
}
