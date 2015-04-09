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
//#define DEBUG
const LL M=1000000009;
LL c[100110];
LL ksm(LL a,LL b)
{
	LL ans=1;
	while (b)
	{
		if (b&1)
			ans=ans* a % M;
		b>>=1;
		a=a*a%M;
	}
	return ans;
}
int main()
{
	LL n,m;
//	freopen("1009.in","r",stdin);
	while (~scanf("%I64d%I64d",&n,&m))
	{
		LL l=0,r=0;
		for (int i=1;i<=n;i++)
		{
			LL ll,rr,x;
			scanf("%I64d",&x);
			if (l>=x) ll=l-x;
			else if (r>=x) ll=(l+x)&1;
			else ll=x-r;
			if (r+x<=m) rr=r+x;
			else if (l+x<=m) rr=m-((m+l+x)&1);
			else rr=2*m-l-x;
			l=ll;
			r=rr;
		}
		c[0]=1;
	//	cout<<l<<" "<<r<<endl;
		for (int i=1;i<=m;i++)
			if (m-i<i) c[i]=c[m-i];
			else c[i]=((c[i-1]*(m-i+1))%M * ksm(i,M-2))%M;
		LL ans=0;
		for (int i=l;i<=r;i+=2)
			ans=(ans+c[i]) % M;
		cout<<ans<<endl;
	}
	return 0;
}
