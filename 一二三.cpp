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
string a="one",b="two",c="three";
int main()
{
	int T; 
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		string s;
		cin>>s;
		if (s.length()==5) cout<<3<<endl;
		else
		{
			int f=0;
			for (int i=0;i<3;i++)
				if (s[i]!=a[i]) f++;
			if (f<=1) cout<<1<<endl;
			else cout<<2<<endl;
		}
	}
	return 0;
}

