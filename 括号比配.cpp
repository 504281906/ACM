#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAX=10001;
char s[MAX];
char a[MAX];
int k;
int l;
int len;
int find(int p)
{
	strcpy(a,s);
	a[p]=')';
	a[p+1]='(';
	p+=2;
	int i;
	for(i=p;i<len;++i)
	{
		if(l>0)
		{
			a[i]='(';
			l--;
		}
		else
		{a[i]=')';}
	}
	return 1;
}
int main()
{
	int i,j;
	while(scanf("%s",&s)!=EOF)
	{
		k=j=l=0;
		len=strlen(s);
		for(i=len-1;i>=0;--i)
		{
			if(s[i]=='('&&k<-1)
			{
				j=find(i);
				break;
			}
			if(s[i]==')')
			{k--;}
			else
			{
				k++;
				l++;
			}
		}
		if(j==0)
		{printf("No solution\n");}
		else
		{printf("%s\n",a);}
	}
	return 0;
}
