#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
//lower_bound������ȡ��(a,a+n)���ش��ڻ����val�ĵ�һ��Ԫ�ص�λ�ã�a������
//����ġ��������Ԫ�ض�С��val���򷵻�a+n��λ�á� 
int main()
{
	int n,i,m,a[100];
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	while (~scanf("%d",&m))
	{
		int k=lower_bound(a,a+n,m)-a;
		printf("%d\n",k);
	}
	return 0;
}
