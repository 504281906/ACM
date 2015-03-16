#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
char f[500][110];
void ff(char *a,char *b,char *c)
{
	int l=strlen(a);
	for (int i=0;i<l;i++)
	{
		c[i]+=a[i]+b[i]-'0';
		if (c[i]<'0')
			c[i]+='0';
		if (c[i]>'9')
		{
			c[i]-=10;
			c[i+1]++;
		}
	}
	if (c[l]==1) c[l]+='0';
	return;
}
int ccmp(char *a,char *b)
{
	int i,l1=strlen(a);
	int l2=strlen(b);
	if (l1>l2) return 1;
	if (l1<l2) return -1;
	for (i=0;i<l1;i++)
	{
		if (a[i]<b[l1-i-1]) return -1;
		if (a[i]>b[l1-i-1]) return 1;
	}
	return 0;
}
int main()
{
	memset(f,0,sizeof(f));
	f[1][0]=1+'0';
	f[2][0]=2+'0';
	int i;
	for (i=3;i<=500;i++)
		ff(f[i-1],f[i-2],f[i]);
	char n[110],m[110];
	while (~scanf("%s %s",&n,&m))
	{
		int k=0,k1=0;
		if (0==(strcmp(n,"0")+strcmp(m,"0"))) break;
		for (i=1;i<500;i++)
			if (ccmp(n,f[i])<=0)
			{
				k=i;
				break;
			}
		for (i=1;i<500;i++)
			if (ccmp(m,f[i])<0)
			{
				k1=i;
				break;
			}
		cout<<k1-k<<endl;
	}
	return 0;
}
