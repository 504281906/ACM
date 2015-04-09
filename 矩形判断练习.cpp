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
#include <ctime>
#define LL long long
#define EPS 1e-8
using namespace std;
struct node
{
	LL x,y;
}f[5][3];
int pd(LL x,LL y)
{
	int i,j;
	node s[3];
	int t=1;
	for (i=1;i<=4;i++)
		for (j=1;j<=2;j++)
		{
			if (f[i][j].x==x && f[i][j].y==y)
			{
				s[t].x=f[i][3-j].x-x;
				s[t].y=f[i][3-j].y-y;
				//cout<<s[t].x<<s[t].y<<endl;
				t=2;
			}
		}
	int ans=s[1].x*s[2].x+s[1].y*s[2].y;
	if (ans!=0) return 1;
	return 0;
}
node d[10];
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while (T--)
	{
		map < pair<LL ,LL> ,int>mp;
		for (i=1;i<=4;i++)
			for (j=1;j<=2;j++)
			{
				scanf("%lld%lld",&f[i][j].x,&f[i][j].y);
				pair<LL ,LL> t;
				t=make_pair(f[i][j].x,f[i][j].y);
				mp[t]++;
			}
		map < pair<LL ,LL> ,int>::iterator it;
		int flag=0;
		for (it=mp.begin();it!=mp.end();it++)
		{
			d[flag].x=(*it).first.first;
			d[flag].y=(*it).first.second;
			flag++;
			//cout<<(*it).first.first<<" "<<(*it).first.second<<endl;
			if ((*it).second!=2)
			{
				flag=0;
				break;
			}
		}
		if (flag!=4)
		{
			puts("NO");
			continue;
		}
		flag=1;
		for (i=0;i<4;i++)
			if (pd(d[i].x,d[i].y))
			{
				puts("NO");
				flag=0;
				break;
			}
		if (flag) puts("YES");
	}
	return 0;
}
