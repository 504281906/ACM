#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int ff(int a,int b)
{
	if (b==0) return a;
	else return ff(b,a % b);
}
int main()
{
	int n,m,i,t;
	while (~scanf("%d%d",&n,&m))
	{
		t=0;
		for (i=n;i<=sqrt(n*m);i+=n)
		{
			if (ff(m*n/i,i)==n && (n*m % i==0)) 
			{
				//printf("%d %d\n",m*n/i,i);
				t++;
			}
		}
		cout<<t*2<<endl;
	}
	return 0;
}

