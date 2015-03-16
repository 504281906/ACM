#include <iostream>
#include <cstdio>
using namespace std;
#define ll __int64
int main()
{
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++)
	{
		ll x1=0,y1=0,x,y,n;
		scanf("%I64d",&n);
		while (n--)
		{
			scanf("%I64d%I64d",&x,&y);
			while (x>1 && y>1)
			{
				x>>=1;y>>=1;
				x1++;y1++;
			}
			if (x==1) y1+=y-1;
			else x1+=x-1;
		}
		if (x1>y1) printf("Case %d: Alice\n",c);
		else printf("Case %d: Bob\n",c);
	}
	return 0;
}
