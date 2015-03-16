#include <stdio.h>
#include <string.h>
int main()
{
	int l1,l,i,f,t;
	char s[55];
	t=0;
	while (gets(s))
	{
		if (strcmp(s,"STOP")==0) break;
		t++;f=1; 
		l=strlen(s);
		l1=l;
		if (l==1) 
		{
		 	printf("#%d: YES\n",t);
		 	continue;
		}
		if (l%2==0) l/=2;
		else l=(l-1)/2;
		for (i=0;i<l;i++)
		 if (s[i]!=s[l1-i-1]) 
		 {
				f=0;
				break;
		 }
		if (f) printf("#%d: YES\n",t);
		else printf("#%d: NO\n",t);
	}
	return 0;
}
