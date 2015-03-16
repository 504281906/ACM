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
#define ll __int64
char a[1100][1100];
int b[1100];
int n,i,j;
int main()
{
	while (~scanf("%d",&n) && n)
	{
		int t=0;
		getchar();
		int f=0,o=0;
		for (i=1;i<=n;i++)
		{
			scanf("%s",&a[i]);
			if (o>=2) f=1;
			if (strstr(a[i],"x")) o++;
			else o=0;
			if (strstr(a[i],"x")==NULL && i!=1 && strstr(a[i-1],"x")==NULL)
			{
				int k1=atoi(a[i]);
				int k2=atoi(a[i-1]); //k1是后一个 
				if (i % 2==0) 
				{
					if (k1<=k2) f=1;
				}
				else if (k1>=k2) f=1;
			}
			if (strstr(a[i],"x"))
				b[t++]=i;
		}
		if (f==1 || t==n)
		{
			printf("none\n");
			continue;
		}
		else if (t==0) 
		{
			printf("ambiguous\n");
			continue;
		}
		ll min=-1e9-100,max=1e9+100;
		for (i=0;i<t;i++)
		{
			if (b[i] % 2==0) //偶数,大于周边min
			{
				if (strstr(a[b[i]-1],"x")==NULL && b[i]-1!=0)
				{
					int k=atoi(a[b[i]-1]);
					if (min<k) min=k;
				}
				if (strstr(a[b[i]+1],"x")==NULL && b[i]+1<=n)
				{
					int k=atoi(a[b[i]+1]);
					if (min<k) min=k;
				}
			}
			else
			{
				if (strstr(a[b[i]-1],"x")==NULL && b[i]-1!=0)
				{
					int k=atoi(a[b[i]-1]);
					if (max>k) max=k;
				}
				if (strstr(a[b[i]+1],"x")==NULL && b[i]+1<=n)
				{
					int k=atoi(a[b[i]+1]);
					if (max>k) max=k;
				}
			}
		}
		if (max-min==2) printf("%I64d\n",min+1);
		else if (max-2>min) printf("ambiguous\n");
		else printf("none\n");
	}
	return 0;
}
