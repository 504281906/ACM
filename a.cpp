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
int main(){
	int i,j,a[15][15],n;
	for (i=1;i<=10;i++){
		a[1][i]=1;
		a[i][1]=1;
	}
	for (i=2;i<=10;i++)
		for (j=2;j<=10;j++)
			a[i][j]=a[i-1][j]+a[i][j-1];
	scanf("%d",&n);
	printf("%d\n",a[n][n]);
	return 0;
}
