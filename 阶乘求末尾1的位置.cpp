/*
���������N!��2�ĸ�������Ϊÿ����һ��2���������� 
���λ��1��0���������1�����λ��λ�ü�ΪN!��2�ĸ���+1�� 
*/
#include <cstdio>
int lowestOnePos(int n) 
{ 
	int ret = 0; //ͳ��n!�к���������2�ĸ���
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

