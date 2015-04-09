#include <iostream>
using namespace std;

int qi[8][8];

void print_h(int h)
{
	cout << "     " << (char)(h+65) << "╟";
	for (int k=0; k<8; k++)
	{
		switch (qi[h][k])
		{   case 0: cout << "┼"; break;
		    case 1: cout << "◎"; break;
			case 2: cout << "●"; break;
		}
	}
	cout << "╢" << endl;
}

void print()
{
	cout << "        ０１２３４５６７" << endl;
	cout << "      ╔╤╤╤╤╤╤╤╤╗" << endl;
	for (int l=0; l<8; l++)
		print_h(l);
	cout << "      ╚╧╧╧╧╧╧╧╧╝" << endl;
}

void xiugai(int hang, int lie, int heng, int zong, int num)
{
	for (int i=1; i<=num; i++)
	{
		hang+=heng; lie+=zong;
		qi[hang][lie]=3-qi[hang][lie];
	}
}

int panduan(int count, int shu, int se)
{
	int out; // out=0:不继续; out=1:继续; out=2:不继续并返回成功;
    if (shu==0) out=0;
	else if (shu==(3-se)) out=1;
	     else if (count==1) out=0;
		      else out=2;
	return out;
}

bool chuli(int se, int i, int j, bool leixing)
{
	bool ctrl=false;
	int flag=1;
	int hang=i; int lie=j;
	int count=0;
	while (hang>0 && flag==1) // 向上判断
	{
		hang--;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,-1,0,count-1); ctrl=true; }
	             else ctrl=true;

	flag=1;
	count=0;
    hang=i; lie=j;
	while (hang<7 && flag==1) // 向下判断
	{
		hang++;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,1,0,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (lie>0 && flag==1) // 向左判断
	{
		lie--;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,0,-1,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (lie<7 && flag==1) // 向右判断
	{
		lie++;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,0,1,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (hang>0 && lie>0 && flag==1) // 向左上判断
	{
		hang--; lie--;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,-1,-1,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (hang<7 && lie<7 && flag==1) // 向右下判断
	{
		hang++; lie++;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,1,1,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (hang>0 && lie<7 && flag==1) // 向右上判断
	{
		hang--; lie++;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,-1,1,count-1); ctrl=true; }
                 else ctrl=true;
	flag=1;
	count=0;
    hang=i; lie=j;
	while (hang<7 && lie>0 && flag==1) // 向左下判断
	{
		hang++; lie--;
		count++;
		flag=panduan(count, qi[hang][lie], se);
	}
	if (flag==2) if (leixing) {   xiugai(i,j,1,-1,count-1); ctrl=true; }
                 else ctrl=true;
	if (ctrl && leixing) qi[i][j]=se;
	return ctrl;
}


int main()
{
	bool ctrl=false, ctrl_all=false, ctrl_1=false, ctrl_2=false;
	int j=0,i;
	int n=1;
	int se=2;
	char h,l;
	int lie, hang;	
	int count_hei=0; int count_bai=0;
	for (int i=0; i<8; i++)
		for (j=0; j<8; j++)
			qi[i][j]=0;
	qi[3][3]=1; qi[4][4]=1; qi[3][4]=2; qi[4][3]=2;
	while (n<61)
	{
		se=3-se;
		for (i=0; i<8; i++)
		{
			for (j=0; j<8; j++)
			{
				if (qi[i][j]==0)
				{
					ctrl_1=(ctrl_1 || chuli(1, i, j, false));
					if (ctrl_1 && ctrl_2) break;
					ctrl_2=(ctrl_2 || chuli(2, i, j, false));
					if (ctrl_1 && ctrl_2) break;
				}
			}
			if (ctrl_1 && ctrl_2) break;
		}
		if (!(ctrl_1 || ctrl_2)) break;
		if ((!ctrl_1) && ctrl_2 && (se==1)) continue;
		if ((!ctrl_2) && ctrl_1 && (se==2)) continue;
		count_hei=0; count_bai=0;
		for (i=0; i<8; i++)
			for (j=0; j<8; j++)
			{
			    if (qi[i][j]==1) count_hei++;
			    else if (qi[i][j]==2) count_bai++;
			}
		print();
		cout << "     黑方 " << count_hei << " : " << count_bai << " 白方" << endl;
		if (se==1) cout << "     黑方下子" << endl;
		else cout << "     白方下子" << endl;
		while (!ctrl)
		{
			cout << "     ";
			cin >> h >> l;
		    cout << endl;
		    hang=h-65; lie=l-48;
			if (qi[hang][lie]!=0) ctrl=false;
		    else ctrl=chuli(se, hang, lie, true);
			if (!ctrl) cout << "     此处不能落子!" << endl;
		}
		ctrl=false; ctrl_1=false; ctrl_2=false;
		n++;
	}
	count_hei=0; count_bai=0;
	for (i=0; i<8; i++)
		for (j=0; j<8; j++)
		{
			if (qi[i][j]==1) count_hei++;
			else if (qi[i][j]==2) count_bai++;
		}
	print();
	cout << "     黑方 " << count_hei << " : " << count_bai << " 白方" << endl;
	if (count_hei>count_bai) cout << "     黑方胜!" << endl;
	else if (count_hei<count_bai) cout << "     白方胜!" << endl;
	     else cout << "     打平了!" << endl;
	cout << "     按任意键退出..." << endl;
	cin >> i;
	return 0;
}
