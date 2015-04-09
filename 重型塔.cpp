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
#define mod 1000000007
int js(int m,int n,int t) //m为行，n为列，t为还剩下t个重型塔
{
	if (t==1) return m*n;
	return (m*n*js(m-1,n-1,t-1) % mod)+(m*n*(n-1)/2*js(m-1,n-2,t-2) % mod)+(n*m*(m-1)/2*js(m-2,n-1,t-2) % mod);	
}
int main()
{
	printf("%d\n",mod);
	return 0;
}

