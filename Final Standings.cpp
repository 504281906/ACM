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
#define LL __int64
#define EPS 1e-8
using namespace std;
int a[10010];
int main()
{
	int n,p,k,d,i;
	//freopen("out.txt","w",stdout);
	while (~scanf("%d%d%d%d",&n,&p,&k,&d))
	{
		//int max=(2*k-d+1)*d/2+(k-d)*k;
		int min=(d-1)*d/2;
		if (p<min)
		{
			puts("Wrong information");
			continue;
		}
		int i=0;int ans;
		if (d==1)
		{
			ans=p/k;
			if ((p-ans*k>0 && (n-k)==0) || ((n-k)!=0 && (p-ans*k)/(n-k)>ans))
			{
				puts("Wrong information");continue;
			}
			else
			{
				for (i=1;i<=k;i++)
					cout<<ans<<endl;
				int s=p-ans*k;
				for (i=1;i<=n-k;i++)
				{
					if (s>ans)
					{
						cout<<ans<<endl;
						s-=ans;
					}
					else 
					{
						cout<<s<<endl;
						s-=s;
					}
				}
			}
		}
		else
		{
			for (i=0;i<d-1;i++)
			{
				a[i]=i;
				p-=i;
			}
			if (p>0) cout<<p<<endl;
			for (i=d-2;i>=0;i--)
				cout<<a[i]<<endl;
			for (i=1;i<=n-d;i++)
				cout<<"0"<<endl;
		}
	}
	return 0;
}
