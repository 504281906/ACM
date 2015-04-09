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
	int n;
	while (~scanf("%d",&n) && n)
	{
		int f=0;
		while (n)
		{
			if (n % 2==0) 
			{
				f=1;
				break;	
			}
			n/=2;
		}
		if (f==0) cout<<"Bob"<<endl;
		else cout<<"Alice"<<endl; 
	} 
	return 0;
}

