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
#define LL __int64
#define EPS 1e-8
using namespace std;
struct node
{
	int time,id;
}f[15];
int n,t,m,i,tt,dd;
char p;
char sta[5];
struct node1
{
	int pp[15];
}team[110];
int main()
{
	while (~scanf("%d%d%d",&n,&t,&m))
	{
		memset(team,0,sizeof(team));
		memset(f,0,sizeof(0));
		for (i=1;i<=m;i++)
		{
			scanf("%d %d %c %s",&tt,&dd,&p,&sta);
			//cout<<tt<<dd<<p<<sta<<endl;
			if (sta[0]=='N') continue;
			if (team[dd].pp[p-'A']==1) continue;
			team[dd].pp[p-'A']=1;
			f[p-'A'].time=tt;
			f[p-'A'].id=dd;
		}
		for (i=1;i<=n;i++)
		{
			printf("%c ",'A'+i-1);
			if (f[i-1].id==0) printf("- -\n");
			else printf("%d %d\n",f[i-1].time,f[i-1].id);
		}
	}
	return 0;
}
