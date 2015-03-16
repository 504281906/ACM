#include <stdio.h>
int main()
{
    int i;
    while (scanf("%d",&i)!=EOF)
    {
    if(i < 0 || i >100)  printf("Score is error!\n");
 else
    switch (i/10)
    {
           case 6:printf("D\n");break;
           case 7:printf("C\n");break;
           case 8:printf("B\n");break;
           case 9:
           case 10:printf("A\n");break;
                default: printf("E\n");
    }
    }
return 0;
}
