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
#define LL __int64
#define EPS 1e-8
using namespace std;
int Scan()
{
	int flag=0,ret=0,c;
	if ((c=getchar())=='-')
		flag=1;
	else if (c>='0' && c<='9')
		ret=c-'0';
	while ((c=getchar())>='0' && c<='9')
		ret=ret*10+(c-'0');
	return flag?-ret:ret;
}
int main()
{
	int a=Scan(); 
	cout<<a<<endl;
	return 0;
}
//˼·�ܼ򵥣�
//��һ�������жϵ�ǰ�ַ��ǲ���'-'�ţ�����ǣ�
//flag���Ϊ1����ʾ�������Ǹ����������������ַ������֣���ȡ�������֡�
//�ڶ������õ�����������ֻҪ�����������֣���һֱ�۳ˡ�
//������������flag��ֵ���ظ�������ֵ
