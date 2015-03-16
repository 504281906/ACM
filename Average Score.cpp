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
int main()
{
	int T,k,n,m,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		double s1=0,s2=0;
		for (i=1;i<n;i++)
		{
			scanf("%d",&k);
			s1+=k;
		}
		for (i=1;i<=m;i++)
		{
			scanf("%d",&k);
			s2+=k;
		}
		int ans1=floor(s1/(n-1));
		int ans2=ceil(s2/m);
		if (ans1*(n-1)==s1) ans1--;
		if (ans2*m==s2) ans2++;
		cout<<ans2<<" "<<ans1<<endl;
	}
	return 0;
}
