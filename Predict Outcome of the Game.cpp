#include <bits/stdc++.h>
using namespace std;
#define LL __int64
int main()
{
	LL n,m,d1,d2,T;
	scanf("%I64d",&T);
	while (T--)
	{
		scanf("%I64d %I64d %I64d %I64d",&n,&m,&d1,&d2);
	//  cout<<d1<<d2<<endl;
		LL s,d,s1,s2,s3,D1,D2,d3,k=n-m;
		d=m-(d1+d2+d2);
		s=k-2*d1-d2;
		D1=m-(d1+d2);
		s1=k-(max(d1,d2)+abs(d1-d2));
		D2=m-(max(d1,d2)+abs(d1-d2));
		s2=k-(d1+d2);
		d3=m-(2*d1+d2);
		s3=k-d2*2-d1;
		if ((s % 3==0 && s>=0) && (d>=0 && d % 3==0))
			puts("yes");
		else if ((s1 % 3==0 && s1>=0) && (D1>=0 && D1 % 3==0))
			puts("yes");
		else if ((s2 % 3==0 && s2>=0) && (D2>=0 && D2 % 3==0))
			puts("yes");
		else if ((s3 % 3==0 && s3>=0) && (d3>=0 && d3 % 3==0))
			puts("yes");
		else puts("no");
	}
	return 0;
}
