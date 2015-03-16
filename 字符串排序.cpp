#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int compare(const void *arg1,const void *arg2)
{
　　return _stricmp(*(char **)arg1,*(char **)arg2);
}
int main(int argc,char **argv)
{
　　int i;
　　argv++;
　　argc--;
　　qsort((void *)argv,(size_t)argc,sizeof(char *),compare);
　　for(i=0;i<argc;++i)
　　printf("%s\n",argv);
　　return 0;
}
