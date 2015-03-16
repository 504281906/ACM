#include<iostream>   
#include<fstream> //�ļ���������ͷ�ļ�   
#include<iomanip>   
#define Maxvalue 100000   
#define Maxleafsize 40   
#define Maxnode 2*Maxleafsize-1   
#define Maxbit 20   
//�������ṹ����   
using namespace std; 
typedef struct Node{   
    int weight,lchild,rchild,parent;   
    char data;   
}HffNode;   
typedef struct{   
    int bit[Maxbit];   
    int start;   
}HffCode;   
//�������������ĺ�������   
void Create_Haff(HffNode H[],int n)   
{   int i,j,m1,m2,x1,x2;   
    for(i=0;i<2*n-1;i++) //��ʼ���������   
    {   H[i].weight=0;   
        H[i].parent=-1;   
        H[i].lchild=-1;   
        H[i].rchild=-1;   
        H[i].data='#';   
    }   
    cout<<"�������ַ�"<<endl;   
    for(i=0;i<n;i++)   
        cin>>H[i].data;//����Ҷ�ӽ���Ȩֵ   
    cout<<"�������Ҷ�ӽ���Ȩֵ"<<endl;   
    for(i=0;i<n;i++)                    
    cin>>H[i].weight;//ͨ��ѭ��������������   
    for(i=0;i<n-1;i++)              
    {   m1=m2=Maxvalue;   
        x1=x2=0;   
        for(j=0;j<n+i;j++)//ѡȡ��С�ʹ�С����Ȩֵ   
        {   if(H[j].parent==-1&&H[j].weight<m1)   
            {   m2=m1;   
                x2=x1;   
                m1=H[j].weight;   
                x1=j;   
            }   
            else if(H[j].parent==-1&&H[j].weight<m2)   
            {   m2=H[j].weight;   
                x2=j;   
            }   
        }   
        H[x1].parent=n+i;   
        H[x2].parent=n+i;   
        H[n+i].weight=H[x1].weight+H[x2].weight;   
        H[n+i].lchild=x1;   
        H[n+i].rchild=x2;   
    }   
}   
void Hffcode(HffNode Hnode[],int n) //���������뺯��      
{   HffCode Hcode[Maxleafsize],cd;   
    int i,j,c,p,k=0,q=0,u=0,t=0;   
    char ch[50],m;     
    for(i=0;i<n;i++)//ͨ��ѭ��ʵ�ֱ���               
    {   cd.start=n-1;   
        c=i;   
        p=Hnode[c].parent;   
        while(p!=-1)   
        {   if(Hnode[p].lchild==c)   
                cd.bit[cd.start]=0;   
            else   
                cd.bit[cd.start]=1;   
                cd.start--;   
                c=p;   
                p=Hnode[c].parent;   
        }   
        for(j=cd.start+1;j<n;j++)   
            Hcode[i].bit[j]=cd.bit[j];   
        Hcode[i].start=cd.start;   
    }   
    for(i=0;i<n;i++)//�������                  
    {   cout<<Hnode[i].data<<"�ı���Ϊ:"<<endl;   
        for(j=Hcode[i].start+1;j<n;j++)   
            cout<<Hcode[i].bit[j];   
        cout<<endl;   
    }      
    fstream ftxt;//�ı�����   
    ftxt.open("codefile.txt",ios::out);//��Ϣд���ļ���       
    ftxt<<setw(8)<<"Weight"<<setw(8)<<"Lchild"<<setw(8)<<"Rchild"   
        <<setw(8)<<"Parent"<<setw(8)<<"�ַ�ֵ"<<setw(14)<<"����"<<endl;   
    for(i=0;i<2*n-1;i++)   
    {   ftxt<<setw(8)<<Hnode[i].weight<<setw(8)<<Hnode[i].lchild<<setw(8)   
        <<Hnode[i].rchild<<setw(8)<<Hnode[i].parent<<setw(8)<<Hnode[i].data<<setw(11);   
        for(j=Hcode[k].start+1;j<n&&k<n;j++)//�ļ���������Ļ�������   
            ftxt<<Hcode[k].bit[j];   
        k++;   
        ftxt<<endl;   
    }   
    cout<<"������Ҫ������ַ�����#����"<<endl;   
    cin>>m;   
    while(m!='#')   
    {ch[t]=m;   
      t++;   
      cin>>m;   
    }   
     ch[t]='#';    
   ftxt<<"Ҫ������ַ���Ϊ:";   
    for(i=0;ch[i]!='#';i++)   
        ftxt<<ch[i];   
        ftxt<<endl;   
        ftxt<<"�˴�����Ϊ:";   
        while(q<n&&ch[u]!='#')//ʵ�ֱ���   
        {   while(Hnode[q].data!=ch[u])   
                q++;   
            for(j=Hcode[q].start+1;j<n;j++)   
            {   cout<<Hcode[q].bit[j];   
              ftxt<<Hcode[q].bit[j];}   
            q=0;   
            u++;   
        }   
        cout<<endl;   
        ftxt<<endl;   
        ftxt.close();   
       
}   
void Hfftran(HffNode H[],int node)  //���뺯��   
{   int i=node-1,j=0;char b;   
    cout<<"������������밴#����:"<<endl;   
    cin>>b;   
    while(((b=='0')||(b=='1'))&&b!='#')   
    {   if(b=='0')i=H[i].lchild;   
        else i=H[i].rchild;   
        if(H[i].lchild==-1&&H[i].rchild==-1)   
        {   cout<<H[i].data;   
            i=node-1;   
        }   
        cin>>b;   
    }   
    cout<<endl;   
}   
int main()   
{      
        char c;int n,i,k=0;HffNode Hnode[Maxnode];   
        cout<<"************��ӭʹ�ù���������ϵͳ************"<<endl;   
        cout<<"���Ƚ�����������"<<endl;   
        cout<<"�������ַ�����Сn:"<<endl;   
        cin>>n;   
        Create_Haff(Hnode,n);   
        cout<<"���������ѽ���"<<endl;   
        cout<<endl;   
        cout<<"1--���й�����������"<<endl;   
        cout<<"2--���й�����������"<<endl;   
        cout<<"3--��ӡ��������"<<endl;   
        cout<<"0--�˳�����"<<endl;    
A:      cout<<"��ѡ�����"<<endl ;   
        cin>>c;          
        if(c=='1')   
        { Hffcode(Hnode,n);goto A;}   
        else if(c=='2')   
        {   Hfftran(Hnode,2*n-1);goto A;}   
        else if(c=='3')   
        {   
			cout<<setw(8)<<"Weight"<<setw(8)<<"Lchild"<<setw(8)<<"Rchild"<<setw(8)<<"Parent"<<setw(8)<<"�ַ�ֵ"<<endl;   
            for(i=0;i<2*n-1;i++)   
            {   cout<<setw(8)<<Hnode[i].weight<<setw(8)<<Hnode[i].lchild<<setw(8)   
                <<Hnode[i].rchild<<setw(8)<<Hnode[i].parent<<setw(8)<<Hnode[i].data<<setw(11)<<endl;   
            }   
            goto A;   
        }   
        else if(c=='0')   
        {   cout<<"ллʹ��"<<endl;
			return 0;}   
        else {cout<<"��������,�����ԡ�"<<endl;goto A;}   
       
} 
