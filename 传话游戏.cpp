#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <sstream>
using namespace std;
//#define DEBUG
char s[110][30];
struct node
{
	char a[30],b[30];
}f[110];
int T,n,m,i,j;
int main()
{
/*#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif*/
	scanf("%d",&T);
	int cas=1;
	while (T--)
	{
		printf("Case #%d: ",cas++);
		scanf("%d%d",&n,&m);
		getchar();
		for (i=1;i<=m;i++)
		{
			scanf("%s %s",&f[i].a,&f[i].b);	
			getchar();
		}
		string line;
		getline(cin,line);
		istringstream ss(line);
		int k=1;
		while (ss>>s[k++]);
		k--;
		int flag=1;
		n--;
		while (n-- && flag)
		{
			flag=0;
			for (i=1;i<k;i++)
				for (j=1;j<=m;j++)
				if (strcmp(s[i],f[j].a)==0)
				{
					flag=1;
					strcpy(s[i],f[j].b);
					break;
				}
		}
		printf("%s",s[1]);
		for (i=2;i<k;i++)
			printf(" %s",s[i]);
		printf("\n");
	}
	return 0;
}
