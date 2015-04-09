#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int T,n,i,j;
	int b[10];
	char a[3010][5];
	scanf("%d",&T);
	while (T--)
	{
		getchar();
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%s",&a[i]);
			b[i]=i;
		}
		for (i=0;i<n-1;i++)
			for (j=i+1;j<n;j++)
			{
				int t=0;
				while (1)
				{
					if (a[b[i]][t]=='\0')
					{
						if (a[b[j]][t]>a[b[j]][0])
						{
							int k=b[i];
							b[i]=b[j];
							b[j]=k;
						}
						break;
					}
					if (a[b[j]][t]=='\0')
					{
						if (a[b[i]][t]<a[b[i]][0])
						{
							int k=b[i];
							b[i]=b[j];
							b[j]=k;
						}
						break;
					}
					if (a[b[i]][t]>a[b[j]][t])
						break;
					else if (a[b[i]][t]==a[b[j]][t]) t++;
					else 
					{
						int k=b[i];
						b[i]=b[j];
						b[j]=k;
						break;
					}		
				}
			}
		for (i=0;i<n;i++)
			printf("%s",a[b[i]]);
		cout<<endl;
	}
	return 0;
}
