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
struct point
{
	int l,r;
};
int s[100];
point p[100];
int main()
{
	int n,i,j;
	while (~scanf("%d",&n) && n){
		for (i=1;i<=n;i++){
			scanf("%d",&s[i]);
			/*if (i==1) b[1]=sqrt(2.0)/2*s[1];
			else if (s[i]>=s[i-1])
				b[i]=b[i-1]+sqrt(2.0)*s[i-1];
			else 
				b[i]=b[i-1]+sqrt(2.0)*s[i];*/
			p[i].l=0;
			for (j=1;j<i;j++){
				if (s[i]>=s[j]) p[i].l=max(p[i].l,p[j].l+3*s[j]-s[i]);
				else p[i].l=max(p[i].l,p[j].l+s[j]+s[i]);
			}
			p[i].r=p[i].l+2*s[i];
		}
		for (i=2;i<=n;i++)
			for (j=1;j<i;j++){
				if (s[j]<s[i] && p[j].r>p[i].l)
					p[j].r=p[i].l;
				if (s[j]>s[i] && p[j].r>p[i].l)
					p[i].l=p[j].r;
			}
		for (i=1;i<=n;i++)
			if (p[i].l<p[i].r)
				printf("%d ",i);
		cout<<endl;
	}
	return 0;
}
