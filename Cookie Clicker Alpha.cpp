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
int main()
{
	int T,cas,i;
	double c,f,x;
	freopen("outpu.txt","w",stdout);
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		double ans=x/2.0;
		double k=2.0;
		double s=0;
		for (i=1;i<=100000;i++)
		{
			s+=c/k;
			k+=f;
			double q=x/k+s;
		//	cout<<q<<endl;
			if (q>ans) break;
			else ans=q;
		}
		printf("Case #%d: %.7lf\n",cas,ans);
	}
	return 0;
}
