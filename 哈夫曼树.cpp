#include <stdio.h>                                                       
#include <stdlib.h>
#include <string.h>                      
#include<iostream>
using namespace std;


typedef char* HuffmanCode;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      /*¶¯Ì¬·ÖÅäÊý×é£¬´æ´¢¹þ·òÂü±àÂë*/ 

typedef struct 
{  
unsigned int weight ;                                        
unsigned int parent, lchild,rchild ;                         
}HTNode, * HuffmanTree;                                      

void select(HuffmanTree ht,int n, int s1, int s2) 
{ 
  int i; 
  int min;  
  for(i=1; i<=n; i++) 
  {  
    if((ht)[i].parent == 0) 
	{
     min = i; 
     i = n+1; 
	} 
  }
  for(i=1; i<=n; i++) 
  {  
    if((ht)[i].parent == 0) 
	{  
	if((ht)[i].weight < (ht)[min].weight) 
    min = i; 
	} 
  }  
 s1 = min;  
  for(i=1; i<=n; i++) 
  {  
   if((ht)[i].parent == 0 && i!=(s1)) 
   {  
    min = i; 
    i = n+1; 
   } 
  }  
 for(i=1; i<=n; i++) 
 {  
  if((ht)[i].parent == 0 && i!=(s1)) 
  {  
   if((ht)[i].weight < (ht)[min].weight) 
   min = i; 
  } 
 }  
s2 = min; 
}
 
void creatHuffmanTree(HuffmanTree &HT,int n)
{
	int i;
	int m;
	m=2*n-1;
	int s1,s2;
	if(n<=1) return ;
	HT=new HTNode[m+1];      
	for(i=1;i<=m;i++)        
	{
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(i=1;i<=n;i++)
		scanf("%d",&HT[i].weight);
    for(i=n+1;i<=m;++i)
	{
		select(HT,i-1,s1,s2);
	HT[s1].parent=i;
	HT[s2].parent=i;
	HT[i].lchild=s1;
	HT[i].rchild=s2;
	HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
}


                                                    
void outputHuffman(HuffmanTree HT, int m) 
{
 printf("%d ", HT[m].weight);
 if (HT[m].lchild!=0)
 outputHuffman(HT,HT[m].lchild);
 if (HT[m].rchild!=0) 
 outputHuffman(HT,HT[m].rchild); 
} 


void CrtHuffmanCode(HuffmanTree *ht, HuffmanCode *hc, int n) 
{  
char *cd; 
int i;  
unsigned int c; 
int start; 
int p;  
hc=(HuffmanCode *)malloc((n+1)*sizeof(char *));             
cd[n-1]='\0';                                               
for(i=1;i<=n;i++)                                           
{  
	start=n-1;                                              
for(c=i,p=(*ht)[i].parent; p!=0; c=p,p=(*ht)[p].parent)      
if( (*ht)[p].lchild == c) 
cd[--start]='0';                                            
else 
cd[--start]='1';                                              
hc[i]=(char *)malloc((n-start)*sizeof(char));               
strcpy(hc[i],&cd[start]); 
}  
free(cd);  
for(i=1;i<=n;i++)  
printf("%d±àÂëÎª%s\n",(*ht)[i].weight,hc[i]); 
} 

int main(int argc, char* argv[])
{
   HuffmanTree HT; 
   HuffmanCode HC; 
   int *w; 
   int i,n;                                                       
   int wei;                                                       
   int m; 
   printf("input the total number of the Huffman Tree:" ); 
   scanf("%d",&n); 
   w=(int *)malloc((n+1)*sizeof(int)); 
  /* for(i=1;i<=n;i++) 
   { 
    printf("input the %d element's weight:",i); 
    fflush(stdin);  
    scanf("%d",&wei); 
    w[i]=wei; 
   }*/ 
    creatHuffmanTree(HT,n); 
    m = 2*n-1;  
    outputHuffman(HT,m); 
    printf("\n");  
    CrtHuffmanCode(&HT,&HC,n); 
	printf("Hello World!\n");
	return 0;
}
