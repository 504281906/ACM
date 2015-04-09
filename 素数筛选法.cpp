#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#define max 1010000
using namespace std;
int a[max+10],p[max+10];
int main()
{
	int i,j,k=0,n;
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	for (i=2;i<=max;i++)
	{
		if (a[i]==0)
			p[++k]=i;
		for (j=1,n;p[j]!=0 && ((n=i*p[j])<=max);j++)
		{
			a[n]=1;
			if (i % p[j]==0) break;
		}
	}
	printf("%5d\n",p[k]);
}
