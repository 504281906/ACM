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
	printf("\t\t��ӭ����21����Ϸ\n");
	freopen("21����Ϸ.txt","rw",stdin);
	scanf("%lld",&s);
	freopen("CON","r",stdin); //"CON"�������̨
	if (s==0){
		s=1000;
		printf("���ź�,���Ľ������Ϊ���޷�������Ϸ,�����󷽵�Modiz������1000��ң�\n(��������ϵQQ504281906���г�ֵ)\n");
	}
	printf("��Ŀǰ�Ľ��������:%lld\n",s);
	system("pause");
	do{
		printf("�ף����ǵĹ����ÿ��100���Ŷ~");
		printf("��ʼ��Ϸ�����е�һ�η���...\n");
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
		printf("��ʾ���Եĵ��ƣ���һ�Ų���ʾΪ*��:");
		cout<<"*"<<" "<<a1[1]<<endl;
		s1+=a[0]+a[1];
		printf("���ĵ����ǣ�");
		cout<<b1[0]<<" "<<b1[1]<<endl;
		s2+=b[0]+b[1];
		int t1=2,t2=2;
		while (1){
			printf("���������Ƿ�Ҫ�ƣ�1��ʾҪ�ƣ�0��ʾ��Ҫ�ƣ�����������Ч����");
			string k;
			cin>>k;
			if (k=="1"){
				
			}
		}
	}while(0);
	return 0;
}
