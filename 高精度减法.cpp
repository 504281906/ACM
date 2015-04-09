#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char a[510],b[510];
	int c[510],la,lb,k; 
	memset(c,0,sizeof(c));
	cin>>a>>b;
	la=strlen(a)-1;
	lb=strlen(b)-1;
	k=la+1;
	int t=0;
	while (k--)
	{
		if (lb>=0)
		c[t]=(a[la--]-b[lb--]);
		else 
		c[t]=a[la--]-'0';
		if (c[t]<0)
		{
			a[la]--;
			c[t]+=10;
		}
		t++;
	}
	while (c[t]==0) t--;
	int ff=t;
	memset(a,0,sizeof(a));
	for (int j=t;j>=0;j--)
	a[ff-j]=c[j]+'0';
	cout<<a;
	return 0;
}
