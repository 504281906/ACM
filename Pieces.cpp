#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[50];
int vis[50];
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		memset(vis,0,sizeof(vis));
		gets(s);
		int l=strlen(s);
		int k=0,i,t=0;
		vis[0]=1;
		int h=l-1;
		while (k<l)
		{
			int pos=k;
			for (i=h;i>k;i--)
				if (s[i]==s[k] && vis[i]==0) 
				{
					vis[i]=1;
					pos=i;
					h=i;
					break;
				}
			if (pos==k) 
			{
				t++;
				h=l-1;
			}
			else
			{
				bool flag=true;
			for (i=k+1;i<pos;i++)
			if (vis[i]==0) 
			{
				flag=false;
				break;
			}
			if (flag) t++;
			}
			while (vis[++k]==1);
		}
		printf("%d\n",t);
	}
	return 0;
}
