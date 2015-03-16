#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring> 
using namespace std;
char a[1000];
int n,i;
int main()
{
	while (~scanf("%s%d",a,&n))
	{
		int m=0;
		int l=strlen(a);
		for (i=0;i<l;i++)
			m=((m*10)%n+(a[i]-'0'))%n;
		cout<<m<<endl;
	}
	return 0;
}
