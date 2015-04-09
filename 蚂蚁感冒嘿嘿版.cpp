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
struct point
{
	int f,x,num;
}a[55];
bool cmp(point a,point b)
{
	return a.x<b.x;
}
int main()
{
	int n,i;
	while (~scanf("%d",&n))
	{
		for (i=0;i<n;i++)
		{
			int k;
			scanf("%d",&k);
			a[i].f=k<0?-1:1;
			a[i].num=i+1;
			a[i].x=abs(k);
		}
		int left=0,right=0,pos,ans=0;
		sort(a,a+n,cmp);
		for (i=0;i<n;i++)
			if (a[i].num==1)
			{
				pos=i;
				break;
			}
			else if (a[i].f>0) left++;
		for (i=pos+1;i<n;i++)
			if (a[i].f<0) right++;
		if (a[pos].f==1 && right==0 || a[pos].f==-1 && left==0)
			ans=1;
		else 
			ans=left+right+1;
		printf("%d\n",ans);
	}
	return 0;
}
