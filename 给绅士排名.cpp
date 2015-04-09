#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
struct node
{
	char fn[100];
	char ln[100];
	int h;
	int l;
}man[100];
using namespace std;
int ccmp(const void *x,const void *y)
{
	if ((*(node *)x).h<(*(node *)y).h) return -1;
	if ((*(node *)x).h>(*(node *)y).h) return 1;
	if ((*(node *)x).l<(*(node *)y).l) return -1;
	if ((*(node *)x).l>(*(node *)y).l) return 1;
	if (int r=strcmp((*(node *)x).ln,(*(node *)y).ln)!=0) return r;
	return (strcmp((*(node *)x).fn,(*(node *)y).fn));
}
int main()
{
	int k=0,hh,ll;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while (scanf("%s %s %d %d",&man[k].fn,&man[k].ln,&hh,&ll)!=EOF)
	{
		man[k].h=fabs(hh-180);
		if (ll>75)
		man[k].l=ll-75;
		else
		man[k].l=-ll;
		k++;
	}
	int cmp();
	qsort(man,k,sizeof(man[0]),ccmp);
	for (int i=0;i<k;i++)
	printf("%s %s\n",man[i].fn,man[i].ln);
	return 0;
}
