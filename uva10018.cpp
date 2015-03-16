#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[100];
int ff(int a[100],int l)
{
	int i;
	for (i=0;i<l/2;i++)
		if (a[i]!=a[l-i-1]) return 0;
	return 1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		char s[100];
		scanf("%s",&s);
		int i,t=0,f=1,l=strlen(s);
		for (i=0;i<l;i++)
			a[i]=s[l-i-1]-'0';
		if (ff(a,l)) f=0;
		while (f)
		{
			int k=0;
			int b[20];
			for (i=0;i<l;i++)
				b[i]=a[l-i-1];
			for (i=0;i<l;i++)
			{
				a[i]=a[i]+b[i]+k;
				k=a[i] / 10;
				a[i]%=10;
			}
			if (k==1) 
			{
				l++;
				a[l-1]=1;
			}
			if (ff(a,l)) f=0;
			t++;
		}
		cout<<t<<" ";
		for (i=l-1;i>=0;i--)
		cout<<a[i];
		printf("\n");
	}
	return 0;
}
