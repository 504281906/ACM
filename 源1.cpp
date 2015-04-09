#include <cstdio>
#include <iostream>
using namespace std;
#define M 1000000007
int f[100000];
int ff()
{
	f[0]=1;
	long long i,j,k,s,t;
	for (i=1;i<=100000;i++)
	{
		j=1;k=1;s=0;t=-1;
		for (;j>0;k++,t*=-1)
		{
			j=i-(3*k*k+k)/2;
			if (j>=0) s-=t*j;
			j=i-(3*k*k-k)/2;
			if (j>=0) s-=t*j;
			s=((s % M)+M)%M;
		}
		f[i]=s;
	}
}
int main()
{
	int T;
	cin>>T;
	ff();
	while (T--)
	{
		int a;
		cin>>a;
		cout<<f[a]<<endl;
	}
	return 0;
}
