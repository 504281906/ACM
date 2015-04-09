#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const int N=200005;
int e[N],f[N];
void init()
{
	int i,j,k;
	memset(f,0,sizeof(f));
	for (i=1;i<N;i++)
		e[i]=i;
	for (i=2;i<N;i++)
	{
		if (e[i]==i)
		for (j=i;j<N;j+=i)
			e[j]=e[j]/i*(i-1);
	}
	for (i=2;i<N;i++)
		f[i]=e[i];
	for (i=2;i<sqrt(N);i++)
	{
		f[i*i]+=e[i]*i;
		for (k=i+1;k*i<N;k++)
			f[k*i]+=e[i]*k+e[k]*i;
	}
	for (i=2;i<N;i++)
		f[i]+=f[i-1];
}
int main()
{
	int n;
	init();
	while (~scanf("%d",&n))
		cout<<f[n]<<endl;
	return 0;
}
