#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
int b[10];
char s[20];
int l,f;
long long mm;
int vist[100];
bool cmp(char a,char b)
{
	return a>b;
}
long long js()
{
	return (b[0]-b[1]*b[1]+b[2]*b[2]*b[2]-b[3]*b[3]*b[3]*b[3]+b[4]*b[4]*b[4]*b[4]*b[4]);
}
int DFS(int x)
{
	if (x==5 && f==0) 
	{
		
		long long k=js();
		if (k==mm) 
		{
			f=1;
			printf("%c%c%c%c%c\n",b[0]+'A'-1,b[1]+'A'-1,b[2]+'A'-1,b[3]+'A'-1,b[4]+'A'-1);
			return 0;
		}
	}
	for (int i=0;i<l;i++)
	if (x<5)
	{
	if (vist[i]==0)
	{
		b[x]=s[i]-'A'+1;
		vist[i]=1;
		DFS(x+1);
		vist[i]=0;
	}
	}
	return 0;
}
using namespace std;
int main()
{
	while (~scanf("%lld%s",&mm,&s) && (mm!=0 && s!="END"))
	{
		l=strlen(s);
		memset(b,0,sizeof(b));
		memset(vist,0,sizeof(vist));
		sort(s,s+l,cmp);
		f=0;
		DFS(0);
		if (f==0) printf("no solution\n"); 
	}
	return 0;
}
