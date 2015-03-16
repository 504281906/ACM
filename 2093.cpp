#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct node
{
	char name[100];
	int time,ti;
}f[10000];
bool cmp(node a,node b)
{
	if (a.ti>b.ti) return 1;
	else if (a.ti==b.ti && a.time<b.time) return 1;
	else if (a.ti==b.ti && a.time==b.time)
	{
		int k=strcmp(a.name,b.name);
		if (k>0) return 0;
		else return 1;
	}
	return 0;
}
int main()
{
	int n,t,i,j;
	scanf("%d%d",&n,&t);
		//getchar();
		int T=0;
		memset(f,0,sizeof(f));
		while (~scanf("%s",&f[T].name))
		{
			f[T].ti=f[T].time=0;
			for (j=1;j<=n;j++)
			{
				int a,k=0;
				char c;
				scanf("%d",&a);
				scanf("%c",&c);
				if (c=='(') 
					scanf("%d%c",&k,&c);
				if (a<=0) continue;
				else 
				{
					f[T].ti++;
					f[T].time+=a+t*k;
				}
			}
			T++;
			//if (T==6) break;
		}
		sort(f,f+T,cmp);
		for (i=0;i<T;i++)
			printf("%-10s %2d %4d\n",f[i].name,f[i].ti,f[i].time);
	return 0;
}

