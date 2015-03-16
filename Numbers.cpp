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
#define DeBug
struct Mx
{
	int a[3][3];
}f,k;
void Init()
{
	k.a[1][1]=1;
	k.a[2][1]=0;
	k.a[1][2]=0;
	k.a[2][2]=1;
}
Mx mul(Mx x,Mx y)
{
	Mx z;
	int i,j,l;
	for (i=1;i<=2;i++)
		for (j=1;j<=2;j++)
		{
			z.a[i][j]=0;
			for (l=1;l<=2;l++)
				z.a[i][j]=(z.a[i][j]+x.a[i][l]*y.a[l][j]) % 1000;
		}
	return z;
}
Mx ksm(Mx f,int n)
{
	if (n==1) return f;
	if (n % 2==0)
	{
		Mx k1=ksm(f,n/2);
		return mul(k1,k1);
	}
	else 
		return mul(f,ksm(f,n-1));
}
int main()
{
#ifdef DeBug
	freopen("C-large-practice.in","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T,n;
	scanf("%d",&T);
	f.a[1][1]=3;f.a[1][2]=5;
	f.a[2][1]=1;f.a[2][2]=3;
	for (int cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		Init();
		Mx ans=ksm(f,n);
		printf("#Case %d: %03d\n",cas,(2*ans.a[1][1]+999) % 1000);	
	}
	return 0;
}
