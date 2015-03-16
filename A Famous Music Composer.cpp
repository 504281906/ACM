#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int k=0;
	char s[20];
	while (gets(s))
	{
		if (s[0]=='A'&&s[1]=='#')
		{
			s[0]='B';
			s[1]='b';
			printf("Case %d: %s\n",++k,s); 
		}
		else if(s[0]=='A'&&s[1]=='b')
		{
			s[0]='G';
			s[1]='#';
			printf("Case %d: %s\n",++k,s);	
		}
		else if(s[0]=='B'&&s[1]=='b')
		{
			s[0]='A';
			s[1]='#';
			printf("Case %d: %s\n",++k,s);
		}
		else if (s[0]=='C'&&s[1]=='#')
		{
			s[0]='D';
			s[1]='b';
			printf("Case %d: %s\n",++k,s); 
		} 
		else if (s[0]=='D'&&s[1]=='b')
		{
			s[0]='C';
			s[1]='#';
			printf("Case %d: %s\n",++k,s);
		}
		else if (s[0]=='D'&&s[1]=='#')
		{
			s[0]='E';
			s[1]='b';
			printf("Case %d: %s\n",++k,s); 
		}
		else if (s[0]=='E'&&s[1]=='b')
		{
			s[0]='D';
			s[1]='#';
			printf("Case %d: %s\n",++k,s);
		}
		else if (s[0]=='F'&&s[1]=='#')
		{
			s[0]='G';
			s[1]='b';
			printf("Case %d: %s\n",++k,s);
		}
		else if (s[0]=='G'&&s[1]=='b')
		{
			s[0]='F';
			s[1]='#';
			printf("Case %d: %s\n",++k,s); 
		}
		else if (s[0]=='G'&&s[1]=='#')
		{
			s[0]='A';
			s[1]='b';
			printf("Case %d: %s\n",++k,s);
		}
		else printf("Case %d: UNIQUE\n",++k);
	}
	return 0;
} 
