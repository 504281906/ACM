#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define M 1000000007
long long f[100010];
int main()
{
	int i,T,n;
	f[1]=1;f[2]=2;f[3]=3;f[4]=5;f[5]=7;f[6]=11;
	for (i=7;i<=100001;i++)
	f[i]=(f[i-2]*2) % 1000000007;
	scanf("%d",&T);
	while (T--)
	{
		cin>>n;
		cout<<f[n]<<endl;
	}
	return 0;
} 
