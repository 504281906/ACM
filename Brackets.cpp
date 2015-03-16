#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
struct node
{
	char c;
	int id;
};
bool ff(char a,char b)
{
	if ( (a=='(' && b==')') || (a=='[' && b==']'))
		return 1;
	else return 0;
}
int main()
{
	stack <node>p;
	while (gets(s))
	{
		memset(a,0,sizeof(a));
		while (!p.empty()) p.pop();
		getchar();
		int l=strlen(s);
		for (i=0;i<l;i++)
		{
			if (p.empty || !(ff(s[i],p.top())))
				p.push(node(s[i],i));
			else
			{
				a[i]=1;
				a[p.top().id]=1;
				p.pop();
			}
		}
	}
}
