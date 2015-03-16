#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int next[1000010];

void getnext(char *s)
{
	int i=0,j=-1;
	int l=strlen(s);
	memset(next,0,sizeof(next));
	next[0]=-1;
	while (i<l)
	{
		if (s[i]==s[j] || j==-1)
		{
			i++;
			j++;
			next[i]=j;
		}
		else j=next[j];
	}
}
char s[1000010];
int main()
{
	int T,i,j,l;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		int ans=0;
		gets(s);
		l=strlen(s);
		getnext(s);
		for (i=0;i<l/3;i++)
		if (s[i]==s[l-1])
		{
			int k=l-1;
			while (next[k]!=i && k!=0)
				k=next[k];
			if (next[k]==i)
			{
				for (j=2*i+1;j<l-i-1;j++)
				{
					int k=j;
					while (next[k]!=i && k!=0)
						k=next[k];
					if (next[k]==i)
						ans=i+1;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
