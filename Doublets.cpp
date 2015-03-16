#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
using namespace std;
int t,flag;
string line,s1,s2;
string ss[25150];
string s5[25150];
map <string,int> m;
int vis[25150];
int b[25150];
bool bj(string s1,string s2)
{
	if (s1.length()!=s2.length()) return false;
	int k=0;
	for (int i=0;i<s1.length();i++)
	{
		if (k>1) return false;
		if (s1[i]!=s2[i]) k++;
	}
	if (k!=1) return false;
	return true; 
}
int BFS()
{
	queue <string> q;
	while (!q.empty()) q.pop();
	q.push(s1);
	map<string,int>::iterator it;
	while (!q.empty())
	{
		s1=q.front();
		int j=m[s1];
		q.pop();
		if (s1==s2) 
		{
			flag=j;
			return 1;
		}
	for (it=m.begin();it!=m.end();it++)
	{
		if ((vis[(*it).second]==0) && bj(s1,(*it).first))
		{
			q.push((*it).first);
			b[m[(*it).first]]=j;
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
			s5[k]=line;
			m.insert(make_pair(line,k));
		}
	}
	int ci=0;
	while (getline(cin,line) && line.length()>0)
	{   
		istringstream is(line);
		is>>s1;
		is>>s2;
		for (int i=0;i<25150;i++)
		{
			vis[i]=0;
			b[i]=0;
		}
		if (ci++) printf("\n");
		if (m.find(s1)==m.end() || m.find(s2)==m.end() || s1.length()!=s2.length()) 
		{
			printf("No solution.\n");
			continue;
		}
		else
		{
			vis[(*m.find(s1)).second]=1;
			flag=0; 
			int f=BFS();
			if (f==0) printf("No solution.\n");
			else 
			{
				int j=1;
				for (int i=flag;i;i=b[i])
					ss[j++]=s5[i];
				for (int i=j-1;i>=1;i--)
					cout<<ss[i]<<endl;
			}
		}
	}
	return 0;
}
