//#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#define M 10000 //定义字符串最大长度
#define N 128 //定义叶子结点个数
#include <fstream>
typedef struct node//定义哈夫曼树节点结构体
{
	int weight;
	struct node *LChild,*RChild,*Parent;//分别指向该节点的左孩子，右孩子和双亲节点
	struct node *next;//指向建立的哈夫曼数的下一个节点
}HFMNode,*HFMTree;

typedef struct//定义哈夫曼编码的结构体
{
	char ch;//存储对应的字符

	char code[N+1];//储存对应字符的编码
	int start;//存储编码的起始位置

}CodeNode;

int n;//存储真正的叶子结点个数


void clearscreen()
{
	system("cls");
}

void Open(char s[])//打开存放字符或编码的文件，将其存入字符串数组中/
{
	
	char name[10];
	FILE *fp;
	int i=0;
	printf("请输入您要打开的文件名:");
	gets(name);//要打开的文件名
	if ((fp=fopen(name,"rt"))==NULL)
	{
		printf("打开失败!\n");//若打开失败，直接退出
		exit(1);
	}
	s[i++]=fgetc(fp);
	while(s[i-1]!=EOF)
		s[i++]=fgetc(fp);
	s[i]='\0';//存取字符串结束
	fclose(fp);
}
void Save(char s[]) //保存字符或编码到文件中
{  
	char name[10]; 
    FILE *fp;  
    printf("请输入您要保存的文件名:"); 
    gets(name);  
    if((fp=fopen(name,"wt"))==NULL) 
	{  
		printf("存储失败!"); 
        exit(1); 
	}  
	fputs(s,fp);  
    printf("\n保存成功,文件名为:%s \n",name); 
    printf("\n按回车键继续下一操作"); 
    getchar(); 
    fclose(fp);
}

void SearchStr(char s[],char str[],int count[])  

{  

//查找字符串中字符的个数和每个字符出现的次数
	int i,j,k=0;  
    for(i=0;i<N;i++) //初始化每个字符出现的次数
    count[i]=0; 
    for(i=0;s[i];i++) 
	{  
		for(j=0;j<k;j++) //在str[]中查找是否有该字符
        if(str[j]==s[i]) 
		{
			count[j]++; 
			break; 
		}
		if(j==k) //在str[]中无该字符，将其存入最后一个单元
		{  
			str[k]=s[i]; 
            count[k++]++; 
		} 
	}  
	str[k]='\0'; //将字符串结尾置\0  
    n=k; //将实际的字符个数作为叶子节点个数存入n 
} 


void SelectMin(HFMTree HT,int k,HFMTree *HT1,HFMTree *HT2) 

{  //查找哈夫曼链表中两个权值最小的节点
	int i,min; 
    HFMTree p; 
    min=32767;  
    for(i=0,p=HT;i<k;i++,p=p->next) 
		if(p->weight<min&&p->Parent==0) 
		{  
			min=p->weight; 
            *HT1=p; 
		}  
		min=32767;  
		for(i=0,p=HT;i<k;i++,p=p->next)
			if(p->weight<min&&p->Parent==0&&p!=*HT1) //令第二个最小的节点不等于第一个节点
			{  
				min=p->weight; 
				*HT2=p; 
			} 
} 

 

void CreatHFMTree(HFMTree *HT,int count[]) 
{  
	//创建哈夫曼树
	int i;  
    HFMTree p,HT1,HT2; //HT1，HT2分别存放权值最小和次小的节点的位置
    p=*HT=(HFMTree)malloc(sizeof(HFMNode));  
    p->next=p->LChild=p->RChild=p->Parent=NULL; //初始化哈夫曼链表且有2n-1个节点
	for(i=1;i<2*n-1;i++) 
	{  
		p->next=(HFMTree)malloc(sizeof(HFMNode)); 
        p=p->next;  
        p->next=p->LChild=p->RChild=p->Parent=NULL; 
	} 
	for(i=0,p=*HT;i<n;i++) //将各个字符出现的次数作为权值
	{ 
		//存入哈夫曼链表的前n个单元中
		p->weight=count[i]; 
        p=p->next; 
	} 
	for(i=n;i<2*n-1;i++) //将后n-1个节点赋权值，建树
	{  
		SelectMin(*HT,i,&HT1,&HT2); //每次从前i个节点中选取权值最小的两个节点
        HT1->Parent=HT2->Parent=p;  
        p->LChild=HT1; 
        p->RChild=HT2;  
        p->weight=HT1->weight+HT2->weight; //将两个节点的权值相加存入最后一个节点中
        p=p->next; //p指向下一个没有存储权值的节点
}
}

void HFMCode(HFMTree HT,CodeNode HC[],char str[]) 
{  //从每个叶子节点开始，利用哈夫曼树对每个字符进行编码，最终建立一个哈夫曼表
	int i;  
    HFMTree q,p=HT;  
    for(i=0;i<n;i++) //将字符存入哈夫曼编码结构体数组的字符单元中
	{  
		HC[i].ch=str[i];  
        HC[i].code[n-1]='\0'; //初始化编码的最后一位
	}  
	for(i=0;i<n;i++) 
	{  
		HC[i].start=n-1;  
		for(q=p;q->Parent;q=q->Parent) //判断q所指向的节点，左孩子置0，右孩子置1 
			if(q==q->Parent->LChild) 
				HC[i].code[--HC[i].start]='0'; 
			else HC[i].code[--HC[i].start]='1'; 
			p=p->next; //判断下一个叶子节点
	}
}

void TotalCoding(char s[],CodeNode HC[],char code[]) 

{  
	//利用哈夫曼编码表对整个字符串进行编码
	int i,j;  
	code[0]='\0'; //编码数组初始化
	for(i=0;s[i];i++) //将每个字符在哈夫曼编码表中对应的编码存入存放总编码的数组中
		for(j=0;j<n;j++) 
			if(s[i]==HC[j].ch)  
				strcpy(code+strlen(code),HC[j].code+HC[j].start); 
} 

void DeCoding(char code[],HFMTree HT,char str[],char s[]) 

{  
	//对哈夫曼编码进行解码，放入字符串s中
	int i,j,k=0; 
    HFMTree root,p,q;  
	for(root=HT;root->Parent;root=root->Parent)//用root指向哈夫曼树的根结点
		for(i=0,p=root;code[i];i++) //从根结点开始按编码顺序访问树
		{   
			if(code[i]=='0') 
            p=p->LChild; 
            else p=p->RChild;  
            if(p->LChild==NULL&&p->RChild==NULL) //到根节点时将该节点对应的字符输出
			{  
				for(j=0,q=HT;q!=p;q=q->next,j++); 
				s[k++]=str[j];  
				p=root; //回溯到根结点
			}  
		}  
		s[k]='\0'; //解码完毕，在字符串最后一个单元存入'\0' 
}
	
void Coding(char s[],char str[],char code[],int count[],HFMTree *HT,CodeNode HC[]) 
{ 
	clearscreen();  
    printf("\n请打开您要编码的文件\n\n"); 
	Open(s); //打开源码文件
    SearchStr(s,str,count); //查找字符串中不同的字符及其出现的次数  
    CreatHFMTree(HT,count); //用每个字符出现的次数作为叶子节点的权值建立哈夫曼树
    HFMCode(*HT,HC,str); //利用哈夫曼树对每个叶子节点进行编码，存入编码表中
    TotalCoding(s,HC,code); //利用编码表对字符串进行最终编码
    printf("\n读入的字符串为:\n"); 
    puts(s);  
	printf("\n编码最终的哈夫曼编码是:\n"); 
    puts(code);  
    printf("\n保存编码,");  
    Save(code); //保存最终的哈夫曼编码
} 

 
void TransCode(char code[],char str[],char ss[],HFMTree *HT,CodeNode HC[]) 
{  
	clearscreen();  
    printf("\n请打开您要编码的文件\n\n"); 
    Open(code); //打开编码文件
    DeCoding(code,*HT,str,ss); //将编码进行解码存入字符串数组ss[]中
    printf("\n编译得到的最终字符串为:\n"); 
	puts(ss);  
    printf("\n保存译码"); 
    Save(ss); //保存译码后的字符串
} 

int main() 

 {  
	 //主函数
	 char s[M],ss[M]; //定义字符串数组，s[]存放将要编码的字符串，ss[]存解码后的字符串
     char str[N]; //存放输入的字符串中n个不同的字符
     int count[N]; //存放n个不同字符对应的在原字符串中出现的次数
     char code[M]; //存放最终编码完成后的编码
     char choice;  
	 HFMTree HT; //定义一个哈夫曼树的链表
     CodeNode HC[N]; //定义一个哈夫曼编码表的数组，存放每个字符对应的哈夫曼编码
	 do 
	 {  
		 clearscreen(); 
		 printf("\n\n");  
		 printf(" ************欢迎使用哈夫曼树编码译码器************\n"); 
		 printf(" \n"); 
		 printf(" \n");  
		 printf("                   !.! 1.编码$~$                  \n"); 
         printf("                   @.@ 2.译码@.$                  \n"); 
		 printf("                   !.@ 3.退出:.;                  \n");
         printf(" \n"); 
         printf(" \n");  
         printf(" **           请输入相应操作的序号(1-3)          **\n"); 
         printf(" **************************************************\n"); 
         scanf("%c",&choice); 
         getchar(); 
         switch(choice) 
		 {  
		 case '1': Coding(s,str,code,count,&HT,HC);break; //对字符串进行编码
         case '2': TransCode(code,str,ss,&HT,HC);break; //对编码进行解码
         case '3': break;  
		 default : printf(" 您的输入有误！请重新输入！\n"); 
		 }  
	 }
	 while(choice!='0'); 
 }
