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
char a[1000010];
char b[1000010];
int s1[30];
int s2[30];
int main()
{
	int T,cas,n,l1,l2,m;
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		getchar();
		gets(a);
		gets(b);
		l1=strlen(a);
		l2=strlen(b);
		int i=0,j;
		m=0;
		while(i<l1)
		{
			int k=0;
			while (a[i]>='0' && a[i]<='9')
			{
				k=k*10+a[i]-'0';
				i++;
			}
			m+=k;
			i++;	 
		}
		//cout<<m<<endl;
		m=m/n;   //m:1ÁÐÓÐm¸ö×ÖÄ¸¡£ 
		int flag=1;
		i=0;j=0;
		int k=0;
		while (k<=n && flag)
		{
			int s=0;
			memset(s1,0,sizeof(s1));
			memset(s2,0,sizeof(s2));
			while (s<m)
			{
				k=0;
				while (a[i]>='0' && a[i]<='9')
				{
					k=k*10+a[i]-'0';
					i++;
				}
				s+=k;
				s1[a[i]-'a']+=k;
				i++;
			}
			s=0;
			while (s<m)
			{
				k=0;
				while (b[j]>='0' && b[j]<='9')
				{
					k=k*10+b[j]-'0';
					j++;
				}
				s+=k;
				s2[b[j]-'a']+=k;
				j++;
			}
			for (int h=0;h<26;h++)
				if (s1[h]!=s2[h])
				{
					flag=0;
					break;
				}
		}
		if (flag) printf("Case %d: Yes\n",cas);
		else printf("Case %d: No\n",cas);
	}
	return 0;
}

