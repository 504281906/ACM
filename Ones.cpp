#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		int k=1,m=n,t=1;
		while (k)
		{
			while (k<n) 
			{
				k=k*10+1;
				t++;
			}
			k=k % m; 
		}
		cout<<t<<endl;
	}
	return 0;
}

