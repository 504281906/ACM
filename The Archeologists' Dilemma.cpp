#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int f[10010][30010];
int main()
{
	int i,j;
	f[7][0]=3;f[7][1]=8;f[7][2]=2;f[7][3]=1;
	for (i=8;i<=10001;i++)
	{
		int k=0;
		f[i][0]=f[i-1][0];
		for (j=1;j<=f[i-1][0];j++)
		{
			f[i][j]=(f[i-1][j]*2+k) % 10;
			k=(f[i-1][j]*2)/10;
		}
		if (k==1) 
		{
			f[i][j]=1;
			f[i][0]++;
		}
	}
	char s[30];
	while (~scanf("%s",&s))
	{
		int ff,fff=0;
		int l=strlen(s);
		for (i=7;i<=10001;i++)
		{
			ff=0;
			if (f[i][0]>=2*l+1)
			{
				for (j=0;j<l;j++)
					if ((s[j]-'0')!=f[i][f[i][0]-j])
					{
						ff=1;
						break;
					}
				if (ff==0)
				{
					printf("%d\n",i);
					fff=1;
					break;
				}
			}
		}
		if (fff==0) printf("no power of 2\n");
	}
	return 0;
}
