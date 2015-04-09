#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct sqlist
{
	int *elem;
	int length;
	int listsize;
};
void Init(sqlist &s1)
{
	s1.elem=new int[100];
	memset(s1.elem,0,sizeof(int)*100);
	s1.length=0;
	s1.listsize=100;
	return;
}
//将元素e插入i位置
void insert(sqlist &s1,int e,int i)
{
	if (i>s1.listsize)
	{
		printf("插入位置超过限制\n");
		return; 
	}
	else
	{
	if (s1.length==s1.listsize)
	{
		s1.elem=new int[s1.listsize+10];
		for (int j=s1.listsize;j<s1.listsize+10;j++)
			s1.elem[j]=0;
		s1.listsize+=10;
		s1.elem[i]=e;
	}
	if (s1.length<s1.listsize)
	{
		if (i>s1.length)
			s1.elem[i]=e;
		else
		{
			for (int j=s1.length;j>=i;j--)
				s1.elem[j+1]=s1.elem[j];
			s1.elem[i]=e; 
		} 
	}
	s1.length++;
	}
	return;
}
void free(sqlist &s1)
{
	delete []s1.elem;
}
int main()
{	
	sqlist s;
	Init(s);
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		insert(s,a,i);
	}
	for (int i=0;i<s.length;i++)
		printf("%d ",s.elem[i]);
	free(s);
	return 0;
}

