#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[2010];
char s[2010];
int main()
{
	int T,i,l;
	scanf("%d",&T);
	while (T--)
	{
		getchar();
		scanf("%s",&s);
		l=strlen(s);
		if ((s[l-1]-'0') % 2==1)
		{
			int k=0;
			for (i=0;i<l;i++)
			{
				a[i]=(k*10+s[i]-'0')/2;
				k=(k*10+s[i]-'0')%2;
			}
			k=0;
			while (a[k++]==0);
			for (i=k-1;i<l;i++)
				printf("%d",a[i]);
			printf("\n"); 
		}
		else 
		{
			int k=0;
			for (i=0;i<l;i++)
			{
				a[i]=(k*10+s[i]-'0')/2;
				k=(k*10+s[i]-'0')%2;
			}
			k=0;
			while (a[k++]==0);
			int f=2;
			if (a[l-1]%2==0) f=1;
				if (a[l-1]-f<0)
				{
				int t=l-1;
				a[t]=a[t]+10-f;
				a[--t]--;
				while (a[t]<0)
				{
					a[t]+=10;
					a[--t]--;
				}
				}
				else
				a[l-1]-=f;
			k--;
			while (a[k++]==0);
			for (i=k-1;i<l;i++)
				printf("%d",a[i]);
			printf("\n"); 
		}
		if (T) printf("\n");
	}
	return 0;
}
