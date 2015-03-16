#include <cstdio>
int main()
{
	double a[1010];
	int n;
	double f;
	while (~scanf("%d",&n) && n)
	{
		f=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%lf",&a[i]);
			f+=a[i];
		}
		f=f/n;
		double ff=0,fff=0;
		for (int i=1;i<=n;i++)
		if (a[i]>f)
			ff+=(int)((a[i]-f)*100)/100.0;
		else 
		 	fff+=(int)((f-a[i])*100)/100.0;
		printf("$%.2lf\n",ff<fff?fff:ff);
	}
	return 0;
}
