#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
#define LL __int64
int a[20]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int main()
{
	int T,n,m,p,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&p);
		if (n<=2*m)
		{
			if ((p+n) % 2==0 && (p!=n))
				printf("1\n");
			else 
			if (p==n) 
				printf("%d\n",m-(n-1)/2);
			else printf("0\n");
		}
		else if (n==2*m+1)
		{
			if (p&1 && p<2*m)
				printf("1\n");
			else printf("0\n");
		}
		else
		{
			int k=n-2*m,f=0;
			for (i=1;i<=14;i++)
			if (k==a[i])
			{
				printf("0\n");
				f=1;
				break;
			}
			if (f==0)
			for (i=1;i<=14;i++)
				if (k<a[i])
				{
					if (p>2*m+a[i-1] && p<2*m+a[i])
						printf("Thrown\n");
					else 
						printf("0\n");
					break;
				}
		}
	}
	return 0;
}
