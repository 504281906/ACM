#include <iostream>
#include <cstring>   
using namespace std;
int a[20][100],i,j;
int main()
{
	memset(a,0,sizeof(a));
	a[1][1]=1;
	for (i=2;i<=16;i++)
		for (j=1;j<=i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	for (i=1;i<=16;i++)
	{
		for (j=1;j<=i;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	
	//cout<<a[][]<<endl;
}
