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
#define LL long long
LL gcd(LL a,LL b)
{
	return b==0?a:gcd(b,a%b);
}
struct node
{
	LL z,l,r;
	node (LL a,LL b,LL c):z(a),l(b),r(c){}
	bool operator <(node b) const
	{
		return z<b.z;
	}
};
int ll[3010],rr[3010];
LL a[3010],b[3010];
bool vis[3010][3010];
int main()
{
	LL T,i,n;
	scanf("%I64d",&T);
	while (T--)
	{
		memset(vis,0,sizeof(vis));
		LL ans=0;
		scanf("%I64d",&n);
		priority_queue<node>q;
		for (i=1;i<=n;i++)
		{
			ll[i]=i;
			rr[i]=i;
			scanf("%I64d",&a[i]);
			ans+=a[i];
			b[i]=a[i];
			if (i>1)
				q.push(node(gcd(a[i],a[i-1]),i-1,i));
		}
		LL t=0;
		while (!q.empty())
		{
			node k=q.top();
			q.pop();
			if ((!vis[k.l][k.r]) && (k.z==gcd(b[k.l],b[k.r])))
			{
				t++;
				ans+=k.z;
				int l1=ll[k.r]=ll[k.l];
				int r1=rr[k.l]=rr[k.r];
				b[l1]=b[r1]=k.z;
			//	printf("%I64d %I64d %I64d\n",k.z,k.l,k.r);
				vis[k.l][k.r]=1;
				if (l1!=1)
					q.push(node(gcd(b[l1],b[l1-1]),l1-1,l1));
				if (r1!=n)
					q.push(node(gcd(b[r1],b[r1+1]),r1,r1+1));
			}
			if (t==n-1) break;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
