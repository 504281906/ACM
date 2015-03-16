#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	__int64 T,n,m,x1,y1,x2,y2;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&n,&m,&x1,&y1,&x2,&y2);
		x2=fabs(x1-x2)+1;
		y2=fabs(y1-y2)+1;
		__int64 k=n-x2+1;
		__int64 k1=m-y2+1;
		x1=k;
		y1=k1;
		__int64 s=2*k*k1;
		if (x1>=x2 && y1>=y2)
			s-=(x1-x2+1)*(y1-y2+1);
		s=n*m-s;
		printf("%I64d\n",s);
	}
	return 0;
}
