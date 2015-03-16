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
#define eps 1e-8
using namespace std;
int i,j,n,m;
int a[10010];
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		for (i=1;i<=m;i++)
			scanf("%d",&a[i]);
		a[m+1]=n+a[1];
		int k=n/m;
		int ok=0;
		for (i=a[1];i<a[2];i++)
		{
			int flag=1,pos=i;
			for (j=2;j<=m+1;j++)
			{
				if (pos<a[j] && pos+k>=a[j])
					pos+=k;
				else
				{
					flag=0;
					break;
				}
			}
			if (flag)
			{
				ok=1;
				break;
			}
		}
		if (ok) cout<<"S"<<endl;
		else cout<<"N"<<endl;
	}
	return 0;
}
