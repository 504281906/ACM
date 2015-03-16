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
#define M 1000000007
using namespace std;
LL ksm(int a,int b)
{
	LL s=1,k=a;
	while (b!=0)
	{
		if (b&1) s=s*k%M;
		k=k*k%M;
		b>>=1;
	}
	return s;
}
LL go(int a,int b)
{
	LL s=a;
	for (int i=1;i<=b;i++)
		s=(s*2+1)%M;
	return s;
}
LL f[110][110];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout); 
	memset(f,0,sizeof(f));
	for (int i=1;i<=101;i++)
		f[i][0]=1;
	for (int i=1;i<=101;i++)
		for (int j=1;j<=101;j++)
		{
			if (i<=j) f[i][j]=ksm(2,i-1);
			else f[i][j]=(go(i-j,j-1)+1)%M;
		}
	int a,b;
	while (~scanf("%d%d",&a,&b) && (a+b))
	{
		LL ans=0;
		for (int i=1;i<a;i++)
			ans=(ans+f[i][b])%M;
		for (int i=1;i<a-1;i++)
			ans=(ans+f[i][b-1])%M;
		printf("%I64d\n",(ans+1)%M);
	}
	return 0;
}
