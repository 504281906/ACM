#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[10010];
int b[30];
int main()
{
	int T,l;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",&a);
		l=strlen(a);
		for (int i=0;i<l;i)
		{
			int j=1;
			char c=a[i];
			while (c==a[++i]) j++;
			if (j==1) printf("%c",c);
			else printf("%d%c",j,c); 
		}
		printf("\n");
	}
	return 0;
}
