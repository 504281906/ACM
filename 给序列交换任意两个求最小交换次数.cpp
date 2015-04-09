#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int a[500010];
int main()
{
	int n,i;
	while (~scanf("%d",&n) && n)
	{
		map<int ,int >m1;
		map<int ,int >m2;
		for (i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			m1[a[i]]=i;
			m2[i]=a[i];
		}
		int ans=0;
		sort(a,a+n);
		for (i=0;i<n;i++)
		{
			int pos=m1[a[0]];
			if( pos!=i )
			{
				m2[pos]=m2[i];
				m1[m2[i]]=m1[a[0]];
				m1[a[0]]=i;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

