#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
	int begin1;
	int begin2;
	int end1;
	int end2;
}f[1010];
int cmp(node a,node b)
{
	if (a.begin1==b.begin1)
		return a.begin2<b.begin2;
	return a.begin1<b.begin1;
}
int main()
{
	string s;
	int n;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T=1;
	while (~scanf("%d",&n))
	{
		getchar();
		for (int i=0;i<n;i++)
		{
			getline(cin,s);
			f[i].begin1=(s[0]-'0')*10+(s[1]-'0');
			f[i].begin2=(s[3]-'0')*10+(s[4]-'0');
			f[i].end1=(s[6]-'0')*10+(s[7]-'0');
			f[i].end2=(s[9]-'0')*10+(s[10]-'0'); 
		}
		sort(f,f+n,cmp);
		f[-1].end1=10;f[-1].end2=0;
		f[n].begin1=18;f[n].begin2=0;
		//for (int i=0;i<n;i++)
		//	cout<<f[i].begin1<<":"<<f[i].begin2<<"->"<<f[i].end1<<":"<<f[i].end2<<endl;
		int t=0,t1=10,t2=0,pos=0;
		for (int i=0;i<=n;i++)
		{
			if ((f[i].begin1>t1) || ((f[i].begin1)==t1)&&(f[i].begin2>t2))
			{
				if (t<(f[i].begin1-t1)*60+(f[i].begin2-t2))
				{
					t=(f[i].begin1-t1)*60+(f[i].begin2-t2);
					pos=i-1;
				}
			}
			t1=f[i].end1;
			t2=f[i].end2;
		} 
		t1=t/60;
		t2=t%60;
		printf("Day #%d: ",T++);
		printf(f[pos].end2<10?"the longest nap starts at %d:0%d and will last for ":"the longest nap starts at %d:%d and will last for ",f[pos].end1,f[pos].end2);
		if (t1==0)
		printf("%d minutes.\n",t2);
		else 
		printf("%d hours and %d minutes.\n",t1,t2);
	}
	return 0;
}
