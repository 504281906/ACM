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
//#define DEBUG
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int n,i;
	char s[55];
	scanf("%d",&n);
	getchar();
	scanf("%s",&s);
	stack<int>t;
	for (i=strlen(s)-1;i>=0;i--)
	{
		if (s[i]=='R') t.push(1);
		else t.push(0);
	}
	int k=0;
	__int64 f=0;
	while (1)
	{
		while(!t.empty()&&t.top())
		{
			t.pop();
			k++;
		}
		if (t.empty()) break;
		f++;
		t.pop();
		t.push(1); 
		while (k--)
			t.push(0);
		k=0;
	}
	printf("%I64d\n",f);
	return 0;
}
