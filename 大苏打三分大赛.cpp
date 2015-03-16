#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[21][21][21];
int a,b,c;
void DFS(int x,int y,int z)
{
	if(f[x][y][z])return;
	f[x][y][z] = 1;
	
	if(a-x>0)
	{
		if(y>0)
			DFS(x+y>a?a:x+y,x+y>a?(x+y-a):0,z);
		if(z>0)
			DFS(x+z>a?a:x+z,y,x+z>a?(x+z-a):0);
	}
	if(b-y>0)
	{
		if(x>0)
			DFS(x+y>b?(x+y-b):0,y+x>b?b:x+y,z);
		if(z>0)
			DFS(x,z+y>b?(z+y-b):0,y+z>b?b:z+y);
	}
	if(c-z>0)
	{
		if(x>0)
			DFS(z+x>c?(z+x-c):0,y,x+z>c?c:x+z);
		if(y>0)
			DFS(x,z+y>c?(z+y-c):0,y+z>c?c:y+z);
	}
} 

int main()
{
	
	while(cin>>a>>b>>c)
	{
		memset(f,0,sizeof(f));
		DFS(0,0,c);
		int flag = 0;
		for(int i=b;i>=0;i--)
		for(int j=20;j>=0;j--)
		{
			if(f[0][i][j])
			{
				if(flag)
					cout<<" ";
				else
					flag = 1;
				cout<<j;
			}
		}
		cout<<endl;
	}
}
