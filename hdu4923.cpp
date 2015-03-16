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
#define EPS 1e-8
using namespace std;
struct node
{
	int x,y;//分别一个10区间代表1的个数，0的个数，和平均值 
	double z;
}f[50010]; 
int main()
{
	int T,i,k,n;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int t=0,flag=1;
		memset(f,0,sizeof(f));
		for (i=1;i<=n;i++)
		{
			scanf("%d",&k);
			if (t==0 && k==0) continue;
			if (k==1)
			{
				if (flag==1)
				{
					if (t!=0) f[t].z=(f[t].x*1.0)/(f[t].x+f[t].y);
					t++;
					flag=0;
				}
				f[t].x++;
			}
			else 
			{
				flag=1;
				f[t].y++;
			}
		}
		if (k==1) t-=1;
		else f[t].z=(f[t].x*1.0)/(f[t].x+f[t].y);
		stack<node>st;
		for (i=1;i<=t;i++)
		{
			while (!st.empty())
			{
				node s=st.top();
				if (f[i].z-s.z>=EPS)
				{
					st.push(f[i]);
					break;
				}
				else
				{
					f[i].x+=s.x;
					f[i].y+=s.y;
					f[i].z=(f[i].x*1.0)/(f[i].x+f[i].y);
					st.pop();
				}
			}
			if (st.empty()) st.push(f[i]);
		}
		double ans=0.0;
		while (!st.empty())
		{
			node s=st.top();
			st.pop();
			ans+=pow(1-s.z,2)*s.x*1.0+pow(s.z,2)*s.y*1.0;
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}
