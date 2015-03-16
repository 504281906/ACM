#include <stdio.h>
int main()
{
 	char c;
 	double a,b;
 	int n;
 	scanf("%d",&n);
while (n--)
{	  
  scanf(" %c%d%d",&c,&a,&b);
  switch (c)
  {
   		 case '+':printf("%.0lf\n",a+b);break;
   		 case '-':printf("%.0lf\n",a-b);break;
   		 case '*':printf("%.0lf\n",a*b);break;
   		 case '/':if(a/b - int(a/b) == 0) 
					printf("%.0lf\n", a/b);
				else 
					printf("%.2lf\n", a/b);
  }
}
 	return 0;
}
