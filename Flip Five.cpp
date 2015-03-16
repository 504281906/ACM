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
char p[5][5];
struct node{
	int k,t;
	node(int a,int b){k=a,t=b;
	}
};
queue<node> q;
int vis[3000];
int BFS(){
	while (!q.empty()){
		node a=q.front();
		q.pop();
		if (a.k==0) return a.t;
		for (int i=1;i<=3;i++)
			for (int j=1;j<=3;j++){
				int g1=a.k,g2=a.t+1;
				if (i==1){
					if (j==1){
						if (g1 & 1<<1) g1-=1<<1;
						else g1+=1<<1;
						if (g1 & 1<<2) g1-=1<<2;
						else g1+=1<<2;
						if (g1 & 1<<4) g1-=1<<4;
						else g1+=1<<4;
					}
					if (j==2){
						if (g1 & 1<<1) g1-=1<<1;
						else g1+=1<<1;
						if (g1 & 1<<2) g1-=1<<2;
						else g1+=1<<2;
						if (g1 & 1<<3) g1-=1<<3;
						else g1+=1<<3;
						if (g1 & 1<<5) g1-=1<<5;
						else g1+=1<<5;
					}
					if (j==3){
						if (g1 & 1<<3) g1-=1<<3;
						else g1+=1<<3;
						if (g1 & 1<<2) g1-=1<<2;
						else g1+=1<<2;
						if (g1 & 1<<6) g1-=1<<6;
						else g1+=1<<6;
					}
				}
				if (i==2){
					if (j==1){
						if (g1 & 1<<1) g1-=1<<1;
						else g1+=1<<1;
						if (g1 & 1<<5) g1-=1<<5;
						else g1+=1<<5;
						if (g1 & 1<<4) g1-=1<<4;
						else g1+=1<<4;
						if (g1 & 1<<7) g1-=1<<7;
						else g1+=1<<7;
					}
					if (j==2){
						if (g1 & 1<<5) g1-=1<<5;
						else g1+=1<<5;
						if (g1 & 1<<2) g1-=1<<2;
						else g1+=1<<2;
						if (g1 & 1<<4) g1-=1<<4;
						else g1+=1<<4;
						if (g1 & 1<<6) g1-=1<<6;
						else g1+=1<<6;
						if (g1 & 1<<8) g1-=1<<8;
						else g1+=1<<8;
					}
					if (j==3){
						if (g1 & 1<<3) g1-=1<<3;
						else g1+=1<<3;
						if (g1 & 1<<5) g1-=1<<5;
						else g1+=1<<5;
						if (g1 & 1<<6) g1-=1<<6;
						else g1+=1<<6;
						if (g1 & 1<<9) g1-=1<<9;
						else g1+=1<<9;
					}
				}
				if (i==3){
					if (j==1){
						if (g1 & 1<<4) g1-=1<<4;
						else g1+=1<<4;
						if (g1 & 1<<7) g1-=1<<7;
						else g1+=1<<7;
						if (g1 & 1<<8) g1-=1<<8;
						else g1+=1<<8;
					}
					if (j==2){
						if (g1 & 1<<5) g1-=1<<5;
						else g1+=1<<5;
						if (g1 & 1<<7) g1-=1<<7;
						else g1+=1<<7;
						if (g1 & 1<<8) g1-=1<<8;
						else g1+=1<<8;
						if (g1 & 1<<9) g1-=1<<9;
						else g1+=1<<9;
					}
					if (j==3){
						if (g1 & 1<<6) g1-=1<<6;
						else g1+=1<<6;
						if (g1 & 1<<8) g1-=1<<8;
						else g1+=1<<8;
						if (g1 & 1<<9) g1-=1<<9;
						else g1+=1<<9;
					}
				}
				if (vis[g1]==0) q.push(node(g1,g2));
			}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	while (T--){
		memset(vis,0,sizeof(vis));
		gets(p[1]+1);
		gets(p[2]+1);
		gets(p[3]+1);
		int s=0;
		while (!q.empty()) q.pop();
		for (int i=1;i<=3;i++)
			for (int j=1;j<=3;j++)
				 	if (p[i][j]=='*')
						s+=1<<((i-1)*3+j);
		vis[s]=1;
		q.push(node(s,0));
		cout<<BFS()<<endl;
	}
	return 0;
}
