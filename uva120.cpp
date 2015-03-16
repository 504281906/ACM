#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
int a[110];
void ff(int x)
{
	int j=x/2;
	for (int i=0;i<=j;i++)
		swap(a[i],a[x-i]);
}
int main()
{
	string s;
	while (getline(cin,s)!=NULL && s!="")
	{
		istringstream is(s);
		int k=0;
		while (is>>a[k]) k++;
		for (int i=0;i<k-1;i++)
		cout<<a[i]<<" ";
		cout<<a[k-1]<<endl;
		for (int i=1;i<=k;i++)
		{
			int max=-1,pos=-1,j;
			for (j=k-i;j>=0;j--)
			if (a[j]>max)
			{
				max=a[j];
				pos=j;
			}
			if (pos==k-i) continue;
			else
			if (pos==0)
			{
				ff(k-i);
				cout<<i<<" ";	
			}
			if (pos!=0)
			{
				ff(pos);
				cout<<k-pos<<" ";
				ff(k-i);
				cout<<i<<" ";
			}
		}
		cout<<"0"<<endl;
	}
	return 0;
} 
