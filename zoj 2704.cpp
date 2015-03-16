#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
struct node
{
	char c;
	int id;
	node(char a,int b):c(a),id(b){
	}
};
bool ff(char a,char b)
{
	if ( (a=='(' && b==')') || (a=='[' && b==']'))
		return 1;
	else return 0;
}
char s[100010];
int a[100010];
int main()
{
	int i;
	stack <node>p;
	while (gets(s))
	{
		memset(a,0,sizeof(a));
		while (!p.empty()) p.pop();
		int l=strlen(s);
		for (i=0;i<l;i++)
		{
			if ((p.empty()) || ( !ff(p.top().c,s[i]) ) )
				p.push(node(s[i],i));
			else
			{
				a[i]=1;
				a[p.top().id]=1;
				p.pop();
			}
		}
		i=0;int z=0,y=0,max=0;
		while (i<l)
		{
			int k=0;
			while (a[i] && i<l)
			{
				k++;
				i++;
			}
			if (max<k)
			{
				max=k;
				y=i-1;
				z=i-k;
			}
			i++;
		}
		if (max)
		for (i=z;i<=y;i++)
			printf("%c",s[i]);
		printf("\n\n");
		getchar();
	}
	return 0;
}
