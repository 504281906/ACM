#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ling 1e-8
struct node
{
	__int64 x,y;
}a[10];
int main()
{
//	freopen("out.txt","w",stdout);
	int t=8;
	a[10].x=6;a[10].y=8;
a[9].x=35;a[9].y=49;
a[8].x=204;a[8].y=288;
a[7].x=1189;a[7].y=1681;
a[6].x=6930;a[6].y=9800;
a[5].x=40391;a[5].y=57121;
a[4].x=235416;a[4].y=332928;
a[3].x=1372105;a[3].y=1940449;
a[2].x=7997214;a[2].y=11309768;
a[1].x=46611179;a[1].y=65918161;
/*	__int64 k=200;
	while (t)
	{
		double s=8*k*k+1;
		if (sqrt(s)-(int)(sqrt(s))<=ling)
		{
		s=sqrt(s)-1;
		double s1;
		s1=s/2;
		if (s1-(int)s1<=ling && (int)s1>k)
		{
			a[t].x=k;
			a[t].y=(__int64)s1++;
			t--;
		}
		}
		k++;
	}
	for (int i=10;i>0;i--)
		printf("a[%d].x=%I64d;a[%d].y=%I64d;\n",i,a[i].x,i,a[i].y);*/
	for (int i=10;i>0;i--)
		printf("%10I64d%10I64d\n",a[i].x,a[i].y);
	return 0;
}
