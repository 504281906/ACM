#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
#define INF 0x3fffffff
#define Min(a,b) a>b?b:a
#define Max(a,b) a>b?a:b
//#define DEBUG
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	FILE *fin,*fout;
	fin=fopen("in.txt","r");
	fout=fopen("out.txt","w");
	int min=INF,max=-INF,a,s=0,t=0;
	while (~fscanf(fin,"%d",&a))
	{
		min=Min(min,a);
		max=Max(max,a);
		s+=a;
		t++;
	}
	fprintf(fout,"%d %d %lf\n",min,max,s*1.0/t);
	fclose(fin);
	fclose(fout);
	return 0;
}
