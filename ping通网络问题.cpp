#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#define LL __int64
#define eps 1e-8
using namespace std;
int main(){
	string a;
	char b[100]={"ping 172.16.10.5"};
	for (int i=1;i<=255;i++) //15
	{
		int t=15;
		int j=i;
		int k=0;
		int c[10];
		while (j)
		{
			c[k++]=j%10;
			j/=10;
		}
		for (j=k-1;j>=0;j--)
			b[t++]=c[j]+'0';
		b[t]='\0';
		system(b);
	}
	return 0;
}
