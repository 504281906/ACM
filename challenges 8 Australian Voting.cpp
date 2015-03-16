#include <cstdio>
#include <cstring>
int g[30],vist[30],f[1010][30],k,n;
char name[30][100];
void ff()
{
	memset(vist,true,sizeof(vist));
	bool fff=true;
	bool pj=false;
	while (fff)
	{
		memset(g,0,sizeof(g));
		for (int i=1;i<=k;i++)
			for (int j=1;j<=n;j++)
			{
				int w=f[i][j];
				if (vist[w])
				{
					g[w]++;
					break;
				}
			}
		for (int i=1;i<=n;i++)
		if (g[i]>k/2)
		{
			fff=false;
			pj=true;
			puts(name[i]);
			break;
		}
		if (!fff) break;
		fff=false;
		int first=0;
		int p;
		int j;
		for (int i=1;i<=n;i++)
			if (vist[i])
			{
				j=i;
				first++;
				p=g[i];
				break;
			}
		for (int i=j+1;i<=n;i++)
			if (vist[i])
			{
				first++;
				if (p!=g[i])
				{
					fff=true;
					break;
				}
			}
		if (!fff || first==1) break;
		int min=0x3fffffff;
		for (int i=1;i<=n;i++)
				if (min>g[i] && vist[i] ) 
				min=g[i];
		for (int i=1;i<=n;i++)
				if (min==g[i] && vist[i])
					vist[i]=false;
	}
	if (!pj)
	for (int i=1;i<=n;i++)
		if (vist[i]) puts(name[i]);
	return;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		getchar();
		for (int i=1;i<=n;i++)
		gets(name[i]);
		k=1;
		char s[100];
		while (gets(s)!=NULL && s[0]!='\0')
		{
			int j=1;
			int l;
			l=strlen(s);
			for (int i=0;i<l;i++)
				if (s[i]!=' ')
				{
					int q=0;
					while (s[i]!=' ' && s[i]!='\0')
						q=q*10+s[i++]-'0';
					f[k][j++]=q;
				}
			k++;
		}
		k--;
		ff();
		if (T) printf("\n");
	}
	return 0;
} 
