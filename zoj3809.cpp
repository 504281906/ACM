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
#define eps 1e-8
using namespace std;
int main()
{
	int n,T,a[100];
	scanf("%d",&T);
	while (T--)
	{	
		scanf("%d",&n);
		int ans=0;
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for (int i=2;i<n;i++)
			ans+=(a[i]>a[i-1])&&(a[i]>a[i+1]);
		cout<<ans<<endl;
	}
	return 0;
}

