#include <cstdio>
#include <iostream>
using namespace std;
int f[200][200];
int main()
{
	int n,m,a,b;
	while (~scanf("%d%d",&n,&m))
	{
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				f[i][j]=f[j][i]=300;
		for (int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			f[a][b]=f[b][a]=1;
		}
		for (int k=0;k<n;k++)
			for (int j=0;j<n;j++)
				for (int i=0;i<n;i++)
					if (f[j][i]>f[j][k]+f[k][i])
						f[j][i]=f[i][j]=f[i][k]+f[k][j];
		int kk=1;
		for (int i=0;i<n;i++)
			if (kk)
				for  (int j=0;j<n;j++)
					if(f[i][j]>7)
					{
						printf("No\n");
						kk=0;
						break;
					} 
		if (kk) printf("Yes\n");
	}
	return 0;
}
