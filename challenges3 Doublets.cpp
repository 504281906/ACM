#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;
int t,flag;
string line,s1,s2,s[25145];
map<string,int> m;
map<string,int>::iterator it;
int vis[25145];
bool bj(string s1,string s2)
{
	if (s1.length()!=s2.length()) return false;
	int k=0;
	for (int i=0;i<s1.length();i++)
		if (s1[i]!=s2[i]) k++;
	if (k!=1) return false;
	return true; 
}
int DFS(int x)
{
	if (s1==s2) 
	{
		flag=1;
		return 1;
	}
	for (it=m.begin();it!=m.end();it++)
	{
		if (bj(s1,(*it).first) and vis[(*it).second]==0)
		{
			s[t++]=(*it).first;
			vis[(*it).second]=1;
			s1=s[t-1];
			DFS(x+1);
			if (flag) return 1;
			vis[(*it).second]=0;
			t--;
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
			s[0]=s1;
			t=1;
			vis[(*m.find(s1)).second]=1;
			flag=0;
			int f=DFS(0);
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

