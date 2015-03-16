#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/*void getnext()
{
	int l=strlen(s);
	j=-1;
	i=0;
	memset(next,-1,sizeof(next));
	while (i<l)
	{
		if (s[i]==s[j] || j=-1)
		{
			i++;
			j++;
			next[i]=j;
		}
		else j=next[j];
	}
}*/
int main()
{
	char s[1010],s1[1010];
	int i;
	while (~scanf("%s %s",&s,&s1) && s[0]!='#')
	{
		int t=0;
		//getnext();
		int l=strlen(s);
		int l1=strlen(s1);
		for (i=0;i<l;)
		{
			if (s[i]==s1[0])
			{
				int flag=0;
				for (int j=1;j<l1;j++)
					if (s[i+j]!=s1[j]) 
					{
						flag=1;
						break;
					}
				if (flag==0) 
				{
					t++;
					i+=l1;
				}
				else i++;
			}
			else i++;
		}
		printf("%d\n",t);
	}
	return 0;
}

