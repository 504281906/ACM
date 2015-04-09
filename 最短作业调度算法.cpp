#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
	char name;
	int intime;
	int runtime;
	int dotime;
	int id;
	bool operator <(const node a)const {
		return a.runtime<runtime;
	}
}p[1000];
struct node1{
	int id;
	int time;
}a[1000];
int main(){
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	int n,i,j;
	printf("\t\t进程调度管理系统之时间片轮算法和短进程优先算法\n");
	printf("请输入进程数目:\n");
	scanf("%d",&n);
	printf("请输入每个进程的进程名(用一个英文字母代替)，进入系统时间，工作时间:\n");
	for (i=0;i<n;i++){
		getchar();
		scanf("%c %d %d",&p[i].name,&p[i].intime,&p[i].runtime);
		p[i].id=i;
	}
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			if (p[i].intime>p[j].intime){
				node t=p[i];
				p[i]=p[j];
				p[j]=t;
				int tt=p[i].id;
				p[i].id=p[j].id;
				p[j].id=tt;
			}
	int qwer;
	while (1){
	printf("请输入你要选择的算法（1表示时间片转轮法，2表示短进程优先法.3退出系统):");
	scanf("%d",&qwer);
	if (qwer==1)
	{
	printf("请输入时间片大小：");
	int gg;
	scanf("%d",&gg);
	queue<node>qq;
	int flag=0;
	int ans=0;
	int c=0;
	while (flag<n){
		if (!qq.empty()){ 
		node ac=qq.front();
		qq.pop();
		if (ac.dotime+gg>=ac.runtime){
			printf("进程%c已经完成\n",ac.name);
			flag++;
			if (flag==1) ans=ac.intime;
			ans+=ac.runtime-ac.dotime;  
			printf("当前系统已运行时间%d\n",ans);
		}
		else{
			ac.dotime+=gg;
			ans+=gg;
			qq.push(ac);
			printf("进程%c尚未完成,已完成%d\n",ac.name,ac.dotime);
			printf("当前系统已运行时间%d\n",ans);
		}
		}
		if (c<n){
			int tt=c;
			for (i=tt;i<n;i++){
				if (p[i].intime>ans) break;
				else {
					qq.push(p[i]); 
					c++;
				}
			}
			if (qq.empty()){
				qq.push(p[c++]);
			}
		}
	}
	printf("时间转轮片算法系统总用时间为：%d\n",ans);
	}else if (qwer==2){
	int k=1;
	priority_queue<node>q;
	//q.clear();
	q.push(p[0]);
	int time=p[0].intime;
	int num=0;
	while (!q.empty()){
		node nowp=q.top();
		q.pop();
		time+=nowp.runtime;
		a[num].time=time-nowp.intime;
		a[num++].id=nowp.id;
		for (i=k;i<n;i++){
			if (p[i].intime<=time)
				q.push(p[i]);
			else break;
		}
		k=i;
		if (q.empty() && k<n){
			q.push(p[k]);
			k++;
		}
	}
	cout<<"最短进程优先系统工作总时间："<<time<<endl; 
	cout<<"输出进程优先序列："; 
	for (i=0;i<n;i++){
		printf("%c\t",p[a[i].id].name);
	}
	cout<<endl;
	cout<<"输出进程周转时间：";
	int ans=0;
	for (i=0;i<n;i++){
		printf("%d\t",a[i].time);
		ans+=a[i].time;
	}
	cout<<endl;
	printf("平均周转时间：%lf\n",ans*1.0/n);
	}else break;
	}
	return 0;
}
