#include <stdio.h>
#include <string.h>
int main()
{
	int a[1010],b[1010],n,m,k,p,x,y;
	char s[10],s1[10];
	while (~scanf("%d%d%d",&n,&m,&k) && (n+m+k))
	{
		__int64 f;
		f=n*m*k;
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		scanf("%d",&p);
		while (p--)
		{
			scanf("%s%d%s%d",&s,&x,&s1,&y);
			if (s[0]=='c')
			{
				f-=k;
				f+=a[y];
				b[y]++;
			}
			else 
			{
				f-=n;
				f+=b[x];
				a[x]++;
			}
		}
		printf("%I64d\n",f);
	}
	return 0;
}
