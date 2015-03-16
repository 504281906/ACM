#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int T,y,m,d;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&y,&m,&d);
		if ((m+d) % 2==0 || (d==30 && (m==9 || m==11)))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
