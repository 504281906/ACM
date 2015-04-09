#include <stdio.h>
#include <iostream> 
#include <algorithm> 
using namespace std;
int main()
{
	int n; 
	int a[210][210]; 
	while (~scanf("%d",&n))
	{
		for (int i=0;i<n;i++)
		{	
			for (int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
			sort(a[i],a[i]+n); 
		}
	}
	return 0; 
}
