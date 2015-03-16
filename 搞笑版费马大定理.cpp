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
#include <ctime>
#define LL __int64
#define EPS 1e-8
using namespace std;
int main()
{
	int cas=1,x,y,i,j;
	while (~scanf("%d%d",&x,&y))
	{
		printf("Case %d: ",cas++);
		if (x>=1000)
		{
			printf("0\n");
			continue;
		}
		else
		{
			int ans=0;
			int b=min(1000,y);
			for (i=x;i<=b;i++)
				for (j=i+1;j<=b;j++)
				{
					if (j*j*j>y*10+3) break;
					int s=i*i*i+j*j*j;
					if (s%10==3 && s/10<=y && s/10!=i && s/10!=j)
					{
					//	printf("%d %d\n",i,j);
						ans++;
						if (i!=j) ans++;
					}
				}
			printf("%d\n",ans);
		}	
	}
	return 0;
}
