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
#define M 100000000000
int a[3010];
LL c[300],ans[300],cc[300];
void MUL(int x)
{
	for (int i=1;i<=c[0];i++)
		c[i]=c[i]*x;
	for (int i=1;i<=c[0];i++)
	{
		c[i+1]+=c[i]/M;
		c[i]=c[i]%M;
	}
	while (c[c[0]+1])
	{
		c[0]++;
		c[c[0]+1]=c[c[0]]/M;
		c[c[0]]%=M;	
	}
}
void DIV(int y)
{
	for (int i=c[0];i>1;i--)
	{
		c[i-1]+=(c[i]%y)*M;
		c[i]/=y;
	}
	c[1]/=y;
	while (c[c[0]]==0) c[0]--;
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
	int T,n,i,x,y;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		int j=0;   //0- 1+ 
		c[0]=1;
		c[1]=1;
		ans[0]=-1;
		ans[1]=a[1];
		if (n&1) 
		{
			ans[0]=1;
			j=1;
		}
		x=n-1,y=1;
		for (i=2;i<=n;i++)
		{
			j=(j+1)%2;
			MUL(x);
			x--;
			DIV(y);
			y++;
			memcpy(cc,c,sizeof(c));
			MUL(a[i]);
			if (j) ADD();
			else SUB();
			memcpy(c,cc,sizeof(cc));
		}
		if (ans[0]<0)
		{
			printf("-");
			ans[0]=-ans[0];
		}
		printf("%I64d",ans[ans[0]]);
		for (i=ans[0]-1;i>0;i--)
			printf("%011I64d",ans[i]);
		printf("\n");
	}
	return 0;
}
