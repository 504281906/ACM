#include <cstdio>
#include <cstring>
const char f[4][20]={"Accepted","Presentation Error","Wrong Answer"};
int a1[1000],b1[1000],n,m;
char a[110][110],b[110][110];
int ac()
{
	if (n!=m) return 0;
	for (int i=1;i<=n;i++)
		if (strcmp(a[i],b[i])!=0) return 0;
	return 1;
}
int pe()
{
	int x=0,y=0;
	for (int i=1;i<=n;i++)
	{
		int l=strlen(a[i]);
		for (int j=0;j<l;j++)
		if (a[i][j]>='0' && a[i][j]<='9') 
			a1[x++]=a[i][j]-'0';
	}
	for (int i=1;i<=m;i++)
	{
		int l=strlen(b[i]);
		for (int j=0;j<l;j++)
		if (b[i][j]>='0' && b[i][j]<='9') 
			b1[y++]=b[i][j]-'0';
	}
	if (x!=y) return 0;
	else 
	for (int i=0;i<x;i++)
	if (a1[i]!=b1[i]) return 0;
	return 1;
}
int main()
{
	int t=1;
	while (~scanf("%d",&n) && n)
	{
		int k;
		getchar();
		for (int i=1;i<=n;i++) 
			gets(a[i]);
		scanf("%d",&m);
		getchar();
		for (int i=1;i<=m;i++)
			gets(b[i]);
		if (ac()) k=0;
		else if (pe()) k=1;
		else k=2;
		printf("Run #%d: %s\n",t++,f[k]);
	}
	return 0;
}
