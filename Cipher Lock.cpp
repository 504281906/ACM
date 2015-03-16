#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char s[110][10010];
int main()
{
	int t=0,n,m,i,j;
	while (~scanf("%d%d",&n,&m))
	{
		getchar();
		printf("Case #%d:\n",++t);
		for (i=0;i<n;i++)
			gets(s[i]);
		int max=0x6fffffff;
		int ff=1;
		for (i=0;i<m;i++)
		{
			int k=0;
			for (j=0;j<n;j++)
			{
				int f=1,l,r,a=0;
				while (a<=(m/2+1))
				{
					l=i-a;
					r=i+a;
					if (l<0) l=m+l;
					if (r>=m) r=r-m;
					if (s[j][l]=='1' || s[j][r]=='1')
					{
						f=0;
						break;
					}
					a++;
				}
				if (f==0) k+=a;
				else
				{
					ff=0;
					break;
				}
			}
			if (ff)
				if (max>k) max=k;
			else break;
		}
		if (ff) printf("%d\n",max);
		else printf("Give Me A BOOM please\n");
	}
	return 0;
}
