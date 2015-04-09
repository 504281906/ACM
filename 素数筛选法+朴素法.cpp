#include <iostream>  //利用朴素和筛选法判断素数。 
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int M=1e9+1;
const int N=sqrt(M); 
int t;
int a[1000000];
int p[1000000];
void sf(long long  n)
{
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	t=0;
	for (int i=2;i<n;i++)
	{
		if (!a[i])
			p[t++]=i;
		for (int j=0;p[j] && (p[j]*i)<=n;j++)
		{
			a[p[j]*i]=1;
			if (i % p[j]==0) break;
		}
	}
} 
int pd(long long n)
{
	for (int i=0;p[i]*p[i]<=n;i++)
		if (n % p[i]==0) 
		return 0;
	return 1;
}
int main()
{
	long long h=sqrt(M);
	sf(h);
	long long n;
	while (~scanf("%lld",&n))
	{
		int k=pd(n);
		printf(k==1?"Yes\n":"No\n");
	}
	return 0;
}
