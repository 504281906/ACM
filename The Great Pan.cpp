#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
#define LL __int64
char s[1005][100000];
int l[1005];
int main()
{
	int n,i,f;
	while (~scanf("%d",&n))
	{
		f=0;
		getchar();
		LL L=0;
		for (i=1;i<=n;i++)
		{
			gets(s[i]);
			l[i]=strlen(s[i]);
			L+=l[i];
		}
		int j=0,a=0,b=0,t=0,pos=0,k; //Á½¸ö×´Ì¬ 
		i=1;
		LL ans=1;
		while (pos<L)
		{
			if (a==0 && b==0)
			{
				if (s[i][j]=='{') {a=1;k=1;}
				if (s[i][j]=='$') b=1;
				j++;
				pos++;
			}
			else if (a==1)
			{
				if (s[i][j]=='|') k++;
				if (s[i][j]=='}')
				{
					ans*=k;
					a=0;
				}
				j++;pos++;
			}
			else if (b==1)
			{
				if (s[i][j]=='$')
				{
					b=0;
					j++;
					pos++;
					if (j==l[i])
					{
						i++;
						j=0;
					}
					continue;
				}
				k=0;
				while (s[i][j]==' ')
				{
					k++;
					j++;
					pos++;
					if (j==l[i])
					{
						i++;
						j=0;
					}
				}
				if (k!=0)
					ans*=(k+1);
				else
				{
					j++;pos++;
				}
			}
			if (j==l[i])
			{
				i++;
				j=0;
			}
			if (ans>100000)
			{
				f=1;
				break;
			}
		}
		if (f==1) puts("doge");
		else cout<<ans<<endl;
	}
	return 0;
}
