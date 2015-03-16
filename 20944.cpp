#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
	int i,n;
	set <string>a,b;
	set <string>::iterator it;
	while (~scanf("%d",&n) && n)
	{
		for (i=1;i<=n;i++)
		{
			char s1[100],s2[100];
			scanf("%s%s",&s1,&s2);
			getchar();
			a.insert(s1);
			b.insert(s2);
		}
		for (it=b.begin();it!=b.end();it++)
		{
			if (find(a.begin(),a.end(),*it)!=a.end())
				a.erase(*find(a.begin(),a.end(),*it));
		}
		if (a.size()==1)
			printf("Yes\n");
		else 
			printf("No\n");
		a.clear();
		b.clear();
	}
	return 0;
}
