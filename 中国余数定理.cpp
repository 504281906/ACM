#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// �ҳ���k����3��5��7����ʱ������Ϊ2��3��2����
int main()
{
	long long s=0;
	int i;
	for (i=1;;i++)
		if (15*i % 7==1)
		{
			s+=15*i*2;
			break;
		}
	for (i=1;;i++)
		if (21*i % 5==1)
		{
			s+=21*i*3;
			break;
		}
	for (i=1;;i++)
		if (35*i % 3==1)
		{
			s+=35*i*2;
			break;
		}
	s=s % (3*5*7);
	long long k;
	while (~scanf("%lld",&k))
		printf("%lld\n",(k-1)*105+s);
	return 0;
}
