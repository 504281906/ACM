#include <stdio.h>                                                       
#include <stdlib.h>
#include <string.h>                      
#include<iostream>
using namespace std;


typedef char **HuffmanCode;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      /*¶¯Ì¬·ÖÅäÊý×é£¬´æ´¢¹þ·òÂü±àÂë*/ 

typedef struct 
{  
	int weight ;                                        
	int parent, lchild,rchild ;                         
}HTNode, * HuffmanTree;                                      
//int s1,s2; 
int m;
void select(HuffmanTree ht,int n, int &s1, int &s2) 
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
	int s1,s2;
	//	if(n<=1) return ;
	HT=new HTNode[m+1];
	for(i=1;i<=m;i++)        
	{
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(i=1;i<=n;i++)
	{
		printf("input the %d element's weight:",i); 
		scanf("%d",&HT[i].weight);
	} 
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

void CrtHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n) 
{  
	HC=new char*[n+1];
	char cd[1000];
	int i;  
	int c; 
	int start; 
	int p;             
	cd[n-1]='\0';                                               
	for(i=1;i<=n;i++)                                        
	{  
		start=n-1;
		c=i;p=HT[i].parent;
		while (p!=0)
		{
			start--;
			if (HT[p].lchild==c) cd[start]='0';
			else cd[start]='1';
			c=p;p=HT[p].parent;
		}
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]); 
	}  
	//delete cd; 
	for(i=1;i<=n;i++)  
		printf("%d±àÂëÎª%s\n",HT[i].weight,HC[i]); 
} 

int main(int argc, char* argv[])
{
	HuffmanTree HT; 
	HuffmanCode HC; 
	int i,n;                                                                                                        
	printf("input the total number of the Huffman Tree:" ); 
	scanf("%d",&n); 
	m=2*n-1;
	creatHuffmanTree(HT,n); 
	outputHuffman(HT,m); 
	printf("\n");  
	CrtHuffmanCode(HT,HC,n); 
	//printf("Hello World!\n");
	//system("pause");
	return 0;
}
