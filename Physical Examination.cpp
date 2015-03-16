#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef __int64 LL;
const int max_n = 100010;

struct node
{
	LL a, b;
	bool operator < (const node tmp) const
	{
		return 1.*a/b < 1.*tmp.a/tmp.b;
	}
}que[max_n];

int main ()
{
	int n;
	while (~scanf ("%d", &n), n)
	{
		for (int i = 0; i < n; i ++)
		{
			scanf ("%I64d%I64d", &que[i].a, &que[i].b);
		}
		sort (que, que+n);
	/*	for (int i = 0; i < n; i ++)
		{
			printf ("%I64d %I64d\n",que[i].a, que[i].b);
		}	*/	
		LL ans = 0;
		LL tmp = 0;
		for (int i = 0; i < n; i ++)
		{
			tmp = que[i].a + ans * que[i].b;
	//		cout << tmp << endl;
			ans = (ans+tmp)%31536000;
		}
		printf ("%I64d\n", ans);
	}
}
