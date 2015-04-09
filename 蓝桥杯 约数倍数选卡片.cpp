#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int t1,h,ff,num;
int a[100100],b[100100],vis[100100];
int pd(int s)
{
	int kk=0;
	for (int i=0;i<t1;i++)
		if(!vis[i] && (s % a[i]==0 || a[i] % s==0))
		{
			kk++;
			num=(num+1) % 2;
			vis[i]=1;
			if (pd(a[i])){	
				vis[i]=0;
				num=(num+1)%2;
				return 0;
			}
			vis[i]=0;
			num=(num+1) % 2;
		}
	if (!kk || !num) return 1;
}
int cmp(int a,int b)
{
	return a<b;
}
int main()
{
	char s[10010];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	gets(s);
	int l=strlen(s),i=0;
	t1=0;
	while(i<l)
	{
		int k=0;
		while (s[i]!=' ' && i<l)
		{
			k=k*10+s[i]-'0';
			i++;
		}
		a[t1++]=k;
		i++;
	}
	gets(s);
	l=strlen(s);
	int t=0;
	i=0;
	while (i<l)
	{
		int k=0;
		while (s[i]!=' ' && i<l)
		{
			k=k*10+s[i]-'0';
			i++;
		}
		b[t++]=k;
		i++;
	}
	sort(b,b+t,cmp);
	int f=0;
	for (i=0;i<t;i++)
	{
		memset(vis,0,sizeof(vis));
		for (int j=0;j<t1;j++)
			if (b[i]==a[j])
			{
				vis[j]=1;
				break;
			}
		num=0;
		ff=0;
		if (pd(b[i]))
		{
			printf("%d\n",b[i]);
			f=1;
			break;
		}
	}
	if (!f) printf("-1\n");
	return 0;
}
