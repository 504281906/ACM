#include <stdio.h>
int t1,t2;
void cmp(char a,char b)
{
	if (a==b) return;
	if ((a=='R'&&b=='S') || (a=='S'&&b=='P') || (a=='P'&&b=='R'))
	 t1++;
	else t2++;
}
int main()
{
	void cmp(char a,char b);
	int t,i,n;
	char a[101][5];
	scanf("%d",&t);
	while (t--)
	{
		t1=0;t2=0;
		scanf("%d",&n);
		{
			getchar();
			for (i=1;i<=n;i++)
			  gets(a[i]);
			for (i=1;i<=n;i++)
			cmp(a[i][0],a[i][2]);
		}
		if (t1==t2) printf("TLE\n");
		else if (t1>t2) printf("Player 1\n");
		else printf("Player 2\n");
	}
	return 0;
}
