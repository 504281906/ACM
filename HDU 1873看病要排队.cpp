#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
	int d,s;
	node (int a,int b):d(a),s(b){}
	bool operator <(const node a) const
	{
		if (s!=a.s) return s<a.s;
		else return d>a.d;
	}
};
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		priority_queue <node> q[5];
		int t=1;
		while (n--)
		{
			char c[5];
			int a,b;
			getchar();
			scanf("%s",&c);
			if (c[0]=='I')
			{
				scanf("%d%d",&a,&b);
				//q[a].d=t++;
				//q[a].s=b;
				q[a].push(node(t++,b));
			}
			else if (c[0]=='O')
			{
				scanf("%d",&a);
				if (q[a].empty()) printf("EMPTY\n");
				else
				{
					node k=q[a].top();
					q[a].pop();
					printf("%d\n",k.d);
				}
			}
		}
	}
	return 0;
}
