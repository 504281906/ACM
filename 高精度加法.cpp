#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[510],b[510];
int c[510],la,i,lb;
int main()
{
	while (~scanf("%s%s",&a,&b))
	{
		memset(c,0,sizeof(c));
		la=strlen(a)-1;
		lb=strlen(b)-1;
		int k=la<lb?lb:la;
		i=0;
		k++;
		while (k--)
		{
			if (la>=0 && lb>=0)
			c[i]+=(a[la--]-'0')+(b[lb--]-'0');
			else if (la>=0)
			c[i]+=(a[la--]-'0');
			else c[i]+=(b[lb--]-'0');
			if (c[i]>=10)
			{
				c[i+1]++;
				c[i]-=10;
			}
			i++;
		}
		while (c[i]==0) i--;
		for (int j=i;j>=0;j--)
		printf("%d",c[j]);
		printf("\n");
	}
	return 0;
}
