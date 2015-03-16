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
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		for (j=0;j<n;j++)
		{
			if(i&(1<<j))
			printf("%d ",i^(1<<j));
		}
		cout<<endl;
	}
	return 0;
}
