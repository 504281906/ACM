#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list> 
using namespace std;
typedef struct node 
{
	int key;
	int n;
	struct node *next;
}*List,L;
List l;
int main()
{
	int b[1000];
	int n,i,m;
	printf("������������");
	scanf("%d",&n);
	printf("������ÿ���˵����룺");
	l=new node;
	List head;
	head=new node;
	for (i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		if (i==1) 
		{
			l=head;
			l->key=k;
			l->n=1;
			l->next=head;
		}
		else 
		{
			L *p;
			p=new node;
			p->n=i;
			p->key=k;
			p->next=l->next;
			l->next=p;
			l=p;
		}
	}
	printf("�����뵱ǰ���룺");
	scanf("%d",&m); 
	List lf=l; //lf����ǰ�ڵ��ǰһ�� 
	l=head;
	int k=n;
	while (k)
	{
		int t=1;
		while (t!=m)
		{
			lf=l;
			l=l->next;
			t++;
		}
		b[n-k]=l->n;
		k--;
		m=l->key;
		printf("��ǰ�������ǣ�%d�� ��ǰ�����ǣ�%d\n",l->n,m);
		system("pause");
		lf->next=l->next;
		l=lf->next;
	}
	printf("�������ǳ���˳��");
	for (i=0;i<n;i++)
		printf("%d ",b[i]);
	cout<<endl;
	return 0;
}
