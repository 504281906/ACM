//#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#define M 10000 //�����ַ�����󳤶�
#define N 128 //����Ҷ�ӽ�����
#include <fstream>
typedef struct node//������������ڵ�ṹ��
{
	int weight;
	struct node *LChild,*RChild,*Parent;//�ֱ�ָ��ýڵ�����ӣ��Һ��Ӻ�˫�׽ڵ�
	struct node *next;//ָ�����Ĺ�����������һ���ڵ�
}HFMNode,*HFMTree;

typedef struct//�������������Ľṹ��
{
	char ch;//�洢��Ӧ���ַ�

	char code[N+1];//�����Ӧ�ַ��ı���
	int start;//�洢�������ʼλ��

}CodeNode;

int n;//�洢������Ҷ�ӽ�����


void clearscreen()
{
	system("cls");
}

void Open(char s[])//�򿪴���ַ��������ļ�����������ַ���������/
{
	
	char name[10];
	FILE *fp;
	int i=0;
	printf("��������Ҫ�򿪵��ļ���:");
	gets(name);//Ҫ�򿪵��ļ���
	if ((fp=fopen(name,"rt"))==NULL)
	{
		printf("��ʧ��!\n");//����ʧ�ܣ�ֱ���˳�
		exit(1);
	}
	s[i++]=fgetc(fp);
	while(s[i-1]!=EOF)
		s[i++]=fgetc(fp);
	s[i]='\0';//��ȡ�ַ�������
	fclose(fp);
}
void Save(char s[]) //�����ַ�����뵽�ļ���
{  
	char name[10]; 
    FILE *fp;  
    printf("��������Ҫ������ļ���:"); 
    gets(name);  
    if((fp=fopen(name,"wt"))==NULL) 
	{  
		printf("�洢ʧ��!"); 
        exit(1); 
	}  
	fputs(s,fp);  
    printf("\n����ɹ�,�ļ���Ϊ:%s \n",name); 
    printf("\n���س���������һ����"); 
    getchar(); 
    fclose(fp);
}

void SearchStr(char s[],char str[],int count[])  

{  

//�����ַ������ַ��ĸ�����ÿ���ַ����ֵĴ���
	int i,j,k=0;  
    for(i=0;i<N;i++) //��ʼ��ÿ���ַ����ֵĴ���
    count[i]=0; 
    for(i=0;s[i];i++) 
	{  
		for(j=0;j<k;j++) //��str[]�в����Ƿ��и��ַ�
        if(str[j]==s[i]) 
		{
			count[j]++; 
			break; 
		}
		if(j==k) //��str[]���޸��ַ�������������һ����Ԫ
		{  
			str[k]=s[i]; 
            count[k++]++; 
		} 
	}  
	str[k]='\0'; //���ַ�����β��\0  
    n=k; //��ʵ�ʵ��ַ�������ΪҶ�ӽڵ��������n 
} 


void SelectMin(HFMTree HT,int k,HFMTree *HT1,HFMTree *HT2) 

{  //���ҹ���������������Ȩֵ��С�Ľڵ�
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
			if(p->weight<min&&p->Parent==0&&p!=*HT1) //��ڶ�����С�Ľڵ㲻���ڵ�һ���ڵ�
			{  
				min=p->weight; 
				*HT2=p; 
			} 
} 

 

void CreatHFMTree(HFMTree *HT,int count[]) 
{  
	//������������
	int i;  
    HFMTree p,HT1,HT2; //HT1��HT2�ֱ���Ȩֵ��С�ʹ�С�Ľڵ��λ��
    p=*HT=(HFMTree)malloc(sizeof(HFMNode));  
    p->next=p->LChild=p->RChild=p->Parent=NULL; //��ʼ����������������2n-1���ڵ�
	for(i=1;i<2*n-1;i++) 
	{  
		p->next=(HFMTree)malloc(sizeof(HFMNode)); 
        p=p->next;  
        p->next=p->LChild=p->RChild=p->Parent=NULL; 
	} 
	for(i=0,p=*HT;i<n;i++) //�������ַ����ֵĴ�����ΪȨֵ
	{ 
		//��������������ǰn����Ԫ��
		p->weight=count[i]; 
        p=p->next; 
	} 
	for(i=n;i<2*n-1;i++) //����n-1���ڵ㸳Ȩֵ������
	{  
		SelectMin(*HT,i,&HT1,&HT2); //ÿ�δ�ǰi���ڵ���ѡȡȨֵ��С�������ڵ�
        HT1->Parent=HT2->Parent=p;  
        p->LChild=HT1; 
        p->RChild=HT2;  
        p->weight=HT1->weight+HT2->weight; //�������ڵ��Ȩֵ��Ӵ������һ���ڵ���
        p=p->next; //pָ����һ��û�д洢Ȩֵ�Ľڵ�
}
}

void HFMCode(HFMTree HT,CodeNode HC[],char str[]) 
{  //��ÿ��Ҷ�ӽڵ㿪ʼ�����ù���������ÿ���ַ����б��룬���ս���һ����������
	int i;  
    HFMTree q,p=HT;  
    for(i=0;i<n;i++) //���ַ��������������ṹ��������ַ���Ԫ��
	{  
		HC[i].ch=str[i];  
        HC[i].code[n-1]='\0'; //��ʼ����������һλ
	}  
	for(i=0;i<n;i++) 
	{  
		HC[i].start=n-1;  
		for(q=p;q->Parent;q=q->Parent) //�ж�q��ָ��Ľڵ㣬������0���Һ�����1 
			if(q==q->Parent->LChild) 
				HC[i].code[--HC[i].start]='0'; 
			else HC[i].code[--HC[i].start]='1'; 
			p=p->next; //�ж���һ��Ҷ�ӽڵ�
	}
}

void TotalCoding(char s[],CodeNode HC[],char code[]) 

{  
	//���ù����������������ַ������б���
	int i,j;  
	code[0]='\0'; //���������ʼ��
	for(i=0;s[i];i++) //��ÿ���ַ��ڹ�����������ж�Ӧ�ı���������ܱ����������
		for(j=0;j<n;j++) 
			if(s[i]==HC[j].ch)  
				strcpy(code+strlen(code),HC[j].code+HC[j].start); 
} 

void DeCoding(char code[],HFMTree HT,char str[],char s[]) 

{  
	//�Թ�����������н��룬�����ַ���s��
	int i,j,k=0; 
    HFMTree root,p,q;  
	for(root=HT;root->Parent;root=root->Parent)//��rootָ����������ĸ����
		for(i=0,p=root;code[i];i++) //�Ӹ���㿪ʼ������˳�������
		{   
			if(code[i]=='0') 
            p=p->LChild; 
            else p=p->RChild;  
            if(p->LChild==NULL&&p->RChild==NULL) //�����ڵ�ʱ���ýڵ��Ӧ���ַ����
			{  
				for(j=0,q=HT;q!=p;q=q->next,j++); 
				s[k++]=str[j];  
				p=root; //���ݵ������
			}  
		}  
		s[k]='\0'; //������ϣ����ַ������һ����Ԫ����'\0' 
}
	
void Coding(char s[],char str[],char code[],int count[],HFMTree *HT,CodeNode HC[]) 
{ 
	clearscreen();  
    printf("\n�����Ҫ������ļ�\n\n"); 
	Open(s); //��Դ���ļ�
    SearchStr(s,str,count); //�����ַ����в�ͬ���ַ�������ֵĴ���  
    CreatHFMTree(HT,count); //��ÿ���ַ����ֵĴ�����ΪҶ�ӽڵ��Ȩֵ������������
    HFMCode(*HT,HC,str); //���ù���������ÿ��Ҷ�ӽڵ���б��룬����������
    TotalCoding(s,HC,code); //���ñ������ַ����������ձ���
    printf("\n������ַ���Ϊ:\n"); 
    puts(s);  
	printf("\n�������յĹ�����������:\n"); 
    puts(code);  
    printf("\n�������,");  
    Save(code); //�������յĹ���������
} 

 
void TransCode(char code[],char str[],char ss[],HFMTree *HT,CodeNode HC[]) 
{  
	clearscreen();  
    printf("\n�����Ҫ������ļ�\n\n"); 
    Open(code); //�򿪱����ļ�
    DeCoding(code,*HT,str,ss); //��������н�������ַ�������ss[]��
    printf("\n����õ��������ַ���Ϊ:\n"); 
	puts(ss);  
    printf("\n��������"); 
    Save(ss); //�����������ַ���
} 

int main() 

 {  
	 //������
	 char s[M],ss[M]; //�����ַ������飬s[]��Ž�Ҫ������ַ�����ss[]��������ַ���
     char str[N]; //���������ַ�����n����ͬ���ַ�
     int count[N]; //���n����ͬ�ַ���Ӧ����ԭ�ַ����г��ֵĴ���
     char code[M]; //������ձ�����ɺ�ı���
     char choice;  
	 HFMTree HT; //����һ����������������
     CodeNode HC[N]; //����һ�����������������飬���ÿ���ַ���Ӧ�Ĺ���������
	 do 
	 {  
		 clearscreen(); 
		 printf("\n\n");  
		 printf(" ************��ӭʹ�ù�����������������************\n"); 
		 printf(" \n"); 
		 printf(" \n");  
		 printf("                   !.! 1.����$~$                  \n"); 
         printf("                   @.@ 2.����@.$                  \n"); 
		 printf("                   !.@ 3.�˳�:.;                  \n");
         printf(" \n"); 
         printf(" \n");  
         printf(" **           ��������Ӧ���������(1-3)          **\n"); 
         printf(" **************************************************\n"); 
         scanf("%c",&choice); 
         getchar(); 
         switch(choice) 
		 {  
		 case '1': Coding(s,str,code,count,&HT,HC);break; //���ַ������б���
         case '2': TransCode(code,str,ss,&HT,HC);break; //�Ա�����н���
         case '3': break;  
		 default : printf(" ���������������������룡\n"); 
		 }  
	 }
	 while(choice!='0'); 
 }
