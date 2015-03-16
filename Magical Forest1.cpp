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
int w,cas,i,k,c,q,x,y;
int n,m,s;
int main()
{
	scanf("%d",&w);
	map<int,int>mh;
	map<int,int>ml;
	map<int,map<int,int> >mz;
	for (cas=1;cas<=w;cas++)
	{
		printf("Case #%d:\n",cas);
		scanf("%d%d%d",&n,&m,&k);
		mh.clear();
		ml.clear();
		mz.clear();
		while (k--)
		{
			scanf("%d%d%d",&x,&y,&c);
			mh[x]=x;
			ml[y]=y;
			mz[x][y]=c;
		}
		scanf("%d",&k);
		while (k--)
		{
			scanf("%d%d%d",&q,&x,&y);
			if (q==1)
					{
						s=mh[x];
						mh[x]=mh[y];
						mh[y]=s;
					}
			else if(2==q)
					{

						s=ml[x];
						ml[x]=ml[y];
						ml[y]=s;
					}
			else if (q==3)
					{
						if (mh.find(x)!=mh.end() && ml.find(y)!=ml.end())
						{
							printf("%d\n",mz[mh[x]][ml[y]]);
						}
						else puts("0");
						//break;
					}
		}
	}
	return 0;
}
