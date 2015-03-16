#include<stdio.h>
int main()
{
	int i,n,a,b,c;
	scanf("%d",&i);
	while(i--){
		scanf("%d",&n);
		c=2;
		while(n--){
			scanf("%d%d",&a,&b);
			a==c?c=b:b==c?c=a:c;
		}
		printf("%d\n",c);
	}
	return 0;
}
