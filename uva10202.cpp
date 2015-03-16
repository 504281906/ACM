#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
int n;
bool cmp(int a,int b)
{
	return a<b;
}
vector <int> yanzheng(int k,vector<int> sum)
{
	vector <int> chu1;
	chu1.push_back(k);
	int i,j;
	while (sum.size())
	{
		int p=sum[0]-chu1[0];
		for (j=0;j<chu1.size();j++)
		{
			vector<int>::iterator it=find(sum.begin(),sum.end(),p+chu1[j]);
			if (it!=sum.end())
				sum.erase(it);
			else
			{
				chu1.clear();
				return chu1;
			}
		}
		chu1.push_back(p);
	}
	return chu1;
}
void findd(vector<int> sum)
{
	int i,j;
	int f=0;
	sort(sum.begin(),sum.end(),cmp);
	for (i=2;i<=sum.size();i++)
	{
		vector <int> chu;
		int k=sum[0]+sum[1]-sum[i];
		if (k % 2==1)
			continue;
		else
			chu=yanzheng(k/2,sum);
		if (chu.size())
		{
			for (j=0;j<chu.size();j++)
			{
				cout<<chu[j];
				if (j<chu.size()-1)
				cout<<" ";
			}	
			cout<<endl;
			f=1;
			break;
		}
	}
	if (f==0) cout<<"Impossible\n";
}
int main()
{
	int i;
	while (cin>>n)
	{
		vector <int> sum;
		int l=n*(n-1)/2;
		for (i=0;i<l;i++)
		{
			int a;
			cin>>a;
			sum.push_back(a);
		}
		findd(sum);
	}
} 
