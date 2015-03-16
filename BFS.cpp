#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
using namespace std;
int t,flag;
string line,s1,s2;
int w[25145];
map<string,int> m;
map<string,int>::iterator it;
int vis[25145];
struct node
{
	string s;
	int pos;
};
queue<node>q;
bool bj(string s1,string s2)
{
	if (s1.length()!=s2.length()) return false;
	int k=0;
	for (int i=0;i<s1.length();i++)
		if (s1[i]!=s2[i]) k++;
	if (k!=1) return false;
	return true; 
}
int BFS(int x)
{
	while (!q.empty())
	{
		node ss=q.front();
		q.pop();
		for (it=m.begin();it!=m.end();it++)
		{
			if (bj(ss.s,(*it).first) and vis[(*it).second]==0)
			{
				
			}
		}
}
int main()
{
	m.clear();
	int k=0;
	while (getline(cin,line) && line.length()>0)
	{
		it=m.find(line);
		if (it==m.end())
		{
			k++;
			m.insert(make_pair(line,k));
		}
	}
	int ci=0;
	while (ci++,getline(cin,line) && line.length()>0)
	{   
		istringstream is(line);
		is>>s1;
		is>>s2;
		memset(vis,0,sizeof(vis)); 
		if (ci) printf("\n");
		if (m.find(s1)==m.end() || m.find(s2)==m.end()) 
		{
			printf("No solution.\n");
			continue;
		}
		else
		{
			t=1;
			vis[(*m.find(s2)).second]=1;
			flag=0;
			q.push(s2,(*m.find(s2)).second);
			int f=BFS(0);
			if (f==0) printf("No solution.\n");
			else 
			{
				for (int i=0;i<t;i++)
					cout<<s[i]<<endl;
			}
		}
	}
	return 0;
} 

