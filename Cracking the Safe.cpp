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
#define ling 0.0000000001
double go(double a,double b,int c)
{
	if (c==0) return a+b;
	else if (c==1) return a-b;
	else if (c==2) return a*b;
	//else if (b==0) return 10000;
	else return a/b;
}
double a[5],b[5];
int T,i,t,j,k;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		for (i=0;i<4;i++)
			scanf("%lf",&a[i]);
		sort(a,a+4);
		int f=0;
		do
		{
			double ans=0;
			for (i=0;i<4;i++)
			{
				for (j=0;j<4;j++)
				{
					for (k=0;k<4;k++)
					{	
						memset(b,0,sizeof(b));
						b[1]=go(a[0],a[1],i);	
						b[2]=go(b[1],a[2],j);
						ans=go(b[2],a[3],k);
						if (fabs(ans-24)<=ling)
						{
							puts("YES");
							f=1;
							if (f)break;
						}
						
						memset(b,0,sizeof(b));
						b[1]=go(a[0],a[1],i);	
						b[3]=go(a[2],a[3],k);
						ans=go(b[1],b[3],j);
						if (fabs(ans-24)<=ling)
						{
							puts("YES");
							f=1;
							if (f)break;
						}
						
						memset(b,0,sizeof(b));
						b[2]=go(a[1],a[2],j);
						b[1]=go(a[0],b[2],i);	
						ans=go(b[1],a[3],k);
						if (fabs(ans-24)<=ling)
						{
							puts("YES");
							f=1;
							if (f)break;
						}
						
						memset(b,0,sizeof(b));
						b[2]=go(a[1],a[2],j);
						b[3]=go(b[2],a[3],k);	
						ans=go(a[0],b[3],i);
						if (fabs(ans-24)<=ling)
						{
							puts("YES");
							f=1;
							if (f)break;
						}
						
						memset(b,0,sizeof(b));
						b[3]=go(a[2],a[3],k);	
						b[2]=go(a[1],b[3],j);
						ans=go(a[0],b[2],i);
						if (fabs(ans-24)<=ling)
						{
							puts("YES");
							f=1;
							if (f)break;
						}
					}
					if (f)break;
				}
				if (f)break;
			}
			if (f)break;
		}while (next_permutation(a,a+4));
		if (f==0) puts("NO");
		/*else 
		{
			cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
			cout<<i<<j<<k<<endl;
		}*/
	}
	return 0;
}
