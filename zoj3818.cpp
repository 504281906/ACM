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
#include <ctime>
#define LL __int64
#define eps 1e-8
using namespace std;
char c[110],s[110];
int main()
{
	int T,i,j,h;
	scanf("%d",&T);
	while (T--)
	{
		int gg=0;
		memset(c,0,sizeof(c));
		memset(s,0,sizeof(s));
		scanf("%s",&c);
		int l=strlen(c);
		int k=1;
		for (i=0;i<l;i++)
			if ((c[i]>='A' && c[i]<='Z') || (c[i]>='a' && c[i]<='z'))
				s[k++]=c[i];
		s[k]='\0';
		k--;
		l=k;
		/*for (i=1;i<=l;i++)
			printf("%c",s[i]);*/
		for (i=1;i<=l-2;i++)
			for (j=1;j<=l-3*i;j++)
			{
				int flag=1;
				int ff=1;
					if (i==j)
					{
						ff=0;
						for (h=1;h<=i;h++)
							if (s[h]!=s[h+i])
							{
								ff=1;
								break;
							}
					}
				if (!ff) continue;
				k=i+j;
					for (h=k+1;h<=2*k;h++)
						if (s[h-k]!=s[h])
						{
							flag=0;
							break;
						}
					if (!flag) continue;
				if (i*3+j*2==l)
				{
					for (h=2*k+1;h<=l;h++)
						if (s[h-2*k]!=s[h])
						{
							flag=0;
							break;
						}
				}
				else
				{
					int qq=l-3*k; //qq : length(c)
					if (qq<=0) break;
					if (qq==i)
					{
						ff=0;
						for (h=1;h<=i;h++)
							if (s[h]!=s[h+2*k])
							{
								ff=1;
								break;
							}
					}
					if (!ff)
					{
						flag=0;
						break;
					}
					if (qq==j)
					{
						ff=0;
						for (h=1+i;h<=i+j;h++)
							if (s[h]!=s[h+2*k])
							{
								ff=1;
								break;
							}
					}
					if (!ff)
					{
						flag=0;
						break;
					}
					for (h=2*k+qq+1;h<=l;h++)
						if (s[h]!=s[h-2*k-qq])
						{
							flag=0;
							break;
						}
				}
				if (flag) 
				{
					gg=1;
					break;
				}
			}
			if (gg) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
	}
	return 0;
}
