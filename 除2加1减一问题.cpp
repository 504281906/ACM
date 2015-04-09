//题目：给定一个数，如果是奇数就+1或者-1，偶数就/2.直到这个数变成1结束，问最小步数。
#include <iostream>
#include <cstdio>
using namespace std;
int k;
int gogogo(int n,int k)
{
	if (n==1) return k;
	if (n % 2==0)
		return gogogo(n/2,k+1);
	else
	{
		if (n==3) return k+2;
		if (n & 2) return gogogo(n+1,k+1);
		else return gogogo(n-1,k+1);
	}
} 
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		printf("%d\n",gogogo(n,0));
	}
	return 0;
} 
