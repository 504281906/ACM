#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;
int main()
{
	int n,m;
	map<string,int> a;
	while (~scanf("%d%d",&n,&m))
	{
		char s[100];
		a.clear();
		for (int i = 0; i < n; i++)  
        {  
            scanf("%s", s);  
            a[s] = 1;  
        } 
		while (m--)
		{
			scanf("%s",s);
			if (a[s]==1)
				printf("NO\n");
			else 
			{
				a[s]=1;
				printf("YES\n");
			}
		}
	}
	return 0;
}
