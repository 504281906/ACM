#include <cstdio>
#include <iostream>
#include <cstring> 
using namespace std;
int main()
{
	int i,j,a[10000],n;
	memset(a,0,sizeof(a));
	a[1]=1;
	for (i=2;i<=10000;i++)
	{
		if (!a[i])
		{
			for (j=i;j<=10000;j+=i)
			{
				if (!a[j])
					a[j]=j;
				a[j]=a[j]/i*(i-1);
			}
		}
	}
	while (~scanf("%d",&n))
		cout<<a[n]<<endl;
}
