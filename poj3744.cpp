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
struct Matrix{
	double go[2][2];
	Matrix operator *(const Matrix a){
		Matrix res;
		memset(res.go,0,sizeof(res.go));
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				for (int k=0;k<2;k++)
					res.go[i][j]+=go[i][k]*a.go[k][j];
		return res;
	}
};
Matrix KSM(Matrix a,int k){
	Matrix res;
	memset(res.go,0,sizeof(res.go));
	for (int i=0;i<2;i++)
		res.go[i][i]=1;
	Matrix temp=a;
	while (k){
		if (k&1) res=res*temp;
		temp=temp*temp;
		k>>=1;
	}
	return res;
}
int a[20];
int main(){
	int n;
	double p;
	while (~scanf("%d%lf",&n,&p)){
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		Matrix t;
		t.go[0][0]=p;
		t.go[0][1]=1-p;
		t.go[1][0]=1;
		t.go[1][1]=0;
		double ans=1;
		for (int i=0;i<n;i++){
			Matrix temp;
			if (i==0)
				temp=KSM(t,a[0]-1);
			else 
				temp=KSM(t,a[i]-a[i-1]-1);
			ans*=(1-temp.go[0][0]);
		}
		printf("%.7f\n",ans);
	}
	return 0;
}
