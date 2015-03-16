#include <cstdio> 
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
int a,b,c,d,n,m,i,j;
int x[4]={1,0,0,-1};
int y[4]={0,-1,1,0};
char z[4]={'D','L','R','U'};
char s[20][20];
void check(int& x1,int& y1,int& x2,int& y2,int i)
{
	if (x1<0 || x1>=n || y1<0 || y1>=m || s[x1][y1]=='#')
	{
		x1-=x[i];
		y1-=y[i];
	}
	if (x2<0 || x2>=n || y2<0 || y2>=m || s[x2][y2]=='#')
	{
		x2-=x[i];
		y2-=y[i];
	}
}
int hash(int a,int b,int c,int d)
{
	int k=a;
	k=k*100+b;
	k=k*100+c;
	k=k*100+d;
	return k;
}
struct zb
{
	int x1,y1,x2,y2;
	string ss;
};
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		set <int> st;
		queue <zb> q;
		st.clear();
		a=0;b=0;c=0;d=0;
		getchar();
		for (i=0;i<n;i++)
			scanf("%s",s[i]);
		for (i=0;i<n;i++)
			for (j=0;j<m;j++)
				if (s[i][j]=='*')
					if (a==0 && b==0)
					{
						a=i;
						b=j;
					}
					else
					{
						c=i;
						d=j;
						break;
					}
		int k=hash(a,b,c,d);
		st.insert(k);
		zb qq=(zb){a,b,c,d,"."};
		q.push(qq);
		int flag=0;
		string ans;
		while (!q.empty())
		{
			qq=q.front();
			q.pop();
			if (flag && (qq.ss.size()>ans.size())) break;
			if (qq.x1==qq.x2 && qq.y1==qq.y2)
			{
			//	cout<<ans<<endl;
				if (ans.size()==0) ans=qq.ss;
				else if (ans.size()>qq.ss.size()) ans=qq.ss;
				flag=1;
			}
			for (i=0;i<4;i++)
			{
				int X1=qq.x1+x[i],X2=qq.x2+x[i];
				int Y1=qq.y1+y[i],Y2=qq.y2+y[i];
				check(X1,Y1,X2,Y2,i);
				string sss=qq.ss+z[i];
				k=hash(X1,Y1,X2,Y2);
				if (!st.count(k))
				{
					st.insert(k);
					zb ww=(zb){X1,Y1,X2,Y2,sss};
					q.push(ww);
				}
			}
		}
		if (flag) 
		{
			for (i=1;i<ans.size();i++)
				printf("%c",ans[i]);
			printf("\n");
		}
		else printf("Sorry\n");
	}
	return 0;
}
