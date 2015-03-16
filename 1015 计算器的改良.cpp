#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	char s[1200];
	scanf("%s",&s);
	int l=strlen(s);
	int i=0,t=0,k=0,x=0,y=0;
	char c;
	while (i<l)
	{
		if (s[i]=='=') 
		{
			i++;
			t=1;
		}
		if (s[i]=='-')
		{
			i++;
			k=1;
		}
		if (s[i]=='+') i++;
		int f=0;
		while (s[i]>='0' && s[i]<='9')
			f=f*10+s[i++]-'0';
		if (s[i]>='a' && s[i]<='z')
		{
			c=s[i++];
			if ( (k+t)%2 ==0 ) x+=f;
			else x-=f;
			k=0;
		}
		else
		{
			if ( (k+t)%2 ==0 ) y+=f;
			else y-=f;
			k=0;
		}
	}
	double ans=y*1.000/x;
	printf("%lf\n",ans);
	return 0;
}
