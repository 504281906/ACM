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
#include <ctime>
#define LL __int64
#define EPS 1e-8
using namespace std;
int main()
{
	int ans=1;
	for (int i=1;i<=43200;i++)
	{
		if (i%120==0&&(i/120)%360==(i/10)%360)
		{
			ans++;
			cout<<i<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}

