#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define min(x,y) x<y?x:y
int main()
{
	int a[130][130],n;
	memset(a,0,sizeof(a));
	for (int i=0;i<122;i++)
		a[i][0]=a[i][1]=a[0][i]=a[1][i]=1;
	for (int i=2;i<122;i++)
		for (int j=2;j<122;j++)
		{
			if (i>=j)
				a[i][j]=a[i][j-1]+a[i-j][j];
			else 
				a[i][j]=a[i][i];		
		}
	while (~scanf("%d",&n))
		printf("%d\n",a[n][n]);
	return 0;
}
