#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctype.h>
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
{
	int n,i,l;
	char s[1000050];
	cin>>n;
	getchar(); 
	while (n--)
	{
		gets(s);
		//puts(s);
		l=strlen(s);
		int k=16;
		__int64 a=0;
		if ( isalpha(s[l-1]) ) a+=s[l-1]-'A'+10;
		else a+=s[l-1]-'0';
		for (i=l-2;i>=0;i--)
		{
			int h;
			if (isalpha(s[i])) h=k*(s[i]-'A'+10);
				else h=k*(s[i]-'0');
			k*=16;
			a+=h;
		}
		char g[1000100];
		itoa(a,g,8);
		printf("%s\n",g);
	}
	return 0;
}
