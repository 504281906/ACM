#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
	int t,i,j;
	char s[10100];
	freopen("C-large-practice.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&t);
	getchar();
	int qq=0;
	int k=0;
	while (t--)
	{
		printf("Case #%d: ",++qq);
		gets(s);
		int l=strlen(s);
		for (i=0;i<l;i++)
		{
			j=0;
			if (s[i]==' ') 
			{
				if (j==k) printf(" ");
				k=0;
				printf("0");
				continue;
			}
			j=s[i]-'a'+1;
			int y;
			if (j<=15)
			{
				y=(j-1)%3;
				j=ceil(j*1.0/3);
				j++;
			}
			else
			{
				if (j<=19) 
				{
					y=j-16;
					j=7;
					
				}
				else
				if (j<=22)
				{
					y=j-20;
					j=8;
					
				}
				else
				{
					y=j-23;
					j=9;
					
				}
			}
			if (j==k) printf(" ");
			k=j;
			for (int h=0;h<=y;h++)
				printf("%d",j);
		}
		printf("\n");
	}
	return 0;
}
