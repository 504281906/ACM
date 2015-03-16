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
bool pd(char a[100],char b[100])
{
	int l=strlen(a);
	for (int i=0;i<l;i++)
		if (a[i]==b[i]) continue;
		else return a[i]>b[i];
}
int main()
{
	char ss[1100][100];
	char s[100];
	unsigned long long k;
	int T,i,n,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%d",&k,&n);
		for (i=0;i<n;i++)
			s[i]='0';
		s[n]='\0';
		j=0;
		while (k)
		{
			i=k%2;
			k/=2;
			s[j++]='0'+i;
		}
		j--;
		int m=n/2;
		if (j>=n) 
		{
		for (i=0;i<=m-1;i++)
		{
			char c=s[i];
			s[i]=s[n-i];
			s[n-i]=c;
		}
		s[n]='\0';
		}
		else 
		for (i=0;i<n;i++)
		{
			char c=s[i];
			s[i]=s[n-i-1];
			s[n-i-1]=c;
		}
		for (i=0;i<n;i++)
		{
			int k=0;
			for (j=i;j<n;j++)			
				ss[i][k++]=s[j];
			for (j=0;j<i;j++)
				ss[i][k++]=s[j];
			//printf("%s\n",ss[i]);
		}
		//sort(ss,ss+n,cmp);
		//qsort(ss,n,sizeof(ss[0]),cmp);
		char t[100];
		for (i=0;i<n;i++)
			for (j=i+1;j<n;j++)
				if (pd(ss[i],ss[j]))
				{
					strcpy(t,ss[i]);
					strcpy(ss[i],ss[j]);
					strcpy(ss[j],t);
				}
		/*for (i=0;i<n;i++)
			printf("%s\n",ss[i]);
		cout<<endl;*/
		for (i=0;i<n;i++)
			printf("%c",ss[i][n-1]);
		cout<<endl;
	}
	return 0;
}
