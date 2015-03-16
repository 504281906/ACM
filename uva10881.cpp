#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int id,p,q;
	bool operator <(const node& a) const
	{
		return p<a.p;
	} 
}a[10010],b[10010];
int main()
{
	int c[10010];
	int T,cc=1;
	scanf("%d",&T);
	const char ch[10][10]={"L","Turning","R"};
	while (T--)
	{
		int l,t,n;
		scanf("%d%d%d",&l,&t,&n);
		for (int i=0;i<n;i++)
		{
			int d,k;
			char c;
			scanf("%d %c",&d,&c);
			k=(c=='L'?-1:1);
			a[i]=(node){i,d,k};
			b[i]=(node){0,d+t*k,k};
		}
		sort(a,a+n);
		for (int i=0;i<n;i++)
			c[a[i].id]=i;
		
		sort(b,b+n);
		for (int i=0;i<n-1;i++)
			if (b[i].p==b[i+1].p)
				b[i].q=b[i+1].q=0;
		printf("Case #%d:\n",cc++);
		for (int i=0;i<n;i++)
		{
			int k=c[i];
			if (b[k].p<0 || b[k].p>l) printf("Fell off\n");
			else 
			printf("%d %s\n",b[k].p,ch[b[k].q+1]);
		}
		printf("\n");
	}
	return 0;
}
