#include <stdio.h>
#include <string.h>
int main()
{
	char a,s[201];
	int l,t,i;
	while (scanf("%c%s",&a,&s)!=EOF)
	{
		l=strlen(s);t=0;
		if (a<'a') a+=32;
		for (i=0;i<l;i++)
		{
		if (s[i]<'a') s[i]+=32;
		if (a==s[i]) t++;
	    }
	    printf("%.5lf\n",t*1.000000/l);
		getchar();
	}
	return 0;
}
