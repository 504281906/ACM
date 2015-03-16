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
int m[20][20];
int find(int x,int y,int z){
	int x1,x2,y1,y2,i;
	for (i=1;i<=9;i++){
		if (m[x][i]==z) return 0;
		if (m[i][y]==z) return 0;
	}
	if (x%3==1){
		x1=x+1;
		x2=x+2;
	}
	if (x%3==2){
		x1=x-1;
		x2=x+1;
	}
	if (x%3==0){
		x1=x-2;
		x2=x-1;
	}
	if (y%3==1){
		y1=y+1;
		y2=y+2;
	}
	if (y%3==2){
		y1=y-1;
		y2=y+1;
	}
	if (y%3==0){
		y1=y-2;
		y2=y-1;
	}
	if (m[x1][y1]==z||m[x1][y2]==z||m[x2][y1]==z||m[x2][y2]==z) return 0;
	return 1;
}
int DFS(int x,int y,int gg){
	int x1,y1,i;
	if (gg) return gg;
	if (x==9 && y==9){
		if (m[9][9]) return gg=1;
		for (i=1;i<=9;i++){
			if (find(9,9,i)){
				m[9][9]=i;
				return gg=1;
			}
		}
		return 0;
	}
	if (m[x][y]){
		x1=x;
		y1=y+1;
		if (y1>9){
			x1=x+1;
			y1=1;
		}
		gg=DFS(x1,y1,gg);
	}
	else{
		for (i=1;i<=9;i++){
			int flag=0;
			if (find(x,y,i)){
				flag=1;
				m[x][y]=i;
			}
			if (flag){
				x1=x;
				y1=y+1;
				if (y1>9){
					x1=x+1;
					y1=1;
				}
				gg=DFS(x1,y1,gg);
				if (!gg) m[x][y]=0;
			}
		}
	}
	return gg;
}
int main(){
	int n,i,x,y,z,j;
	printf("请输入已知的数有多少个n,然后分别给出每个数的位置(x,y,z),z表示这个数\n");
	scanf("%d",&n);
	memset(m,0,sizeof(m));
	for (i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		m[x][y]=z;
	}
	int gg=DFS(1,1,0);
	if (gg){
		for (i=1;i<=9;i++){
			for (j=1;j<=9;j++)
				printf("%d ",m[i][j]);
			printf("\n");
		}
	}
	return 0;
}
