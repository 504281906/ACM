#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define ll __int64
using namespace std;
ll e[1000005],b,p,n;
ll a;
ll m1[2][2],m2[2][2],m3[2][2];
int oula(int n)
{
	int i,j;
	memset(e,0,sizeof(e));
	e[1]=1;
	for (i=2;i<=n;i++)
	{
		if (e[i]==0)
		for (j=i;j<=n;j+=i)
		{
			if (e[j]==0)
				e[j]=j;
			e[j]=e[j]*(i-1)/i;
		}	
	}
}
ll KSM(ll a,ll b,ll p)
{
	ll s=1;
	while (b)
	{
		if (b & 1) s=s*a % p;
		a=a*a % p;
		b>>=1;
	}
	return s;
}
void jc(ll m1[2][2],ll m2[2][2])
{
	int i,j,k;
	for (i=0;i<2;i++)
		for (j=0;j<2;j++)
		{
			m3[i][j]=0;
			for (k=0;k<2;k++)
				m3[i][j]=m3[i][j]+m1[i][k]*m2[k][j];
			if (m3[i][j]>=e[p]*2)
				m3[i][j]=(m3[i][j]%e[p])+e[p];
		}
		memcpy(m1,m3,sizeof(m3));
}
void fib(int m)
{
	m1[0][0]=m1[1][1]=1;
	m1[0][1]=m1[1][0]=0;
	m2[0][0]=m2[1][0]=m2[0][1]=1;
	m2[1][1]=0;
	while (m)
	{
		if (m & 1) jc(m1,m2);
		jc(m2,m2);
		m>>=1;
	}
}
void ff()
{
	fib(n-2);
	printf("%I64d\n",KSM(a,m1[0][1],p)*KSM(b,m1[0][0],p)%p);
} 
int main()
{
	oula(1000000);
	int T;
	int t=1;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%I64d %I64d %I64d %I64d",&a,&b,&p,&n);
		printf("Case #%d: ", t++);
        if (n == 1) printf("%I64d\n", a % p);  
      	else if (n == 2) printf("%I64d\n", b % p);  
      	else ff();
	} 
	return 0;
}
