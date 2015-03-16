#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
char s[1000010];
char s2[400010]={0},s1[400010]={0},s3[400010]={0};
int main()
{
	int T,i,j;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		int h=0;
		gets(s);
		int l=strlen(s);
		int k=0,f=0;
		for (i=l/3+1;i<l-l/3;i++)
			s2[k++]=s[i];
		s3[-1]='\0';
		memset(s1,0,sizeof(s1));
		memset(s3,0,sizeof(s3));
		for (i=0;i<k;i++)
		{
			s1[i]=s[i];
			s1[i+1]='\0';
			for (j=i;j>0;j--)
			s3[j]=s3[j-1];
			s3[0]=s[l-1];
			if (strcmp(s1,s3)==0)
			{
				char *ss=strstr(s2,s1);
				if (ss!=NULL) h=i;	
			}
			l--;
		}
		printf("%d\n",h+1);
	}
	return 0;
}
