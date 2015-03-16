#include <iostream>
#include <cstring>
using namespace std;
int f[100],i,j; 
int main()
{
	memset(f,0,sizeof(f));
	f[0]=1;
	f[1]=1;
	for (i=2;i<=16;i++)
		for (j=0;j<i;j++)
			f[i]+=f[j]*f[i-j-1];
	cout<<f[16]<<endl;
}
