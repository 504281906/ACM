#include <stdio.h>
#include <string.h>
int main()
{
	char s[1000];
	int n,i,l,l1,j,k;
	while (scanf("%d\n",&n)!=EOF && n!=0)
	{
		memset(s,0,sizeof(s));
		gets(s);
		l=strlen(s);
		l1=l;
		l--;
		s[-1]='x';
		while (1) 
		if (s[l--]=='x') break;
		if (l==-2) l=l1;
		else l+=2;
	    k=l/n;
	    for (i=0;i<n;i++)
	     for (j=0;j<k;j++)
	      {
				if (j%2==0) printf("%c",s[j*n+i]);
				else printf("%c",s[(j+1)*n-1-i]);
		  }
		  printf("\n");
	}
	return 0;
}
