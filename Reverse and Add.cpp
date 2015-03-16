#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int f(char s[20])
{
	int l=strlen(s);
	for (int i=0;i<l/2;i++)
		if (s[i]!=s[l-i-1]) return 1;
	return 0;
}
int main()
{
	int T;
	char s[100];
	scanf("%d",&T);
	while (T--)
	{
		getchar();
		int t=0;
		scanf("%s",&s);
		int l=strlen(s);
		while (f(s)) 
		{
			t++;
			long long k=0,k1=0;
			l=strlen(s);
			for (int i=0;i<l;i++)
			{	
				k=k*10+s[i]-'0';
				k1=k1*10+s[l-i-1]-'0';
			}
			k=k+k1;
			int i=0;
			while (k)
			{
				s[i++]=k % 10+'0';
				k/=10;
			}
			s[i]='\0';
		}
		printf("%d %s\n",t,s);
	} 
	return 0;
}
