#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
char s[55],f[55][55];
int n,m,xxx,yyy,l;
bool zz(int x,int y)
{
	for (int i=1;i<l;i++)
	{
		if (f[x][y-i]!=s[i])
		return false;
	}	
	return true;
}
bool zs(int x,int y)
{
	for (int i=1;i<l;i++)
	{
		if (f[x-i][y-i]!=s[i])
		return false;
	}	
	return true;
}
bool ss(int x,int y)
{
	for (int i=1;i<l;i++)
	{
		if (f[x-i][y]!=s[i])
		return false;
	}	
	return true;
}
bool ys(int x,int y)
{
	for (int i=1;i<l;i++)
	{
		if (f[x-i][y+i]!=s[i])
		return false;
	}	
	return true;
}
bool yy(int x,int y)
{
	for (int i=1;i<l;i++)
	{
		if (f[x][y+i]!=s[i])
		return false;
	}	
	return true;
}
bool yx(int x,int y)
{
	for (int i=1;i<l;i++)
	{
		if (f[x+i][y+i]!=s[i])
		return false;
	}	
	return true;
}
bool xx(int x,int y)
{
	for (int i=1;i<l;i++)
	{
		if (f[x+i][y]!=s[i])
		return false;
	}	
	return true;
}
bool zx(int x,int y)
{
	for (int i=1;i<l;i++)
	{
		if (f[x+i][y-i]!=s[i])
		return false;
	}	
	return true;
}
void find(char c[55])
{
	bool ff=false;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			if (f[i][j]==c[0])
			ff=zz(i,j) || zs(i,j) || ss(i,j) || 
			   ys(i,j) || yy(i,j) || yx(i,j) ||
			   xx(i,j) || zx(i,j);
			if (ff) 
			{
				xxx=i;
				yyy=j;
				return;
			}
		}		
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		getchar();
		for (int i=0;i<n;i++)
		{	
			for (int j=0;j<m;j++)
			{
				scanf("%c",&f[i][j]);
				if (f[i][j]<'a')
				f[i][j]+='a'-'A'; 
			}
			getchar();
		}
		int t;
		scanf("%d",&t);
		getchar();
		while (t--)
		{
			gets(s);
			l=strlen(s);
			for (int i=0;i<l;i++)
			if (s[i]<'a') s[i]+='a'-'A';
			find(s);
			printf("%d %d\n",xxx+1,yyy+1);
		}
		if (T) printf("\n");
	}
	return 0;
}
