#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
char f[10]={"algorithm"};
char s[1010];
int main()
{
	int T,i;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		char s[1010];
		gets(s);
		int l=strlen(s);
		int j=0,t=0;
		for (i=0;i<l;i++)
		{
			if (f[j]==s[i])
				j++;
			if (j>8) 
			{
				j=0;	
				t++;
			}
		}
		printf("%d\n",t);
	} 
	return 0;
}
