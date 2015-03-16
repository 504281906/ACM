#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
stack <char> in,out;
int main()
{
	char a[100],b[100];
	int n;
	int c[100];
	while (~scanf("%d%s%s",&n,&a,&b))
	{
		int f=0;
		memset(c,0,sizeof(c));
		while (!in.empty())
			in.pop();
		while (!out.empty())
			out.pop();
		for (int i=n-1;i>=0;i--)
			out.push(b[i]);
		for (int i=0;i<n;i++)
		{
			in.push(a[i]);
			f++;
			while (!in.empty() && !out.empty() && in.top()==out.top())
			{
				in.pop();
				out.pop();
				c[++f]=1;
			}
		}
		if (out.empty())
		{
			printf("Yes.\n");
			for (int i=1;i<=f;i++)
			if (c[i]) printf("out\n");
			else printf("in\n");
		}
		else printf("No.\n");
		printf("FINISH\n"); 
	}
	return 0;
}
