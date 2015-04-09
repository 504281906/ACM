#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>

#define ll __int64
using namespace std;
struct node
{
	ll m[2][2];
	
	node operator * (const node &h)
	{
		node now;
		int i,j,k;
		for (i=0;i<2;i++)
			for (j=0;j<2;j++)
			{
				now.m[i][j]=0;
				for (k=0;k<2;k++)
					now.m[i][j]=(now.m[i][j]+m[i][k]*h.m[k][j])%10000;
			}
		return now;
	}
	node pow(int n,const node &w)
	{
		if (n==1) return w;
		node mm=pow(n/2,w);
		if (n % 2)
			return mm*mm*w;
		else 
			return mm*mm;
	}
};
int main()
{
	int n;
	while (~scanf("%d",&n) && n != -1)
	{
		if (n==0) {printf("0\n");continue;}
		if (n==1 || n==2) {printf("1\n");continue;}
		node w;
		w.m[0][0]=w.m[0][1]=w.m[1][0]=1;
		node s=w.pow(n-2,w);
		w.m[0][0]=w.m[1][0]=w.m[0][1]=1;
        w.m[1][1]=0;
        s=s*w;
        printf("%lld\n",s.m[0][0]);
	}
	return 0;
}
