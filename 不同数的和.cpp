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
#define eps 1e-8
#define M 100999
using namespace std;
int f[2010][2010];
int g[2010][2010];
int main()
{
	int i,n,j,T;
//	freopen("out1.txt","w",stdout);
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	f[1][0]=1;
	for (i=2;i<=2010;i++)
	{
		f[i][0]=1;
		for (j=1;j<=(i-1)/2;j++)
		{
			LL s=f[i-j][0];
			g[i][0]=0;
			int jj=j;
			while (g[i-j][jj]==0 && g[i-j][jj+1]==0 && jj>0) jj--;
			s=(s+M-g[i-j][jj])%M;
			f[i][j]=s;
			g[i][j]=(g[i][j-1]%M+s%M)%M;
			f[i][0]=(f[i][0]+s)%M;
		}
	}
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		//cout<<n<<endl;
		printf("%d\n",f[n][0]);
	}
	return 0;
}
