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
const LL p=1000000009;
LL ss[100010];
__int64 pmod = 1000000009;
__int64 inv[100005];
__int64 ba[100005];
__int64 rba[100005];
LL Pow(LL a,LL b,LL mod)  
{  
    LL ans=1;  
    while(b)  
    {  
        if(b&1)
            ans=(ans*a)%mod;   
        b>>=1;  
        a=(a*a)%mod;   
    }  
    return ans;  
}  
/*LL C(LL n,LL m)  
{  
    if(n<m)  
        return 0;  
    LL ans=1;  
    for(LL i=1;i<=m;i++)  
    {
        ans=ans%p*(((n-m+i)%p)*ss[i]%p)%p;  
    }
    return ans;  
}
LL Lucas(LL n,LL m)  
{  
    if(m==0)  
        return 1;  
    return (Lucas(n/p,m/p)*C(n%p,m%p))%p;  
}*/
void pre() {
	inv[0] = inv[1] = 1;
	ba[0] = ba[1] = 1;
	rba[0] = rba[1] = 1;
	for (int i = 2; i < 100005; i++) {
		inv[i] = ((pmod - pmod / i) * inv[pmod % i]) % pmod;
		ba[i] = (ba[i - 1] * i)%pmod;
		rba[i] = (rba[i - 1] * inv[i])%pmod;
	}
}
__int64 C(int n, int k) {
	return (ba[n] * rba[k] % pmod )* rba[n - k] % pmod;
}
int main()
{
	//freopen("1009.in","r",stdin);
//	freopen("out.txt","w",stdout);
	pre();
	LL n,m,x,i;
//	for (i=1;i<=100000;i++)
//		ss[i]=Pow(i,p-2,p)%p;
	while (~scanf("%I64d%I64d",&n,&m))
	{
		scanf("%I64d",&x);
		int l=x,r=x;
		for (i=2;i<=n;i++)
		{
			scanf("%I64d",&x);
			int ll=l;
			int rr=r;
			if (l-x>=0) ll=l-x;
			else if (r>=x) ll=(r-x)&1;
			else ll=x-r;
			if (r+x<=m) rr=r+x;
			else
			if (l+x<=m) rr=m-((m-l-x)&1);
			else rr=m-(x-(m-l));
			l=ll;
			r=rr;
		}
		cout<<l<<" "<<r<<endl;
		LL ans=0;
		for (i=l;i<=r;i+=2)
			ans=(ans+C(m,i)) % p;
		printf("%I64d\n",ans);
	}
	return 0;
}
