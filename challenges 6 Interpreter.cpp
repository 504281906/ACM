#include <cstdio>
#include <cstring>
int f[11];
int m[1010];
char s[100];	
int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	getchar();
	for(int l=1;l<=t;l++)
	{
		int i=0;
		if (l==1) getchar();
		memset(m,0,sizeof(m));
		while (fgets(s,sizeof(s),stdin))
		{
			if (s[0]=='\n') break;
			sscanf(s,"%d",&m[i++]);
		}
		memset(f,0,sizeof(f));
		i=0;
		int k=0;
		bool end=true;
		while (end)
		{
			i++;
			a=m[k]/100;
			b=m[k]/10%10;
			c=m[k]%10;
			switch(a)
			{
				case 1:
						if (m[k]==100)
						end=false;
						break;
				case 2:
						f[b]=c;
						k++;
						break;
				case 3:
					{
						f[b]+=c;
						f[b]%=1000;
						k++;
						break;}
				case 4:
					{
						f[b]*=c;
						f[b]%=1000;
						k++;
						break;}
				case 5:
					{
						f[b]=f[c];
						k++;
						break;}
				case 6:
					{
						f[b]+=f[c];
						f[b]%=1000;
						k++;
						break;}
				case 7:
					{
						f[b]*=f[c];
						f[b]%=1000;
						k++;
						break;}
				case 8:
					{
						f[b]=m[f[c]];
						k++;
						break;}
				case 9:
					{
						m[f[c]]=f[b];
						k++;
						break;}
				case 0:
					{
						if (f[c]!=0) k=f[b];
						else k++;
						break;}				
			}
		}
		if (l!=1) 
			printf("\n");
		printf("%d\n",i);
	}
	return 0;
}
