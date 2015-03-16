#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	int a[20010],b[20010],i,n,m;
	while (~scanf("%d%d",&n,&m) && (m+n))
	{
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (i=0;i<m;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+m);
		int f=0;
		int s=0,j=0;
		for (i=0;i<n;i++)
		{
			while ((b[j]<a[i]) && (j<m)) j++;
			if (j==m) {f=1;break;}
			else 
			{
				s+=b[j];
				j++;
			}
		}
		if (f) printf("Loowater is doomed!\n");
		else printf("%d\n",s);
	}
	return 0;
}
