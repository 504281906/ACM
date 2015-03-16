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
#define LL __int64
using namespace std;
int t,a[1000010],p[1000010];
void getp(int n)
{
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	t=0;
	for (int i=2;i<=n;i++)
	{
		if (!a[i])
			p[t++]=i;
		for (int j=0;p[j] && i*p[j]<=n;j++)
		{
			a[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
}
LL mul(LL a, LL b, LL mod) {
    LL ret = 0;
    while (b > 0) {
	if (b&1) ret = (ret + a) % mod;
	b >>= 1;
	a = (a<<1) % mod;
    }
    return ret;
}

LL pow_mod(LL x, LL k, LL mod) {
    LL ans = 1;
    while (k) {
	if (k&1) ans = mul(ans, x, mod);
	x = mul(x, x, mod);
	k >>= 1;
    }
    return ans;
}

bool mlrb (LL n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 0; i < 20; i++) {
	LL a = rand() % (n - 1) + 1;
	if (pow_mod(a, n - 1, n) != 1)
	    return false;
    }
    return true;
}
int main()
{
	int i;
	LL n;
	getp(1000005);
	//printf("%d",t);
	while (~scanf("%I64d",&n) && (n!=-1))
	{
		if (n==1 || n==2 || n==4) 
		{
			printf("%I64d\n",n-1);
			continue;
		}
		if (n % 4==0) 
		{
			puts("1");
			continue;
		}
		LL m=n;
		if (m % 2==0) 
			m/=2;
		LL k=0;
		for (i=0;i<t && p[i]<m;i++)
			if (m % p[i]==0)
			{
				while (m%p[i]==0)
					m/=p[i];
				if (m==1) k=1;
				break;
			}
		m=n;
		if (m % 2==0) 
			m/=2;
		if (k==1) printf("%I64d\n",n-1);
		else
		{
			if (mlrb(m)) printf("%I64d\n",n-1);
			else
			{
				k=sqrt(m*1.0);
				if (k*k==m) printf("%I64d\n",n-1);
				else puts("1");
			}
		}  
	}
	return 0;
}
