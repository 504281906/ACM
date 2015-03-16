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
#define LL __int64
#define EPS 1e-8
using namespace std;
struct node
{
	LL s,k,p;
	node (LL a,LL b,LL c):s(a),k(b),p(c){}
};
int main()
{
	
	LL a,b,s;
	while(1)
	{queue<node>q;
	scanf("%I64d%I64d%I64d",&a,&b,&s);
	if (a==0 || b==0)
	{
		if (a==0 && b==0) 
			if (s!=0) puts("NO");
			else puts("YES");
		else
		{
			if (a==0) 
				if (s%b==0 || s==0) puts("YES");
				else puts("NO");
			else if (s%a==0 || s==0) puts("YES");
				else puts("NO");
		}
		return 0;
	}
	q.push(node(s,a,b));
	q.push(node(s,b,a));
	int flag=0;
	while (!q.empty())
	{
		node f=q.front();
		q.pop();
		if ( (f.s>=f.k && (f.s-f.k)%f.p==0) || (f.s>=f.p && (f.s-f.p)%f.k==0)) 
		{
			flag=1;
			cout<<f.s<<" "<<f.k<<" "<<f.p<<endl;
			break;
		}
		if (f.s<f.k || f.s<f.p) continue;
		q.push(node(f.s-f.k,f.k+f.p,f.k));
	}
	if (flag) puts("YES");
	else puts("NO");
}
	return 0;
}
