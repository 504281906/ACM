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
char s[1000010];
int l,a,b,f,i,c,k;
int main()
{
	while (gets(s))
	{
		int l=strlen(s);
		if (l % 2 || s[l-1]=='(')
		{
			puts("None");
			continue;
		}
		a=0,b=0,f=1,c=0,k=0;
		for (i=0;i<l;i++)
		{
			if (s[i]=='(')
			{
				if (b>a)
				{
					c+=(b-a);
					b=a;
					if (a!=0 && b!=1)
						k=1;
				}
				a++;
				continue;
			}
			if (s[i]==')')
			{
				if (a==0 && b==0 && c==0)
				{
					puts("None");
					f=0;
					break;	
				}
				else if (a!=0) 
				{
					if (b>a) k=1;
					a--;
					if (b>a)
					{
						c+=(b-a);
						b=a;
					}
				}
				else if (c!=0) {if (c>1) k=1;c--;}
				else if (b!=0) {if (b>1) k=1;b--;}
				continue;
			}
			if (s[i]=='?')
			{
				if (a>0) b++;
				else c++;
				continue;
			}
		}
		if (f==0) continue;
		if (a>b) puts("None");
		else
		{
			if ((b-a) %2!=c%2) puts("None");
			else
			{
				if (b-a>0 && a) 
				{
					puts("Many");
					continue;
				}
				b-=a;
				if (k==1)
				{
					if (fabs(c-b)>=2)
						puts("Many");
					else puts("Unique");
				}
				else 
				{
					if (fabs(c-b)>2)
						puts("Many");
					else puts("Unique");
				}
			}
			/*if (b % 2==1) puts("None");
			else if (b==0) puts("Unique");
			else puts("Many");*/
		}
	}
	return 0;
}
