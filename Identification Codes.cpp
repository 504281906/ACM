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
int t;
int a[100020],p[100000],b[100000];
void sf(long long  n)
{
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	t=0;
	for (int i=2;i<n;i++)
	{
		if (!a[i])
			p[t++]=i;
		for (int j=0;p[j] && (p[j]*i)<=n;j++)
		{
			a[p[j]*i]=1;
			if (i % p[j]==0) break;
		}
	}
} 
int main()
{
	sf(100000);
	int T,i;
	LL n;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%I64d",&n);
		int k=0,ff=0;
		for (i=0;i<t;i++)
		{
			if (n==1) 
			{
				ff=1;
				break;
			}
			if (n <= p[i])
			{
				ff=1;
				b[k]=n;
				k++;
				break;
			}
			else
			{
				if (n % p[i]!=0) continue;
				else
				{
					while (n % p[i]==0)
					{
						LL h=p[i];
						while (n%h==0)
						{
							b[k]=h;
							h*=h;		
						}
						n/=sqrt(h);
						k++;
					}
				}
			}
		}
		if (ff==0) b[k++]=n;
		sort(b,b+k);
		for (i=0;i<k-1;i++)
			printf("%d ",b[i]);
		cout<<b[k-1]<<endl;
	}
	return 0;
}
