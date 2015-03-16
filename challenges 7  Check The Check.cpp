#include <cstdio>
#include <cstring>
#include <cmath>
char map[20][20];
int xb=0,yb=0,xw=0,yw=0,xbb,ybb,yww,xww;
int fp(int x,int y,int t)
{
	if (t==-1)
	{
		if ((map[x+t][y-1]=='k' || map[x+t][y+1]=='k'))
			return 1;
	}
	else
	{
		if ((map[x+t][y-1]=='K' || map[x+t][y+1]=='K'))
			return 1;
	}
	return 0;
}
int fr(int x,int y,int t)
{
	if (t==-1)
	{
		if (x>xb)
			{
				x=x+xb;
				xb=x-xb;
				x=x-xb;
			}
			if (y>yb)
			{
				y=y+yb;
				yb=y-yb;
				y=y-yb;
			}
		if (x==xb)
		{
			for (int i=y+1;i<yb;i++)
				if (map[x][i]!='.') return 0;
			return 1;
		}
		else 
		if (y==yb)
		{
			for (int i=x+1;i<xb;i++)
				if (map[i][y]!='.') return 0;
			return 1;
		}
		else return 0;	
	}
	else 
	{
			if (x>xw)
			{
				x=x+xw;
				xw=x-xw;
				x=x-xw;
			}
			if (y>yw)
			{
				y=y+yw;
				yw=y-yw;
				y=y-yw;
			}
		if (x==xw)
		{
			for (int i=y+1;i<yw;i++)
				if (map[x][i]!='.') return 0;
			return 1;
		}
		else 
		if (y==yw)
		{
			for (int i=x+1;i<xw;i++)
				if (map[i][y]!='.') return 0;
			return 1;
		}
		else return 0;
	}
	return 0;
}
int fb(int x,int y,int t)
{
	if (t==-1)
	{
		if (fabs(xb-x)!=fabs(yb-y)) return 0;
		else 
		{
			if (x>xb)
			{
				x=x+xb;
				xb=x-xb;
				x=x-xb;
			}
			if (y>yb)
			{
				y=y+yb;
				yb=y-yb;
				y=y-yb;
			}
			int k=yb-y;
			for (int i=1;i<k;i++)
			if (map[x+i][y+i]!='.') return 0;
			return 1;
		}
	}
	else 
	{
		if (fabs(xw-x)!=fabs(yw-y)) return 0;
		else 
		{
			if (x>xw)
			{
				x=x+xw;
				xw=x-xw;
				x=x-xw;
			}
			if (y>yw)
			{
				y=y+yw;
				yw=y-yw;
				y=y-yw;
			}
			int k=yw-y;
			for (int i=1;i<k;i++)
			if (map[x+i][y+i]!='.') return 0;
			return 1;
		}
	}
}
int fn(int x,int y,int t)
{
	if (t==-1)
	{
		return (fabs(x - xb) == 2 && fabs(y - yb) == 1) ||  
               (fabs(x - xb) == 1 && fabs(y - yb) == 2);  

	}
	else 
	{
		return (fabs(x - xw) == 2 && fabs(y - yw) == 1) ||  
               (fabs(x - xw) == 1 && fabs(y - yw) == 2);
	}
	return 0;
}
int main()
{
	int c=1;
	while (1)
	{
		memset(map,0,sizeof(map));
		int kb=0,kw=0;
		xbb=0;ybb=0;xww=0;yww=0;   // kbÊÇºÚÆå kwÊÇ°×Æå 
		for (int i=1;i<=8;i++)
		{
		for (int j=1;j<=8;j++)
		{
			scanf("%c",&map[i][j]);
			if (map[i][j]=='k')
			{xbb=i;ybb=j;}
			if (map[i][j]=='K')
			{xww=i;yww=j;}
		}
		getchar();
		}
		for (int i=1;i<=8;i++)
		{
		for (int j=1;j<=8;j++)
		{
			xb=xbb;xw=xww;yb=ybb;yw=yww;
			if (map[i][j]=='P')
				kb=fp(i,j,-1);
			if (map[i][j]=='p')
				kw=fp(i,j,1);
			if (map[i][j]=='R')
				kb=fr(i,j,-1);
			if (map[i][j]=='r')
				kw=fr(i,j,1);
			if (map[i][j]=='B')
				kb=fb(i,j,-1);
			if (map[i][j]=='b')
				kw=fb(i,j,1);
			if (map[i][j]=='Q')
			{
				kb=fr(i,j,-1);
				xb=xbb;xw=xww;yb=ybb;yw=yww;
				kb+=fb(i,j,-1);
			}
			if (map[i][j]=='q')
			{
				kw=fr(i,j,1);
				xb=xbb;xw=xww;yb=ybb;yw=yww;
				kw+=fb(i,j,1);
			}
			if (map[i][j]=='N')
				kb=fn(i,j,-1);
			if (map[i][j]=='n')
				kw=fn(i,j,1);
			if (kb || kw) break;	
		}
		if (kb || kw) break;
		}
		if (xb+yb+xw+yw==0) break;
		if (kw) printf("Game #%d: white king is in check.\n",c++);
		if (kb) printf("Game #%d: black king is in check.\n",c++);
		if (!(kb+kw)) printf("Game #%d: no king is in check.\n",c++);
		getchar();
	}
	return 0;
}
