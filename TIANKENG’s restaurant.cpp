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
struct node
{
	int s,kf,km,jf,jm;
}a[110];
int cmp(node a,node b)
{
	if (a.kf==b.kf) 
		if (a.km==b.km)
			if (a.jf==b.jf) return a.jm<b.jm;
				else return a.jf<b.jf;
		else return a.km<b.km;
	else return a.kf<b.kf;	
}
int T,n,i;
#define LL __int64
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d %d:%d %d:%d",&a[i].s,&a[i].kf,&a[i].km,&a[i].jf,&a[i].jm);
		sort(a+1,a+1+n,cmp);
		int max=a[1].s,k=a[1].s;
		int jf=a[1].jf,jm=a[1].jm;
		for (i=2;i<=n;i++)
		{
			if (a[i].kf<jf || (a[i].kf==jf && a[i].km<jm))
				k+=a[i].s;
			else 
			{
				if (k>max) max=k;
				k=a[i].s;
			}
			if (a[i].jf>jf || (a[i].jf==jf && a[i].jm>jm))
			{
				jf=a[i].jf;
				jm=a[i].jm;
			}
		}
		if (k>max) max=k;
		cout<<max<<endl;
	}
	return 0;
}
