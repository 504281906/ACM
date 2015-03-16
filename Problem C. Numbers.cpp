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
using namespace std;
//#define DEBUG
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	double b=sqrt(5);
	double a=3.0+b;
	double s=1.0;
	for (int i=1;i<=100;i++)
	{
		s*=a;
		
		printf("%d\n",(int )s % 1000);
		system("pause");
	}	
	return 0;
}

