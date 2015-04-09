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
int main()
{
	long long a[110],b[110];
	int T,n,cas,i;
	scanf("%d",&T);
	double max=9223372036854775808;
	for (cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		a[0]=n;
		b[0]=n;
		int k=1;
		long long s=1;
		int fa=1,fb=1,flag=0,j=0;
		int fh=1;
		while (k<=100)
		{
			a[k]=a[k-1]+s*fh;
			b[k]=b[k-1]-s*fh;
			if (a[k]>max) fa=0;
			if (b[k]>max) fb=0;
			if (s>max) break;
			if (k>=3)
			{
				if (a[k] % a[k-1]==0 && fa && a[k]!=0)
				{
					flag=1;
					j=k;
					break;
				}
				if (b[k] % b[k-1]==0 && fb && b[k]!=0)
				{
					flag=2;
					j=k;
					break;
				}
			}
			s*=2;
			fh*=-1;
			k++;
		}
		printf("Case %d: ",cas);
		if (flag==0) printf("no solution\n");
		else if (flag==1)
		{
			printf("%lld",a[j]);
			for (i=j-1;i>0;i--)
			if (a[i+1]>a[i])
				printf(" %lld",(a[i+1]-a[i]));
			else
				printf(" %lld",(a[i]-a[i+1]));
			printf(" 1\n");
		}
		else if (flag==2)
		{
			printf("%lld",b[j]);
			for (i=j-1;i>0;i--)
			if (b[i+1]>b[i])
				printf(" %lld",(b[i+1]-b[i]));
			else
				printf(" %lld",(b[i]-b[i+1]));
			printf(" 1\n");
		}
	}
	return 0;
}
