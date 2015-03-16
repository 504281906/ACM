#include <iostream>
#include <cstdio>
using namespace std;
long long KSM(int a,int b)
{
	long long s=1,k=a;
	while (b!=0)
	{
		if (b&1) s*=k;
		k*=k;
		b>>=1;
	}
	return s;
}
int main()
{
	int n,m; 
	while (~scanf("%d%d",&n,&m))
		cout<<KSM(n,m)<<endl;
	return 0;
}
