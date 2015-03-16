#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int k;
int a[10000010];
int b[10000001];
map<int,int>mp;
int ss()
{
	int i,j;
	k=1;
	mp.clear();
	memset(a,0,sizeof(a));
	for (i=2;i<=10000000;i++)
		if (a[i]==0)
		{
			b[k++]=i;
			mp[i]=1;
			for (j=i*2;j<=10000000;j+=i)
				a[j]=1;
		}
}
int main()
{
	int n,i,j;
	ss();
	while (~scanf("%d",&n))
	{
		if (n<8) 
		{
			printf("Impossible.\n");
			continue;
		}
		if (n % 2 ==0 )
		{
			printf("2 2");
			n-=4;
			if (mp[n/2])
			{
				printf(" %d %d\n",n/2,n/2);
				continue;
			}
			for (i=1;i<k;i++)
			if (mp[n-b[i]]) 
			{
				printf(" %d %d\n",b[i],n-b[i]);
				break;
			}
		}
		else 
		{
			n-=2;
			int flag=1;
			for (i=1;i<k;i++)
				if (mp[n-2*b[i]] && n-2*b[i]>0) 
				{
					printf("2 %d %d %d\n",b[i],b[i],n-2*b[i]);
					flag=0;
					break;
				}
			if (flag) printf("Impossible.\n");
		}
	}
	return 0;
}
