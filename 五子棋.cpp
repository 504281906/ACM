# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# define SPA 0
# define MAN 1
# define COM 2 /* 空位置设为0 ，玩家下的位置设为1 ，电脑下的位置设为2 */
int qipan[15][15]; /* 15*15的棋盘 */
int a,b,c,d,x; /* a b为玩家下子坐标 ，c d为电脑下子坐标 x为剩余空位置*/
void start(); /* 程序的主要控制函数 */
void draw(); /* 画棋盘 */
int win(int p,int q); /* 判断胜利 p q为判断点坐标 */
void AI(int *p,int *q); /* 电脑下子 p q返回下子坐标 */
int value(int p,int q); /* 计算空点p q的价值 */
int qixing(int n,int p,int q); /* 返回空点p q在n方向上的棋型 n为1-8方向 从右顺时针开始数 */
void yiwei(int n,int *i,int *j); /* 在n方向上对坐标 i j 移位 n为1-8方向 从右顺时针开始数 */
int main()
{
 char k;
 do{ 
 x=225;
 start();
 printf("还要再来一把吗?输入y或n："); getchar(); scanf("%c",&k);
 while(k!='y'&&k!='n'){ 
 printf("输入错误,请重新输入\n"); scanf("%c",&k); }
 system("cls");}while(k=='y');printf("谢谢使用!\n");
}
void start()
{
 int i,j,a1,b1,c1,d1,choice; /* a1 b1储存玩家上手坐标 c1 d1储存电脑上手坐标 */
 char ch; 
printf("\t╔══════════════════════════════╗\n");printf("\t║ ║\n");printf("\t║ 欢迎使用五子棋对战程序 祝您玩的愉快挑战无极限 ║\n"); printf("\t║ ║\n");printf("\t║ ._______________________. ║\n"); printf("\t║ | _____________________ | ║\n");printf("\t║ | I I | ║\n");printf("\t║ | I 五 子 棋 I | ║\n");printf("\t║ | I I | ║\n");printf("\t║ | I made by 晓之蓬 I | ║\n"); printf("\t║ | I___________________I | ║\n");printf("\t║ !_______________________! ║\n"); printf("\t║ ._[__________]_. ║\n");printf("\t║ .___|_______________|___. ║\n");printf("\t║ |::: ____ | ║\n"); printf("\t║ | ~~~~ [CD-ROM] | ║\n");printf("\t║ !_____________________! ║\n");printf("\t║ ║\n");printf("\t║ ║\n");printf("\t║ 寒 星 溪 月 疏 星 首，花 残 二 月 并 白 莲。 ║\n");printf("\t║ 雨 月 金 星 追 黑 玉，松 丘 新 宵 瑞 山 腥。 ║\n");printf("\t║ 星 月 长 峡 恒 水 流，白 莲 垂 俏 云 浦 岚。 ║\n");printf("\t║ 黑 玉 银 月 倚 明 星，斜 月 明 月 堪 称 朋。 ║\n");printf("\t║ 二 十 六 局 先 弃 二，直 指 游 星 斜 彗 星。 ║\n");printf("\t║ ║\n");printf("\t║ ║\n");printf("\t║ 1.人机对战 2.人人对战 ║\n");printf("\t║ ║\n");printf("\t╚═══════════════════════════ ══╝\n");printf("\t\t\t请输入1或2：");

scanf("%d",&choice); /* 选择模式:人机或人人 */
 while(choice!=1&&choice!=2) { 
 printf("输入错误，请重新输入："); scanf("%d",&choice); }
 if(choice==1){ /* 人机模式 */
 system("cls"); 
 printf("欢迎使用五子棋人机对战！下子请输入坐标（如13 6）。悔棋请输入15 1 5。\n\n\n"); 
 for(j=0;j<15;j++)
 for(i=0;i<15;i++)
 qipan[j][i]=SPA; /* 置棋盘全为空 */
 draw();
 printf("先下请按1，后下请按2：");scanf("%d",&i); 
 while(i!=1&&i!=2) { printf("输入错误，请重新输入："); scanf("%d",&i); }
 if(i==1) { /* 如果玩家先手下子 */
 printf("请下子："); scanf("%d%d",&a,&b); 
 while((a<0||a>14)||(b<0||b>14)) { 
 printf("坐标错误!请重新输入："); scanf("%d%d",&a,&b); }
 a1=a; b1=b; x--; qipan[b][a]=MAN; system("cls"); draw();
 }
 while(x!=0){
 if(x==225) {
 c=7; d=7; qipan[d][c]=COM; x--; system("cls"); draw(); } /* 电脑先下就下在7 7 */
 else { AI(&c,&d); qipan[d][c]=COM; x--; system("cls"); draw(); } /* 电脑下子 */
 c1=c; d1=d; /* 储存电脑上手棋型 */
 if(win(c,d)){ /* 电脑赢 */
 printf("要悔棋吗？请输入y或n："); getchar(); scanf("%c",&ch);
 while(ch!='y'&&ch!='n') { printf("输入错误，请重新输入：");
 scanf("%c",&ch); }
 if(ch=='n') {
 printf("下不过电脑很正常，请不要灰心!!!\n"); return; }
 else { x+=2; qipan[d][c]=SPA; qipan[b1][a1]=SPA;
 system("cls"); draw(); } /* 悔棋 */
 }
 printf("电脑下在%d %d\n请输入：",c,d); 
 scanf("%d%d",&a,&b); /* 玩家下子 */
 if(a==15&&b==15) { 
 x+=2; qipan[d][c]=SPA; qipan[b1][a1]=SPA; system("cls"); draw();
 printf("请输入："); scanf("%d%d",&a,&b); } /* 悔棋 */
 while((a<0||a>14)||(b<0||b>14)||qipan[b][a]!=SPA) { 
 printf("坐标错误或该位置已有子!请重新输入："); 
 scanf("%d%d",&a,&b); } 
 a1=a; b1=b; x--; qipan[b][a]=MAN; system("cls"); draw();
 if(win(a,b)){ printf("电脑神马的都是浮云!!!\n"); 
 return; } /* 玩家赢 */
 }
 printf("和局\n");
 }
 if(choice==2){
 system("cls");
 printf("欢迎使用五子棋人人对战！下子请输入坐标(如13 6)。悔棋请输入15 15。\n\n\n"); 
 for(j=0;j<15;j++)
 for(i=0;i<15;i++)
 qipan[j][i]=SPA; /* 置棋盘全为空 */
 draw();
 while(x!=0){
 printf("1P请输入："); scanf("%d%d",&a,&b);

if(a==15&&b==15) { 
 x+=2; qipan[d][c]=SPA; qipan[b1][a1]=SPA; system("cls"); 
 draw(); printf("1P请输入："); scanf("%d%d",&a,&b); }
 while((a<0||a>14)||(b<0||b>14)||qipan[b][a]!=SPA) { 
 printf("坐标错误或该位置已有子!请重新输入："); 
 scanf("%d%d",&a,&b); }
 a1=a; b1=b; x--; qipan[b][a]=MAN; system("cls"); draw();
 printf("1P下在%d %d。\n",a,b);
 if(win(a,b)){ printf("你真棒!!!\n"); return; } /* 玩家1赢 */
 printf("2P请输入："); scanf("%d%d",&c,&d);
 if(c==15&&d==15) {
 x+=2; qipan[b][a]=SPA; qipan[d1][c1]=SPA; system("cls"); draw();
 printf("2P请输入："); scanf("%d%d",&c,&d); }
 while((c<0||c>14)||(d<0||d>14)||qipan[d][c]!=SPA) { 
 printf("坐标错误或该位置已有子!请重新输入："); scanf("%d%d",&c,&d);
 }
 c1=c; d1=d; x--; qipan[d][c]=COM; system("cls"); draw();
 printf("2P下在%d %d。\n",c,d);
 if(win(c,d)){ printf("你真棒!!!\n"); return; } /* 玩家2赢 */
 }
 printf("和局\n");
 }
}
void draw() /* 画棋盘 */
{
 int i,j;
 char p[15][15][4];
 for(j=0;j<15;j++)
 for(i=0;i<15;i++){
 if(qipan[j][i]==SPA) strcpy(p[j][i]," \0");
 if(qipan[j][i]==MAN) strcpy(p[j][i],"●\0");
 if(qipan[j][i]==COM) strcpy(p[j][i],"◎\0");}
 printf(" 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 \n"); 
 printf(" ┌—┬—┬—┬—┬—┬—┬—┬—┬—┬—┬—┬—┬—┬—┬—┐\n");
 for(i=0,j=0;i<14;i++,j++){
 printf(" %2d│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%d\n",j,p[i][0],p[i][1],p[i][2],p[i][3],p[i][4],p[i][5],p[i][6],p[i][7],p[i][8],p[i][9],p[i][10],p[i][11],p[i][12],p[i][13],p[i][14],j);
 printf(" ├—┼—┼—┼—┼—┼—┼—┼—┼—┼—┼—┼—┼—┼—┼—┤\n"); } 
 printf(" 14│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│0\n",p[14][0],p[14][1],p[14][2],p[14][3],p[14][4],p[14][5],p[14][6],p[14][7],p[14][8],p[14][9],p[14][10],p[14][11],p[14][12],p[14][13],p[14][14]); 
 printf(" └—┴—┴—┴—┴—┴—┴—┴—┴—┴—┴—┴—┴—┴—┴—┘\n");
 printf(" 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 \n");
}
int win(int p,int q) /* 判断胜利 p q为判断点坐标，胜利返回1，否则返回0 */
{
 int k,n=1,m,P,Q; /* k储存判断点p q的状态COM或MAN。P Q储存判断点坐标。n为判断方向。m为个数。 */
 P=p; Q=q;k=qipan[q][p];
 while(n!=5){
 m=0; 
 while(k==qipan[q][p]){
 m++;if(m==5) return 1; 
 yiwei(n,&p,&q); if(p<0||p>14||q<0||q>14) break;
 }
 n+=4; m-=1; p=P; q=Q; /* 转向判断 */
 while(k==qipan[q][p]){

m++;
 if(m==5) return 1; 
 yiwei(n,&p,&q); if(p<0||p>14||q<0||q>14) break;
 }
 n-=3; p=P; q=Q; /* 不成功则判断下一组方向 */
 }
 return 0;
}
void AI(int *p,int *q) /* 电脑下子 *p *q返回下子坐标 */
{
 int i,j,k,max=0,I,J; /* I J为下点坐标 */
 for(j=0;j<15;j++)
 for(i=0;i<15;i++)
 if(qipan[j][i]==SPA){ /* 历遍棋盘，遇到空点则计算价值，取最大价值点下子。 */
 k=value(i,j);if(k>=max) { I=i; J=j; max=k; }
 }
 *p=I; *q=J;
}
int value(int p,int q) /* 计算空点p q的价值 以k返回 */ 
{
 int n=1,k=0,k1,k2,K1,K2,X1,Y1,Z1,X2,Y2,Z2,temp; 
 int a[2][4][4]={40,400,3000,10000,6,10,600,10000,20,120,200,0,6,10,500,0,30,300,2500,5000,2,8,300,8000,26,160,0,0,4,20,300,0}; /* 数组a中储存己方和对方共32种棋型的值 己方0对方1 活0冲1空活2空冲3 子数0-3（0表示1个子，3表示4个子） */
 while(n!=5){
 k1=qixing(n,p,q); n+=4;/* k1,k2为2个反方向的棋型编号 */
 k2=qixing(n,p,q); n-=3;
 if(k1>k2) { temp=k1; k1=k2; k2=temp; } /* 使编号小的为k1,大的为k2 */
 K1=k1; K2=k2; /* K1 K2储存k1 k2的编号 */
 Z1=k1%10; Z2=k2%10; k1/=10; k2/=10; Y1=k1%10; Y2=k2%10; k1/=10; k2/=10; 
 X1=k1%10; X2=k2%10; /* X Y Z分别表示 己方0对方1 活0冲1空活2空冲3 子数0-3（0表示1个子，3表示4个子） */
 if(K1==-1) { 
 if(K2<0) { k+=0; continue; } else k+=a[X2][Y2][Z2]+5; continue; }; /* 空棋型and其他 */
 if(K1==-2) { if(K2<0) { k+=0; continue; } 
 else k+=a[X2][Y2][Z2]/2; continue; }; /* 边界冲棋型and其他 */ 
 if(K1==-3) { if(K2<0) { k+=0; continue; } 
 else k+=a[X2][Y2][Z2]/3; continue; }; /* 边界空冲棋型and其他 */ 
 if(((K1>-1&&K1<4)&&((K2>-1&&K2<4)||(K2>9&&K2<14)))||((K1>99&&K1<104)&&((K2>99&&K2<104)||(K2>109&&K2<114)))){
 /* 己活己活 己活己冲 对活对活 对活对冲 的棋型赋值*/
 if(Z1+Z2>=2) { k+=a[X2][Y2][3]; continue; }
 else { k+=a[X2][Y2][Z1+Z2+1]; continue; }
 }
 if(((K1>9&&K1<14)&&(K2>9&&K2<14))||((K1>109&&K1<114)&&(K2>109&&K2<114))){ 
 /* 己冲己冲 对冲对冲 的棋型赋值*/
 if(Z1+Z2>=2) { k+=10000; continue; }
 else { k+=0; continue; }
 }
 if(((K1>-1&&K1<4)&&((K2>99&&K2<104)||(K2>109&&K2<114)))||((K1>9&&K1<14)&&((K2>99&&K2<104)||(K2>109&&K2<114)))){
 /* 己活对活 己活对冲 己冲对活 己冲对冲 的棋型赋值*/
 if(Z1==3||Z2==3) { k+=10000; continue; }
 else { k+=a[X2][Y2][Z2]+a[X1][Y1][Z1]/4; continue; }
}
 else 
 { k+=a[X1][Y1][Z1]+a[X2][Y2][Z2]; continue; } /* 其他棋型的赋值 */ 
 }
 return k;
}
int qixing(int n,int p,int q) /* 返回空点p q在n方向上的棋型号 n为1-8方向 从右顺时针开始数 */ 
{
 int k,m=0; /* 棋型号注解: 己活000-003 己冲010-013 对活100-103 对冲110-113 己空活020-023 己空冲030-033 对空活120-123 对空冲130-133 空-1 边界冲-2 边界空冲-3*/
 yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) k=-2; /* 边界冲棋型 */
 switch(qipan[q][p]){
 case COM:{
 m++; yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=m+9; return k; }
 while(qipan[q][p]==COM) {
 m++; yiwei(n,&p,&q); if(p<0||p>14||q<0||q>14) { k=m+9; return k; } 
 }
 if(qipan[q][p]==SPA) k=m-1; /* 己方活棋型 */ 
 else k=m+9; /* 己方冲棋型 */
 }break;
 case MAN:{
 m++; yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=m+109; return k; }
 while(qipan[q][p]==MAN) {
 m++; yiwei(n,&p,&q); if(p<0||p>14||q<0||q>14) { k=m+109; return k; } 
 }
 if(qipan[q][p]==SPA) k=m+99; /* 对方活棋型 */
 else k=m+109; /* 对方冲棋型 */
 }break;
 case SPA:{
 yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=-3; return k; } /* 边界空冲棋型 */ 
 switch(qipan[q][p]){
 case COM:{
 m++; yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=m+29; return k; }
 while(qipan[q][p]==COM) { 
 m++; yiwei(n,&p,&q); 
 if(p<0||p>14||q<0||q>14) { k=m+29; return k; }
 }
 if(qipan[q][p]==SPA) k=m+19; /* 己方空活棋型 */
 else k=m+29; /* 己方空冲棋型 */
 }break;
 case MAN:{
 m++; yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=m+129; return k; }
 while(qipan[q][p]==MAN) { 
 m++; yiwei(n,&p,&q);
 if(p<0||p>14||q<0||q>14) { k=m+129; return k; } 
 } 
 if(qipan[q][p]==SPA) k=m+119; /* 对方空活棋型 */
 else k=m+129; /* 对方空冲棋型 */ 
 }break;
 case SPA: k=-1; break; /* 空棋型 */
 }
 }break;
 }
 return k;
}
void yiwei(int n,int *i,int *j) /* 在n方向上对坐标 i j 移位 n为1-8方向 从右顺时针开始数 */
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
 
