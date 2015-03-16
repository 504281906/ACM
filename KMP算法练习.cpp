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
//#define DEBUG
int next[10010];
char s[10010],s1[1000010];
void find_next(char s[10010])
{
	int l=strlen(s);
	int i=0,j=-1;
	while (i<l)
	{
		if (j==-1 || s[i]==s[j]) next[++i]=++j;
		else j=next[j]; 
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		gets(s);   //模式串	 
		gets(s1);   //原串 
		memset(next,-1,sizeof(next));
		find_next(s); //求模式串的next 
	//	for (int i=0;i<strlen(s);i++)
	//		cout<<next[i]<<" ";
		int l=strlen(s1);
		int l1=strlen(s);
		int i=0,j=0,ans=0;
		while (i<l)
		{
			if (j==-1) 
			{
				i++;j++;
			}
			if (s1[i]==s[j])
			{
				if (j==l1-1)
				{
					ans++;
					j=next[j];
					//if (j)
				//	i++;
				}
				else
				{
					i++;j++;
				}	
			}
			else 
				j=next[j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
