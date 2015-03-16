#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	while (~scanf("%d",&n))
	{
		__int64 ans=0;
		for (i=1;i<=n;i++)
		{
			__int64 a,b;
			scanf("%I64d%I64d",&a,&b);
			if (a % 2 != 0)
			{
				ans^=a;
				a++;
				b--;
			}
			while (b % 4 !=0)
			{
				ans^=(a+b-1);
				b--;
			}
		}
		//cout<<ans<<endl;
		if (ans) printf("tolik\n");
		else printf("bolik\n");
	}
	return 0;
}
