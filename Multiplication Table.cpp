#include <bits/stdc++.h> 
using namespace std;
#define ll __int64
ll n,m,k;
ll cnt(ll s)
{
	ll t=0;
	for (int i=1;i<=n;i++)
	{
		ll h=s/i;
		if (h>m)
			h=m;
		t+=h;
	}
	return t;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	ll l=1;
	ll r=n*m+1;
	while (l<r)
	{
		ll mid=(l+r)/2;
		if (cnt(mid)<k)
			l=mid+1;
		else 
			r=mid;
	}
	cout<<r<<endl;
}
