#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<(1<<n);i++)
	cout<<i<<endl;
	return 0;
}
