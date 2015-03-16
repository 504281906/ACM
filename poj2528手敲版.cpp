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
struct node
{
	int l,r,ans;
}f[10010];
using namespace std;
int n; 
void cover(int l,int r,int now,int k)
{
	while (k<n && (f[k].l>r || f[k].r<l)) //now的上面没有覆盖到now 
		k++;
	if (k>=n)
	{
		f[now].ans+=r-l+1;
		return;
	}
	if (l<f[k].l)
		cover(l,f[k].l-1,now,k+1);	
	if (r>f[k].r)
		cover(f[k].r+1,r,now,k+1);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		memset(f,0,sizeof(f));
		int s=0,i;
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%d%d",&f[i].l,&f[i].r);
		for (i=n-1;i>=0;i--)
		{
			cover(f[i].l,f[i].r,i,i+1);
			if (f[i].ans>0) s++;
		}
		cout<<s<<endl;
	}
	return 0;
}
