#include <stdio.h>
#include <queue>
#include <stack> 
using namespace std;
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		queue<int> que;
		priority_queue<int> pque;
		stack<int> tack;
		int k1=1,k2=1,k3=1;
		while (n--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if (a==1)
			{
				que.push(b);
				pque.push(b);
				tack.push(b);
			}
			else 
			{
				if (!que.empty() && k1)
				{
					if (que.front()!=b)
						k1=0;
					que.pop(); 
				}
				else k1=0;
				if (!pque.empty() && k2)
				{
					if (pque.top()!=b)
						k2=0;
					pque.pop(); 
				}
				else k2=0;
				if (!tack.empty() && k3)
				{
					if (tack.top()!=b)
						k3=0;
					tack.pop(); 
				}
				else k3=0;
			}
		}
		if ((k1+k2+k3)>1) printf("not sure\n");
		else if ((k1+k2+k3)==0) printf("impossible\n");
		else if (k1==1) printf("queue\n");
		else if (k2==1) printf("priority queue\n");
		else printf("stack\n");
	} 
	return 0;
} 
