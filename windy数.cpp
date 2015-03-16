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
int dp[15][15];
void INIT(){
	memset(dp,0,sizeof(dp));
	for (int i=0;i<10;i++)
		dp[1][i]=1;
	for (int i=2;i<=10;i++)
		for (int j=0;j<10;j++)
			for (int k=0;k<10;k++)
				if (abs(j-k)>=2)
					dp[i][j]+=dp[i-1][k];
}
int go(int x){
	int b[15],t=0;
	while (x){
		b[++t]=x%10;
		x/=10;
	}
	b[t+1]=0;
	int ans=0;
	for (int i=1;i<t;i++)
		for (int j=1;j<10;j++)
			ans+=dp[i][j];
	for (int i=1;i<b[t];i++)
		ans+=dp[t][i];
	for (int i=t-1;i>0;i--){
		for (int j=0;j<b[i];j++)
			if (abs(j-b[i+1])>=2)
				ans+=dp[i][j];
		if (abs(b[i]-b[i+1])<2) break;
	}
	return ans;
}
int main(){
	INIT();
	int a,b;
	while(~scanf("%d%d",&a,&b))
		printf("%d\n",go(b+1)-go(a));
	return 0;
}
