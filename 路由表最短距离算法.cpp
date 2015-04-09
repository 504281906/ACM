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
#define Max 1000
using namespace std;
struct node{
	int u,v,c;
}edge[1000];
int dis[1000],pre[1000];
int dian,bian,start;
void ford(){
	int i,j;
	for (i=1;i<=dian;i++)
		if (i!=start) dis[i]=Max;
		else dis[i]=0;
	for (i=1;i<=dian-1;i++)
		for (j=1;j<=bian;j++)
			if (dis[edge[j].v]>dis[edge[j].u]+edge[j].c){
				dis[edge[j].v]=dis[edge[j].u]+edge[j].c;
				pre[edge[j].v]=edge[j].u;
			}
}
void proot(int root) {
	while(root!=pre[root]){
		printf("%d-->",root);
		root=pre[root];
	}
	if(root==pre[root])
		printf("%d\n",root);
}
int main(){
	int i;
	printf("\t��ֱ�����·�����ĸ���������·�����ıߵĸ�������ʼ·������λ��\n");
	scanf("%d%d%d",&dian,&bian,&start);
	pre[start]=start;
	printf("����������ÿ���ߵ���ʼ·������ţ��յ�·������ţ������߾���(���벻�ܳ���16)\n");
	for (i=1;i<=bian;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].c);
	ford();
	for (i=1;i<=dian;i++){
		if (dis[i]==Max) printf("���Ϊ%d��·��������ʼ·������ͨ\n",i);
		else{
			printf("���Ϊ%d��·��������ʼ·��������̾�����:%d",i,dis[i]);
			printf("·��Ϊ:");
			proot(i);
		}
	}
	return 0;
}
