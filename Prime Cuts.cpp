#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int f[1010],k[1010],h[1010],i,j,n,c;
int main()
{
	memset(f,0,sizeof(f));
	memset(k,0,sizeof(k));
	memset(h,0,sizeof(h));
	for (i=2;i<=1000;i++)
		if (f[i]==0)
			for (j=i*2;j<=1000;j+=i)
				f[j]=1;
	int t=0;
	for (i=1;i<=1000;i++)
		if (f[i]==0) 
		{
			k[i]=k[i-1]+1;
			h[++t]=i;
		}
			else k[i]=k[i-1];
	while (~scanf("%d%d",&n,&c))
	{
		cout << n << " " << c << ":";
		if (k[n] % 2 ==0)
		{
			t=max(k[n]/2-c+1,1);
			int t1=min(k[n]/2+c,k[n]);
			for (i=t;i<=t1;i++)
				printf(" %d",h[i]);		
		}
		else 
		{
			t=max((k[n]+1)/2-c+1,1);
			int t1=min(k[n]/2+c,k[n]);
			for (i=t;i<=t1;i++)
				printf(" %d",h[i]);
		}
		cout<<endl<<endl;
	}
	return 0;
}

