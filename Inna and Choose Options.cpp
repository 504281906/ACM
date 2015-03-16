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
//#define DEBUG
struct node
{
	int a,b,c;
}f[10];
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int t,i;
	char s[20];
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		memset(f,0,sizeof(f));
		int k=0;
		scanf("%s",&s);
		for (i=0;i<12;i++)
			if (s[i]=='X')
			{
				k+=1;
				f[0].c=1;
				f[0].a=1;
				f[0].b=12;
				break;
			}
		for (i=0;i<6;i++)
		{
			if (s[i]=='X' && s[i+6]=='X')
			{
				k+=1;
				f[1].c=1;
				f[1].a=2;
				f[1].b=6;
				break;
			}
		}
		for (i=0;i<4;i++)
		{
			if(s[i]=='X' && s[i+4]=='X' && s[i+8]=='X')
			{
				k+=1;
				f[2].c=1;
				f[2].a=3;
				f[2].b=4;
				break;
			}
		}
		for (i=0;i<3;i++)
		{
			if(s[i]=='X' && s[i+3]=='X' && s[i+6]=='X' && s[i+9]=='X')
			{
				k+=1;
				f[3].c=1;
				f[3].a=4;
				f[3].b=3;
				break;
			}
		}
		for (i=0;i<2;i++)
		{
			if(s[i]=='X' && s[i+2]=='X' && s[i+4]=='X' && s[i+6]=='X' && s[i+8]=='X' && s[i+10]=='X')
			{
				k+=1;
				f[4].c=1;
				f[4].a=6;
				f[4].b=2;
				break;
			}
		}
		int ff=1;
		for (i=0;i<12;i++)
			if (s[i]=='O')
			{
				ff=0;
				break;
			}
		if (ff) 
		{
			k++;
			f[5].c=1;
			f[5].a=12;
			f[5].b=1;
		}
		printf("%d",k);
		for (i=0;i<=5;i++)
			if (f[i].c)
				printf(" %dx%d",f[i].a,f[i].b);
		printf("\n");
	}
	return 0;
}
