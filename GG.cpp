#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
using namespace std;
int t,flag;
string line,s1,s2,s[25150];
map <string,int> m;
int vis[25150];
int b[25150];
queue <string,int> q;
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
	map<string,int>::iterator it;
	while (!q.empty())
	{
		s1=q.front().first;
		int j=q.front().second;
		q.pop();
		if (s1==s2) 
		{
			flag=j;
			return 1;
		}
	for (it=m.begin();it!=m.end();it++)
	{
		if (bj(s1,(*it).first) && vis[(*it).second]==0)
		{
			q.push(make_pair((*it).first,t++));
			s[t]=(*it).first;
			b[t]=j;
			vis[(*it).second]=1;
		}
	}
}
	return 0;
}
int main()
{
	m.clear();
	int k=0;
	while (getline(cin,line) && line.length()>0)
	{
		map<string,int>::iterator it;	
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
		memset(b,0,sizeof(b));
		if (ci) printf("\n");
		if (m.find(s1)==m.end() || m.find(s2)==m.end()) 
		{
			printf("No solution.\n");
			continue;
		}
		else
		{
			s[0]=s1;
			t=1;
			vis[(*m.find(s1)).second]=1;
			flag=0;
			q.push(make_pair(s1,0)); 
			int f=BFS(0);
			if (f==0) printf("No solution.\n");
			else 
			{
				for (int i=j;i;i=b[i])
					cout<<s[i]<<endl;
			}
		}
	}
	return 0;
}
