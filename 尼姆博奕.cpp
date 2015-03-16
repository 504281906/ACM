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
using namespace std;
int main()
{
	int q,w,e,k;
	while (~scanf("%d%d%d",&q,&w,&e))
	{
		if (q>e)
		{
			q=q+e;
			e=q-e;
			q=q-e;
		}
		if (w>e)
		{
			w=w+e;
			e=w-e;
			w=w-e;
		}
		int k=q ^ w ^ e;
		if (!k) printf("Yes\n");
		else printf("%d\n",e-(q^w)); //如果不是必输局，则从e从拿走(q^w)则必赢 
	}
	return 0;
}

