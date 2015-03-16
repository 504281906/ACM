#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#define LL __int64
#define EPS 1e-8
using namespace std;
char s[30];
int begin,end,flag;
void ff(int f,int k)
{
	if (k==f) 
	{
		s[k]--;
		if (f==0 && s[f]=='0') begin++;
		if (flag && f!=0) begin--;
		return ;
	}
	if (s[k-1]=='0')
	{
		k--;
		s[k]='9';
		ff(f,k);
	}
	else 
	{
		s[k-1]--;
		if (flag && f!=0 && k-1==f) begin--;
		if (f==0 && s[f]=='0') begin++;
		return;
	}
}
int main()
{
	int T,l;
	long long pp;
	//freopen("in.txt","r",stdin);
	//freopen("out1.txt","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld",&pp);
		if (pp==1) {cout<<0<<endl;continue;}
		pp--;
		sprintf(s,"%lld",pp);
		l=strlen(s)-1;
		if (l==1 && s[0]=='1' && s[1]=='0') 
		{
			cout<<9<<endl;
			continue;
		}
		begin=0;
		end=l;
		while (begin<end)
		{
			flag=0;
			int fk=1;
			while (s[begin+1]==s[begin] && begin<end) 
			{
				begin++;
				flag=1;
			}
			while (end!=l && s[begin]==s[end+1])
				begin++;
			if (begin>=end) break;
			if (s[begin]<=s[end] || end-begin>=1)
			{
				if (s[begin]>s[end])    //◊¢“‚¡„∞°£°£°£°
				{
					if (end!=l && end-begin<=1)
					{ 
						s[end]=s[end+1];
						fk=0;
					}
					else
					{
						int it=end;
						ff(begin,it);
						if (begin!=0 && s[begin]==s[end+1])
						{
							s[end]='9';
							begin++;
						}
						else
							s[end]=s[begin];
					}
				}
				else
				{
					if (end-begin==1 && end!=l && s[end]>s[end+1])
						s[end]=max(s[begin],s[end+1]);
					else
					if (end!=l && s[end]>=s[end+1] && s[begin]==s[end-1])
					{
						fk=0;
						s[end]=s[end+1];
					}
					else s[end]=s[begin];
				}
				if (begin+1==end) break;
				if (fk) begin++;
				end--;
			}
			else begin++;
		}
		begin=0;
		while (s[begin]=='0') begin++;
		for (int i=begin;i<=l;i++)
			printf("%c",s[i]);
		cout<<endl;
	}
	return 0;
}
//1231212
