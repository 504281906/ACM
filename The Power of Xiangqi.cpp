#include <stdio.h>
int a[10]={16,7,8,1,1,2,3}; 
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--)
	{
		char c[2];
		int s1=0,s2=0;
		int f=0,f1=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%s",&c);
			if (c[0]=='B') f=1;
			if (c[0]=='C') f1=1;
			s1+=a[c[0]-'A'];
		}
		if (s1>1 && (f+f1<2)) s1--;
		f=0;
		f1=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%s",&c);
			if (c[0]=='B') f=1;
			if (c[0]=='C') f1=1;
			s2+=a[c[0]-'A'];
		}
		if (s2>1 && (f+f1<2)) s2--;
		if (s1>s2) printf("red\n");
		else if (s1<s2) printf("black\n");
		else printf("tie\n");
	}
	return 0;
}
