# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# define SPA 0
# define MAN 1
# define COM 2 /* ��λ����Ϊ0 ������µ�λ����Ϊ1 �������µ�λ����Ϊ2 */
int qipan[15][15]; /* 15*15������ */
int a,b,c,d,x; /* a bΪ����������� ��c dΪ������������ xΪʣ���λ��*/
void start(); /* �������Ҫ���ƺ��� */
void draw(); /* ������ */
int win(int p,int q); /* �ж�ʤ�� p qΪ�жϵ����� */
void AI(int *p,int *q); /* �������� p q������������ */
int value(int p,int q); /* ����յ�p q�ļ�ֵ */
int qixing(int n,int p,int q); /* ���ؿյ�p q��n�����ϵ����� nΪ1-8���� ����˳ʱ�뿪ʼ�� */
void yiwei(int n,int *i,int *j); /* ��n�����϶����� i j ��λ nΪ1-8���� ����˳ʱ�뿪ʼ�� */
int main()
{
 char k;
 do{ 
 x=225;
 start();
 printf("��Ҫ����һ����?����y��n��"); getchar(); scanf("%c",&k);
 while(k!='y'&&k!='n'){ 
 printf("�������,����������\n"); scanf("%c",&k); }
 system("cls");}while(k=='y');printf("ллʹ��!\n");
}
void start()
{
 int i,j,a1,b1,c1,d1,choice; /* a1 b1��������������� c1 d1��������������� */
 char ch; 
printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");printf("\t�U �U\n");printf("\t�U ��ӭʹ���������ս���� ף����������ս�޼��� �U\n"); printf("\t�U �U\n");printf("\t�U ._______________________. �U\n"); printf("\t�U | _____________________ | �U\n");printf("\t�U | I I | �U\n");printf("\t�U | I �� �� �� I | �U\n");printf("\t�U | I I | �U\n");printf("\t�U | I made by ��֮�� I | �U\n"); printf("\t�U | I___________________I | �U\n");printf("\t�U !_______________________! �U\n"); printf("\t�U ._[__________]_. �U\n");printf("\t�U .___|_______________|___. �U\n");printf("\t�U |::: ____ | �U\n"); printf("\t�U | ~~~~ [CD-ROM] | �U\n");printf("\t�U !_____________________! �U\n");printf("\t�U �U\n");printf("\t�U �U\n");printf("\t�U �� �� Ϫ �� �� �� �ף��� �� �� �� �� �� ���� �U\n");printf("\t�U �� �� �� �� ׷ �� ���� �� �� �� �� ɽ �ȡ� �U\n");printf("\t�U �� �� �� Ͽ �� ˮ ������ �� �� �� �� �� ᰡ� �U\n");printf("\t�U �� �� �� �� �� �� �ǣ�б �� �� �� �� �� �� �U\n");printf("\t�U �� ʮ �� �� �� �� ����ֱ ָ �� �� б �� �ǡ� �U\n");printf("\t�U �U\n");printf("\t�U �U\n");printf("\t�U 1.�˻���ս 2.���˶�ս �U\n");printf("\t�U �U\n");printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T �T�T�a\n");printf("\t\t\t������1��2��");

scanf("%d",&choice); /* ѡ��ģʽ:�˻������� */
 while(choice!=1&&choice!=2) { 
 printf("����������������룺"); scanf("%d",&choice); }
 if(choice==1){ /* �˻�ģʽ */
 system("cls"); 
 printf("��ӭʹ���������˻���ս���������������꣨��13 6��������������15 1 5��\n\n\n"); 
 for(j=0;j<15;j++)
 for(i=0;i<15;i++)
 qipan[j][i]=SPA; /* ������ȫΪ�� */
 draw();
 printf("�����밴1�������밴2��");scanf("%d",&i); 
 while(i!=1&&i!=2) { printf("����������������룺"); scanf("%d",&i); }
 if(i==1) { /* �������������� */
 printf("�����ӣ�"); scanf("%d%d",&a,&b); 
 while((a<0||a>14)||(b<0||b>14)) { 
 printf("�������!���������룺"); scanf("%d%d",&a,&b); }
 a1=a; b1=b; x--; qipan[b][a]=MAN; system("cls"); draw();
 }
 while(x!=0){
 if(x==225) {
 c=7; d=7; qipan[d][c]=COM; x--; system("cls"); draw(); } /* �������¾�����7 7 */
 else { AI(&c,&d); qipan[d][c]=COM; x--; system("cls"); draw(); } /* �������� */
 c1=c; d1=d; /* ��������������� */
 if(win(c,d)){ /* ����Ӯ */
 printf("Ҫ������������y��n��"); getchar(); scanf("%c",&ch);
 while(ch!='y'&&ch!='n') { printf("����������������룺");
 scanf("%c",&ch); }
 if(ch=='n') {
 printf("�²������Ժ��������벻Ҫ����!!!\n"); return; }
 else { x+=2; qipan[d][c]=SPA; qipan[b1][a1]=SPA;
 system("cls"); draw(); } /* ���� */
 }
 printf("��������%d %d\n�����룺",c,d); 
 scanf("%d%d",&a,&b); /* ������� */
 if(a==15&&b==15) { 
 x+=2; qipan[d][c]=SPA; qipan[b1][a1]=SPA; system("cls"); draw();
 printf("�����룺"); scanf("%d%d",&a,&b); } /* ���� */
 while((a<0||a>14)||(b<0||b>14)||qipan[b][a]!=SPA) { 
 printf("���������λ��������!���������룺"); 
 scanf("%d%d",&a,&b); } 
 a1=a; b1=b; x--; qipan[b][a]=MAN; system("cls"); draw();
 if(win(a,b)){ printf("��������Ķ��Ǹ���!!!\n"); 
 return; } /* ���Ӯ */
 }
 printf("�;�\n");
 }
 if(choice==2){
 system("cls");
 printf("��ӭʹ�����������˶�ս����������������(��13 6)������������15 15��\n\n\n"); 
 for(j=0;j<15;j++)
 for(i=0;i<15;i++)
 qipan[j][i]=SPA; /* ������ȫΪ�� */
 draw();
 while(x!=0){
 printf("1P�����룺"); scanf("%d%d",&a,&b);

if(a==15&&b==15) { 
 x+=2; qipan[d][c]=SPA; qipan[b1][a1]=SPA; system("cls"); 
 draw(); printf("1P�����룺"); scanf("%d%d",&a,&b); }
 while((a<0||a>14)||(b<0||b>14)||qipan[b][a]!=SPA) { 
 printf("���������λ��������!���������룺"); 
 scanf("%d%d",&a,&b); }
 a1=a; b1=b; x--; qipan[b][a]=MAN; system("cls"); draw();
 printf("1P����%d %d��\n",a,b);
 if(win(a,b)){ printf("�����!!!\n"); return; } /* ���1Ӯ */
 printf("2P�����룺"); scanf("%d%d",&c,&d);
 if(c==15&&d==15) {
 x+=2; qipan[b][a]=SPA; qipan[d1][c1]=SPA; system("cls"); draw();
 printf("2P�����룺"); scanf("%d%d",&c,&d); }
 while((c<0||c>14)||(d<0||d>14)||qipan[d][c]!=SPA) { 
 printf("���������λ��������!���������룺"); scanf("%d%d",&c,&d);
 }
 c1=c; d1=d; x--; qipan[d][c]=COM; system("cls"); draw();
 printf("2P����%d %d��\n",c,d);
 if(win(c,d)){ printf("�����!!!\n"); return; } /* ���2Ӯ */
 }
 printf("�;�\n");
 }
}
void draw() /* ������ */
{
 int i,j;
 char p[15][15][4];
 for(j=0;j<15;j++)
 for(i=0;i<15;i++){
 if(qipan[j][i]==SPA) strcpy(p[j][i]," \0");
 if(qipan[j][i]==MAN) strcpy(p[j][i],"��\0");
 if(qipan[j][i]==COM) strcpy(p[j][i],"��\0");}
 printf(" 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 \n"); 
 printf(" �����С��С��С��С��С��С��С��С��С��С��С��С��С��С���\n");
 for(i=0,j=0;i<14;i++,j++){
 printf(" %2d��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��%d\n",j,p[i][0],p[i][1],p[i][2],p[i][3],p[i][4],p[i][5],p[i][6],p[i][7],p[i][8],p[i][9],p[i][10],p[i][11],p[i][12],p[i][13],p[i][14],j);
 printf(" �����ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ��\n"); } 
 printf(" 14��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��%s��0\n",p[14][0],p[14][1],p[14][2],p[14][3],p[14][4],p[14][5],p[14][6],p[14][7],p[14][8],p[14][9],p[14][10],p[14][11],p[14][12],p[14][13],p[14][14]); 
 printf(" �����ء��ء��ء��ء��ء��ء��ء��ء��ء��ء��ء��ء��ء��ء���\n");
 printf(" 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 \n");
}
int win(int p,int q) /* �ж�ʤ�� p qΪ�жϵ����꣬ʤ������1�����򷵻�0 */
{
 int k,n=1,m,P,Q; /* k�����жϵ�p q��״̬COM��MAN��P Q�����жϵ����ꡣnΪ�жϷ���mΪ������ */
 P=p; Q=q;k=qipan[q][p];
 while(n!=5){
 m=0; 
 while(k==qipan[q][p]){
 m++;if(m==5) return 1; 
 yiwei(n,&p,&q); if(p<0||p>14||q<0||q>14) break;
 }
 n+=4; m-=1; p=P; q=Q; /* ת���ж� */
 while(k==qipan[q][p]){

m++;
 if(m==5) return 1; 
 yiwei(n,&p,&q); if(p<0||p>14||q<0||q>14) break;
 }
 n-=3; p=P; q=Q; /* ���ɹ����ж���һ�鷽�� */
 }
 return 0;
}
void AI(int *p,int *q) /* �������� *p *q������������ */
{
 int i,j,k,max=0,I,J; /* I JΪ�µ����� */
 for(j=0;j<15;j++)
 for(i=0;i<15;i++)
 if(qipan[j][i]==SPA){ /* �������̣������յ�������ֵ��ȡ����ֵ�����ӡ� */
 k=value(i,j);if(k>=max) { I=i; J=j; max=k; }
 }
 *p=I; *q=J;
}
int value(int p,int q) /* ����յ�p q�ļ�ֵ ��k���� */ 
{
 int n=1,k=0,k1,k2,K1,K2,X1,Y1,Z1,X2,Y2,Z2,temp; 
 int a[2][4][4]={40,400,3000,10000,6,10,600,10000,20,120,200,0,6,10,500,0,30,300,2500,5000,2,8,300,8000,26,160,0,0,4,20,300,0}; /* ����a�д��漺���ͶԷ���32�����͵�ֵ ����0�Է�1 ��0��1�ջ�2�ճ�3 ����0-3��0��ʾ1���ӣ�3��ʾ4���ӣ� */
 while(n!=5){
 k1=qixing(n,p,q); n+=4;/* k1,k2Ϊ2������������ͱ�� */
 k2=qixing(n,p,q); n-=3;
 if(k1>k2) { temp=k1; k1=k2; k2=temp; } /* ʹ���С��Ϊk1,���Ϊk2 */
 K1=k1; K2=k2; /* K1 K2����k1 k2�ı�� */
 Z1=k1%10; Z2=k2%10; k1/=10; k2/=10; Y1=k1%10; Y2=k2%10; k1/=10; k2/=10; 
 X1=k1%10; X2=k2%10; /* X Y Z�ֱ��ʾ ����0�Է�1 ��0��1�ջ�2�ճ�3 ����0-3��0��ʾ1���ӣ�3��ʾ4���ӣ� */
 if(K1==-1) { 
 if(K2<0) { k+=0; continue; } else k+=a[X2][Y2][Z2]+5; continue; }; /* ������and���� */
 if(K1==-2) { if(K2<0) { k+=0; continue; } 
 else k+=a[X2][Y2][Z2]/2; continue; }; /* �߽������and���� */ 
 if(K1==-3) { if(K2<0) { k+=0; continue; } 
 else k+=a[X2][Y2][Z2]/3; continue; }; /* �߽�ճ�����and���� */ 
 if(((K1>-1&&K1<4)&&((K2>-1&&K2<4)||(K2>9&&K2<14)))||((K1>99&&K1<104)&&((K2>99&&K2<104)||(K2>109&&K2<114)))){
 /* ����� ����� �Ի�Ի� �Ի�Գ� �����͸�ֵ*/
 if(Z1+Z2>=2) { k+=a[X2][Y2][3]; continue; }
 else { k+=a[X2][Y2][Z1+Z2+1]; continue; }
 }
 if(((K1>9&&K1<14)&&(K2>9&&K2<14))||((K1>109&&K1<114)&&(K2>109&&K2<114))){ 
 /* ���强�� �Գ�Գ� �����͸�ֵ*/
 if(Z1+Z2>=2) { k+=10000; continue; }
 else { k+=0; continue; }
 }
 if(((K1>-1&&K1<4)&&((K2>99&&K2<104)||(K2>109&&K2<114)))||((K1>9&&K1<14)&&((K2>99&&K2<104)||(K2>109&&K2<114)))){
 /* ����Ի� ����Գ� ����Ի� ����Գ� �����͸�ֵ*/
 if(Z1==3||Z2==3) { k+=10000; continue; }
 else { k+=a[X2][Y2][Z2]+a[X1][Y1][Z1]/4; continue; }
}
 else 
 { k+=a[X1][Y1][Z1]+a[X2][Y2][Z2]; continue; } /* �������͵ĸ�ֵ */ 
 }
 return k;
}
int qixing(int n,int p,int q) /* ���ؿյ�p q��n�����ϵ����ͺ� nΪ1-8���� ����˳ʱ�뿪ʼ�� */ 
{
 int k,m=0; /* ���ͺ�ע��: ����000-003 ����010-013 �Ի�100-103 �Գ�110-113 ���ջ�020-023 ���ճ�030-033 �Կջ�120-123 �Կճ�130-133 ��-1 �߽��-2 �߽�ճ�-3*/
 yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) k=-2; /* �߽������ */
 switch(qipan[q][p]){
 case COM:{
 m++; yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=m+9; return k; }
 while(qipan[q][p]==COM) {
 m++; yiwei(n,&p,&q); if(p<0||p>14||q<0||q>14) { k=m+9; return k; } 
 }
 if(qipan[q][p]==SPA) k=m-1; /* ���������� */ 
 else k=m+9; /* ���������� */
 }break;
 case MAN:{
 m++; yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=m+109; return k; }
 while(qipan[q][p]==MAN) {
 m++; yiwei(n,&p,&q); if(p<0||p>14||q<0||q>14) { k=m+109; return k; } 
 }
 if(qipan[q][p]==SPA) k=m+99; /* �Է������� */
 else k=m+109; /* �Է������� */
 }break;
 case SPA:{
 yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=-3; return k; } /* �߽�ճ����� */ 
 switch(qipan[q][p]){
 case COM:{
 m++; yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=m+29; return k; }
 while(qipan[q][p]==COM) { 
 m++; yiwei(n,&p,&q); 
 if(p<0||p>14||q<0||q>14) { k=m+29; return k; }
 }
 if(qipan[q][p]==SPA) k=m+19; /* �����ջ����� */
 else k=m+29; /* �����ճ����� */
 }break;
 case MAN:{
 m++; yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=m+129; return k; }
 while(qipan[q][p]==MAN) { 
 m++; yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=m+129; return k; } 
 } 
 if(qipan[q][p]==SPA) k=m+119; /* �Է��ջ����� */
 else k=m+129; /* �Է��ճ����� */ 
 }break;
 case SPA: k=-1; break; /* ������ */
 }
 }break;
 }
 return k;
}
void yiwei(int n,int *i,int *j) /* ��n�����϶����� i j ��λ nΪ1-8���� ����˳ʱ�뿪ʼ�� */
{
 switch(n){
 case 1: *i+=1; break;
 case 2: *i+=1; *j+=1; break;
 case 3: *j+=1; break;
 case 4: *i-=1; *j+=1; break;
 case 5: *i-=1; break;
 case 6: *i-=1; *j-=1; break;
 case 7: *j-=1; break;
 case 8: *i+=1; *j-=1; break;
 }
}
 
