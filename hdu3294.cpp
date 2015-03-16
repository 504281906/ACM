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
char c,s1[200010],s[400100];
int d[400100];
int main()
{
	while (~scanf("%c %s",&c,&s1))
	{
		getchar();
		int l=strlen(s1);
		int i,j=0;
		for (i=0;i<l;i++)
		{
			s[j++]='#';
			s[j++]=s1[i];
		}
		s[j++]='#';
		s[j++]='\0';
		l=strlen(s);
		int ans=0,mx=0,id,pos;
		memset(d,0,sizeof(d));
		for (i=0;i<l;i++)
		{
			if (mx>i)
				d[i]=min(d[2*id-i],mx-i);
			else 
				d[i]=1;
			while (i-d[i]>=0 && i+d[i]<l && s[i-d[i]]==s[i+d[i]]) d[i]++;
			if (d[i]+i>mx)
			{
				mx=d[i]+i;
				id=i;
			}
			if (d[i]>ans)
			{
				ans=d[i];
				pos=id;
			}
		}
		ans--;
		int k=c-'a';
		if (ans<2) cout<<"No solution!"<<endl;
		else 
		{
		//	if (ans % 2==0)
				printf("%d %d\n",(pos-ans)/2,(pos+ans-2)/2);
		//	else
		//		printf("%d %d\n",)
			for (i=pos-ans;i<pos+ans+1;i++)
			{
				if (s[i]=='#') continue;
				int f=s[i]-'a'-k;
				if (f<0) f=97+26+f;
				else f+=97;  
				printf("%c",f);
			}
			cout<<endl;
		}
	}
	return 0;
}
