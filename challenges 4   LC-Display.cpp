#include <cstdio>
#include <cstring>
char z[][40]={ " -     -  -     -  -  -  -  - ",
			   "| |  |  |  || ||  |    || || |",
			   "       -  -  -  -  -     -  - ",
			   "| |  ||    |  |  || |  || |  |",
			   " -     -  -     -  -     -  - "};
int main()
{
	int s,l;
	char m[10];
	while(~scanf("%d",&s) && s)
	{
		getchar();
		scanf("%s",&m);
		l=strlen(m);
		for (int i=0;i<2*s+3;i++)
		{
			for (int j=0;j<l;j++)
			{
				int num=m[j]-'0';
				if (i==0 || i==s+1 || i==s*2+2)
				{
					int t;
					if (i==0) t=0;
					if (i==s+1) t=2;
					if (i==s*2+2) t=4;
					printf("%c",z[t][num*3]);
					for (int k=0;k<s;k++)
					printf("%c",z[t][num*3+1]);
					printf("%c",z[t][num*3+2]);
				}
				else if (i>0 && i<s+1)
				{
					printf("%c",z[1][num*3]);
					for (int k=0;k<s;k++)
					printf("%c",z[1][num*3+1]);
					printf("%c",z[1][num*3+2]);
				}
				else
				{
					printf("%c",z[3][num*3]);
					for (int k=0;k<s;k++)
					printf("%c",z[3][num*3+1]);
					printf("%c",z[3][num*3+2]);
				}
				if (j!=l-1)
				printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
