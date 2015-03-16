 #include<stdio.h>
 #include<string.h>
 using namespace std;
 #define maxn 10005
 
 struct NODE 
 {
 	int x,y;
 	int ans;
 }node[maxn];
 int n;
 
 void cover(int l,int r,int k,int c)
 {
 	while(k<n&&(r<node[k].x||l>node[k].y)) //完全不覆盖
 		k++;
 	
 	if(k>=n) //if(k>=n||(r-l+1<=0))
 	{
 		node[c].ans+=r-l+1; 
 		return;
 	}
 	if(l<node[k].x) //右边部分被覆盖
 	{ 
 		cover(l,node[k].x-1,k+1,c);
 		//l=node[k].x;
 	}
 	if(r>node[k].y) //左边部分被覆盖
 	{
 		cover(node[k].y+1,r,k+1,c);
 		//r=node[k].y;
 	}
 }
 
 int main()
 {
 	int t,i,j,sum;
 	scanf("%d",&t);
 	while(t--)
 	{
 		sum=0;
 		memset(node,0,sizeof(node));
 		scanf("%d",&n);
 		for(i=0;i<n;i++)
			scanf("%d%d",&node[i].x,&node[i].y);
 		for(i=n-1;i>=0;i--)
			cover(node[i].x,node[i].y,i+1,i); 
 		for(i=0;i<n;i++) 
 			if(node[i].ans>0)
 				sum++;
 		printf("%d\n",sum);
 	}
 	return 0;
}
