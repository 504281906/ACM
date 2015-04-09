#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char a[510];
	int c[510]; 
	int b,l;
	while (~scanf("%s%d",&a,&b))
	{
		memset(c,0,sizeof(c)); 
		l=strlen(a);
		int ys=0;
		int t=0,i;
		for (i=0;i<l;i++)
		{
			if (a[i]-'0'+10*ys>=b)
			{
				c[t]=(a[i]-'0'+10*ys)/b;
				ys=(a[i]-'0'+10*ys)%b;
				t++;
			}
			else ys=ys*10+a[i]-'0';
		}
		while (c[i]==0) i--;
		for (int j=i;j>=0;j--)
			printf("%d",c[j]);
		if (ys) printf(" %d",ys);
			printf("\n");
	}
	return 0;
}
