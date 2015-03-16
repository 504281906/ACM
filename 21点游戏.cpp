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
LL s;
FILE *f;
void go(int &a,string &b){
	if (a>=10){
		if (a==10) b="10";
		if (a==11) b="J";
		if (a==12) b="Q";
		if (a==13) b="K";
		a=10;
	}
	else
		b='0'+a;
}
int a[30],b[30];
string a1[30],b1[30];
int main(){
	printf("\t\t欢迎来到21点游戏\n");
	freopen("21点游戏.txt","rw",stdin);
	scanf("%lld",&s);
	freopen("CON","r",stdin); //"CON"代表控制台
	if (s==0){
		s=1000;
		printf("真遗憾,您的金币数量为零无法进行游戏,不过大方的Modiz赠送您1000金币！\n(后续请联系QQ504281906自行充值)\n");
	}
	printf("您目前的金币数量是:%lld\n",s);
	system("pause");
	do{
		printf("亲，我们的规矩是每把100金币哦~");
		printf("开始游戏，进行第一次发牌...\n");
		system("pause");
		srand(time(NULL));
		a[0]=rand()%13+1;
		a[1]=rand()%13+1;
		b[0]=rand()%13+1;
		b[1]=rand()%13+1;
		go(a[0],a1[0]);
		go(a[1],a1[1]);
		go(b[0],b1[0]);
		go(b[1],b1[1]);
		int s1=0,s2=0;
		printf("显示电脑的底牌（第一张不显示为*）:");
		cout<<"*"<<" "<<a1[1]<<endl;
		s1+=a[0]+a[1];
		printf("您的底牌是：");
		cout<<b1[0]<<" "<<b1[1]<<endl;
		s2+=b[0]+b[1];
		int t1=2,t2=2;
		while (1){
			printf("请输入您是否要牌（1表示要牌，0表示不要牌，其他输入无效）：");
			string k;
			cin>>k;
			if (k=="1"){
				
			}
		}
	}while(0);
	return 0;
}
