#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;
struct node
{
	int name;
	int t;
	int time;
	int ac[11];
	int tt[11];
}f[110];
bool cmp(node a,node b)
{
	if (a.t==b.t && a.time==b.time)
		return a.name<b.name;
	if (a.t==b.t)
		return a.time<b.time;
	return a.t>b.t;
}
int g[110][11];
int main()
{
	int T;
	
	scanf("%d",&T);
	cin.get();
	string line;
	//getchar();
	getline(cin,line);
	while (T--)
	{
		int a,b,c;	
		char d;
		memset(g,true,sizeof(g));
		for (int i=1;i<=100;i++)
		{
			f[i].time=0;
			f[i].t=0;
			for (int j=0;j<=10;j++)
			{
				f[i].tt[j]=0;
				f[i].ac[j]=0;
			}
		}	
		while (getline(cin,line) && line.length()>0)
		{
			istringstream is(line);
			string str; 
			is>>a;
			is>>b;
			is>>c;
			is>>d;
		//	char cc=getchar();
		f[a].name=a;
		if (d=='I' && g[a][b])
		{
			f[a].tt[b]+=20;
		}
		else if (d=='C' && g[a][b])
			{
				g[a][b]=false;
				f[a].tt[b]+=c;
				f[a].ac[b]=1;
			}
		else 
			continue;
		}
		for (int i=1;i<=100;i++)
		for (int j=1;j<=9;j++)
		if (f[i].ac[j])
		{
			f[i].time+=f[i].tt[j];
			f[i].t++;
		}
		sort(f+1,f+101,cmp);
		for (int i=1;i<=100;i++)
			if (f[i].name!=0)
				printf("%d %d %d\n",f[i].name,f[i].t,f[i].time);
		//	else if (f[i].name!=0)
		//		printf("%d\n",f[i].name);
		if (T) printf("\n");
	}
	return 0;
}
