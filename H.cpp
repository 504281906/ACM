#include <cstdio>
#include <cstring>
char s[100010];
int a[100010];
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		gets(s);
		int l=strlen(s);
		for (int i=1;i<=l;i++)
		a[i]=s[l-i]-'0';
		while (1)
		{
			a[1]++;
			int n=1;
			while (a[n]>=10)
			{
				if (n==l)
				{
					l++;
					a[l]=0;
				}
				a[n]-=10;
				a[n+1]++;
				n++;
			}
			int s=0;
			for (int i=1;i<=l;i++)
			s+=a[i];
			if (s % 10==0) break; 
		}
		for (int i=l;i>=1;i--)
		printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
