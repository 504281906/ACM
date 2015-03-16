#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char s[10][10][10]={{"O"},{"LV","MM"},{"HATE","SHIT","FUCK","UGLY"}};
/*char s[1]={"O"};
char s[2]={"LV","MM"};
char s[3]={"HATE","SHIT","FUCK","UGLY"};*/
char ss[1010];
int main()
{
	while (~scanf("%s",&ss))
	{
		int i,j;
		char *k;
		int l=strlen(ss);
		while (k=strstr(ss,s[0][0]))
		{
			int ll=strlen(k);
			for (i=1,j=0;i<ll;i++,j++)
				ss[l-ll+j]=k[i];
			ss[l-1]='\0';
			l=l-1;
		}
		int f=1;
		while (f)
		{
			f=0;
		for (i=0;i<=1;i++)
			while (k=strstr(ss,s[1][i]))
			{
				f=1;
				int j1,ll=strlen(k);
				for (j=2,j1=0;j<ll;j++,j1++)
					ss[l-ll+j1]=k[j];
				ss[l-2]='\0';
				l=l-2;
			}
			
		}
		f=1;
		while (f)
		{
			f=0;
			for (i=0;i<=3;i++)
			while (k=strstr(ss,s[2][i]))
			{
				f=1;
				int j1,ll=strlen(k);
				for (j=4,j1=0;j<ll;j++,j1++)
					ss[l-ll+j1]=k[j];
				ss[l-4]='\0';
				l=l-4;
			}
		}
		if (strlen(ss)==0) printf("LOSER\n");
		else printf("%s\n",ss);
	}
	return 0;
}
