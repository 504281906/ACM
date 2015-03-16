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
LL a[10][4];
double dis(LL x[3],LL y[3])
{
	return (x[0]-y[0])*(x[0]-y[0])+(x[2]-y[2])*(x[2]-y[2])+(x[1]-y[1])*(x[1]-y[1]);
}
void DFS(int k)
{
	if (k!=8)
	{
		sort(a[k],a[k]+3);
		do
		{
			DFS(k+1);
		}while(next_permutation(a[k],a[k]+3));
	}
	else
	{
		double f[10];
		for (int i=1;i<8;i++)
			for (int j=i+1;j<=8;j++)
				if (dis(a[i],a[j])==0) return;
		for (int i=2;i<=8;i++)
			f[i-2]=dis(a[1],a[i]);
		sort(f,f+7);
		int flag=1;
		if (f[0]<=EPS) return; 
		if (f[0]==f[1] && f[1]==f[2] && f[3]==f[4] && f[4]==f[5] && 2*f[2]==f[3] && f[6]==f[5]+f[0])
			flag=0;
		if (flag==1) return;
		double g[3];
		g[0]=dis(a[1],a[2]);
		flag=0;
		for (int i=3;i<=8;i++)
		{
			g[1]=dis(a[1],a[i]);
			g[2]=dis(a[2],a[i]);
			sort(g,g+3);
			if (g[0]+g[1]!=g[2]&& (g[0]!=g[1] && g[1]!=g[2])) 
			{
				flag=1;
				break;
			}
		}
		if (flag) return;
		puts("YES");
		for (int i=1;i<=8;i++)
			printf("%I64d %I64d %I64d\n",a[i][0],a[i][1],a[i][2]);
		exit(0);
	}
}
int main()
{
	for (int i=1;i<=8;i++)
		scanf("%I64d%I64d%I64d",&a[i][0],&a[i][1],&a[i][2]);
	DFS(1);
	puts("NO");
	return 0;
}
