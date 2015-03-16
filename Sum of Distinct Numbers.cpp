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
int main()
{
	int i,n,j,T;
	memset(f,0,sizeof(f));
	f[1][0]=1;
	for (i=2;i<=2010;i++)
	{
		f[i][0]=1;
		for (j=1;j<=(i-1)/2;j++)
		{
			f[i][j]=(f[i][j]+f[i-j][0]-f[i-j][j])%M;
			f[i][0]=(f[i][0]+f[i][j])%M;
		}
	}
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		cout<<n<<endl;
		printf("%d\n",f[n][0]);
	}
	return 0;
}
