#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int f[3010],t=0,i,j,n,T;
int main()
{
	set<int> st;
	for (i=1;i<1010;i++)
		f[t++]=i*i*i;
	for (i=0;i<t;i++)
		for (j=1;j<t;j++)
			st.insert(f[i]+f[j]);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int k=st.count(n);
		if (k) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
