/*
可以先求出N!中2的个数（因为每存在一个2，则在数的 
最低位多1个0）。因此求1的最低位的位置即为N!中2的个数+1； 
*/
#include <cstdio>
int lowestOnePos(int n) 
{ 
	int ret = 0; //统计n!中含有质因数2的个数
	while(n)
	{ 
		n >>= 1; 
		ret += n; 
	}
	return ret+1;
}
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		printf("%d\n",lowestOnePos(n));
	}
}

