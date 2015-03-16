#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[100010],b[100010];
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		long long s1=0,s2=0;
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			s1+=a[i];
			s2+=b[i];
		}
		if (s1<s2)
		{
			printf("-1\n");
			continue;
		}
		for (i=0;i<n;i++)
		{
			if (a[i]>=b[i])
			{
				int j=(i+1) % n;
				int t=1;
				int s=a[i]-b[i];
				int f=0;
				while (t % n)
				{
					s+=a[j]-b[j];
					if (s<0)
					{
						f=1;
						break;
					}
					j=(j+1)%n;
					t++;
				}
				if (f==0) 
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
