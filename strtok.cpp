#include <string.h>
#include <stdio.h>

int main(void)
{
   char input[16] = "abc,dhh,eee";
   char *p;

   p = strtok(input, ",");
   if (p)   printf("%s\n", p);
  
   p = strtok(NULL, ",");
   if (p)   printf("%s\n", p);

   p = strtok(NULL, ",");
   if (p)   
   		printf("%s\n", p);
   return 0;
}
