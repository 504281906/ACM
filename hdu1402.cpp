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
#define LL __int64
#define M 10000000000
using namespace std;
LL a[5100],b[5100],c[110000];
char s1[500010],s2[500010];
void MUL()
{
	int t,i,j;
	memset(c,0,sizeof(c));
	for (i=a[0];i>0;i--)
	{
		t=a[0]-i+1;
		for (j=b[0];j>0;j--)
		{
			c[t+b[0]-j+1]+=a[i]*b[j] / M;
			c[t+b[0]-j]+=a[i]*b[j]%M;
		}
		if (c[t+1])
			c[0]=t+1;
		else c[0]=t;
	}
}
int main()
{
	while (gets(s1))
	{
		gets(s2);
		strrev(s1);
		strrev(s2);
		int l1=strlen(s1)-1;
		int l2=strlen(s2)-1;
		memset(a,0,sizeof(0));
		memset(b,0,sizeof(0));
		while(l1>=0)
		{
			LL k=0,s=0;
			while (k<10 && l1>=0)
			{
				s=s*10+s1[l1]-'0';
				k++;
				l1--;
			}
			a[0]++;
			a[a[0]]=s;
		}
		while(l2>=0)
		{
			int k=0,s=0;
			while (k<10 && l2>=0)
			{
				s=s*10+s2[l2]-'0';
				k++;
				l2--;
			}
			b[0]++;
			b[b[0]]=s;
		}
		MUL();
		printf("%I64d",c[c[0]]);
		for (int i=c[0]-1;i>1;i--)
			printf("%010I64d",c[i]);
		printf("%I64d\n",c[1]);
		//cout<<endl;
	}
	return 0;
}
