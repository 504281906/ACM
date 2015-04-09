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
	printf("\t\t���̵��ȹ���ϵͳ֮ʱ��Ƭ���㷨�Ͷ̽��������㷨\n");
	printf("�����������Ŀ:\n");
	scanf("%d",&n);
	printf("������ÿ�����̵Ľ�����(��һ��Ӣ����ĸ����)������ϵͳʱ�䣬����ʱ��:\n");
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
	printf("��������Ҫѡ����㷨��1��ʾʱ��Ƭת�ַ���2��ʾ�̽������ȷ�.3�˳�ϵͳ):");
	scanf("%d",&qwer);
	if (qwer==1)
	{
	printf("������ʱ��Ƭ��С��");
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
			printf("����%c�Ѿ����\n",ac.name);
			flag++;
			if (flag==1) ans=ac.intime;
			ans+=ac.runtime-ac.dotime;  
			printf("��ǰϵͳ������ʱ��%d\n",ans);
		}
		else{
			ac.dotime+=gg;
			ans+=gg;
			qq.push(ac);
			printf("����%c��δ���,�����%d\n",ac.name,ac.dotime);
			printf("��ǰϵͳ������ʱ��%d\n",ans);
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
	printf("ʱ��ת��Ƭ�㷨ϵͳ����ʱ��Ϊ��%d\n",ans);
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
	cout<<"��̽�������ϵͳ������ʱ�䣺"<<time<<endl; 
	cout<<"��������������У�"; 
	for (i=0;i<n;i++){
		printf("%c\t",p[a[i].id].name);
	}
	cout<<endl;
	cout<<"���������תʱ�䣺";
	int ans=0;
	for (i=0;i<n;i++){
		printf("%d\t",a[i].time);
		ans+=a[i].time;
	}
	cout<<endl;
	printf("ƽ����תʱ�䣺%lf\n",ans*1.0/n);
	}else break;
	}
	return 0;
}
