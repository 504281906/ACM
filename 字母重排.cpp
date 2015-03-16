#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
#define DEBUG
int f=0;
char c[1000][100],x[1000][10],k[1000][10];
void ff(char s[10])
{
	char ss[10];
	strcpy(ss,s);
	int l=strlen(s);
	for (int i=0; i<l; i++)
		for (int j=i+1; j<l; j++)
		if (s[i] > s[j])
		{
			char t=s[i];
			s[i]=s[j];
			s[j]=t;
		}
	strcpy(k[f++],s);
	strcpy(s,ss);
	//memset(&k[f++],s,sizeof(char));
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	char s[10];
	while (~scanf("%s",x[f]) && x[f][0]!='*')
		ff(x[f]);
	int h=f;
	while (~scanf("%s",s))
	{
		ff(s);
		int fff=0;
		for (int i=0; i<h; i++)
		{
			if (strcmp(k[i],k[f-1])==0)
			{
				printf(" %s",x[i]);
				fff=1;
			}
		}
		if (fff==0) printf(":(");
		printf("\n");
	}
	return 0;
}
