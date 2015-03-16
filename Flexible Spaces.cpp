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
#define pi acos(-1)
using namespace std;
int a[200],b[200],n,m,i,j;
int main(){
	while (~scanf("%d%d",&n,&m)){
		a[0]=0;
		a[m+1]=n;
		for (i=1;i<=m;i++)
			scanf("%d",&a[i]);
		memset(b,0,sizeof(b));
		for (i=0;i<=m;i++)
			for (j=i+1;j<=m+1;j++)
				b[a[j]-a[i]]=1;
		for (i=1;i<n;i++)
			if (b[i]) printf("%d ",i);
		cout<<n<<endl; 
	}
	return 0;
}
