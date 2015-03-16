#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
bool end=false;
bool cmp(char a,char b)
{
	return a<b;
}
bool panduan(string str)
{
	sort(&str[0],&str[0]+str.length(),cmp);
	for (int i=0;i<str.length()-1;i++)
	{
		if (str[i]!='*' && str[i+1]!='*' && str[i]==str[i+1])
		return false;
	}
	return true;
}
bool pipei(string a,string b,string &str)
{
	string now=str;
	if (a.length()!=b.length())
		return false;
	for (int i=0;i<a.length();i++)
	{
		if (str[b[i]-'a']=='*')
			str[b[i]-'a']=a[i];
		else
		if (str[b[i]-'a']!=a[i])
		{
			str=now;
			return false;
		}
	}
	if (!panduan(str))
	{
		str=now;
		return false;
	}
	return true;
}
void jiemi(vector<string>&dict,vector<string>&word,int begin ,string &str)
{
	string now=str;
	if (begin==word.size())
	{
		end=panduan(str);
		return;
	}
	for (int i=0;i<dict.size();i++)
		if (pipei(dict[i],word[begin],str))
		{
			jiemi(dict,word,begin+1,str);
			if(end)
			return;
			else
			str=now;
		}
}
void password(string line,vector <string> &word)
{
	istringstream ss(line);
	string s;
	bool f;
	while (ss>>s)
	{
		f=false;
		for (int i=0;i<word.size();i++)
			if (s==word[i])
			{f=true;break;}
		if (!f) word.push_back(s);
	}
	return;
}
void shuchu(string line, string str)
{
	for (int i = 0; i < line.length(); i++)
		if (line[i] == ' ')
			cout << ' ';
		else
			cout << str[line[i] - 'a'];
	cout << endl;
}
int main()
{
	string line;
	vector<string> dict;
	vector<string> word;
	map<string,int> exist; 
	map<string,int>::iterator it;
	int t;
	scanf("%d",&t);
	getchar();
	for (int i=0;i<t;i++)
	{
		getline(cin,line);
		it=exist.find(line);
		if (it==exist.end())
		{
			dict.push_back(line);
			exist.insert(make_pair(line,dict.size()-1)); 
		}
	}
	while (getline(cin,line))
	{
		if (line.length()==0)
		{
			cout<<endl;
			continue;
		}
		word.clear();
		password(line,word);
		end=false;
		string str(26,'*');
		if (dict.size()>=word.size())
			jiemi(dict,word,0,str);
		shuchu(line,str);
	} 
	return 0;
}
