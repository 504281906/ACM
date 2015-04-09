#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int y,m,r,i,t=0,t1=0;
	printf("\t\t\t下面神算子周大师给你免费算上一卦\n");
	printf("\t\t\t请输入您的出生年月日（例如：1993 10 1）\n");
	while (~scanf("%d%d%d",&y,&m,&r))
	{
		t=0,t1=0;
	for (i=y+1;i<2013;i++)
	{
		if ( ( i % 400 ==0 ) || ((i % 4==0) && (i % 100 !=0)))
			t++;
		else t1++;
	}
	int s=r;
	for (i=1;i<m;i++)
		s+=a[i];
	s=365-s;
	s+=t*366;
	s+=t1*365;
	s+=301;
	printf("您已经蹦跶了%d天\n",s);
	}
	return 0;
}
