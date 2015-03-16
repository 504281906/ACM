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
int sg[60][60000];
int dp(int a,int b)
{
	if (sg[a][b]!=-1) 
		return sg[a][b];
	if (b==1) 
		return sg[a][b]=dp(a+1,0);
	sg[a][b]=0;
	if (a>0&&!dp(a-1,b))
		sg[a][b]=1;
	if (b>0&&!dp(a,b-1))
		sg[a][b]=1;
	if (a>0&&b&&!dp(a-1,b+1))
		sg[a][b]=1;
	if (a>1&&((b==0&&!dp(a-2,b+2))||(b&&!dp(a-2,b+3))))
		sg[a][b]=1;
	return sg[a][b];
}
int main()
{
	int T,n,i,x,y,z;
	memset(sg,-1,sizeof(sg));
	scanf("%d",&T);
	for (int c=1;c<=T;c++)
	{	
		y=0;z=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if (x==1)
				y++;
			else z+=x+1;
		}
		if (z) z--;
		dp(y,z);
		printf("Case #%d: ",c);
		if (sg[y][z]) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
