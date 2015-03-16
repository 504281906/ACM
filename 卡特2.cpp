#include <iostream>
#include <cstring>
using namespace std;
long long f[100],i,j;
int main()
{
	memset(f,0,sizeof(f));
	f[1]=1;
	for (i=2;i<=100;i++)
		f[i]=f[i-1]*(4*i-2)/(i+1);
	while (~scanf("%lld",&i))
		cout<<f[i]<<endl;
}
