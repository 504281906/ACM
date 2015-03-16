#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char a[20],b[20];
	while (~scanf("%s%s",&a,&b) && (a[0]!='0' || b[0]!='0' || strlen(a)!=1 || strlen(b)!=1) )
	{
		int i,j,t=0,l1,l2,k,l;
		l1=strlen(a);
		l2=strlen(b);
		if (l1>l2)
		{
			for (k=l1,i=l2-1;i>=0;i--)
				b[--k]=b[i];
			for (j=0;j<k;j++)
				b[j]='0';
			l=l1;
		}
		else
		{
			for (k=l2,i=l1-1;i>=0;i--)
				a[--k]=a[i];
			for (j=0;j<k;j++)
				a[j]='0';
			l=l2;
		}
		k=0;
		for (i=l-1;i>=0;i--)
		{
			if (a[i]-'0'+b[i]-'0'+k>=10)
			{
				k=1;
				t++;
			}
			else k=0;
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		if (t==0) printf("No carry operation.\n");
		else
		if (t==1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n",t);
	}
	return 0;
}
