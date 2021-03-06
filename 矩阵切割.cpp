/矩形切割
//intersect函数构造矩形a和b的交集
//cut函数将b关于a进行切割,用切下的矩形作参数调用dummy函数
struct rect{
	int x1,x2,y1,y2;
	rect(){}
	rect(int a,int b,int c,int d):x1(a),x2(b),y1(c),y2(d){}
};

inline rect intersect(rect& a,rect& b){
	return rect(a.x1>b.x1?a.x1:b.x1,a.x2<b.x2?a.x2:b.x2,a.y1>b.y1?a.y1:b.y1,a.y2<b.y2?a.y2:b.y2);
}

void dummy(rect a){
	//dispose this rect
}

int cut(rect& a,rect b){
	rect c=intersect(a,b);
	if (c.x1>=c.x2||c.y1>=c.y2)
		return 0;
	if (b.x1<c.x1)
		dummy(rect(b.x1,c.x1,b.y1,b.y2)),b.x1=c.x1;
	if (b.x2>c.x2)
		dummy(rect(c.x2,b.x2,b.y1,b.y2)),b.x2=c.x2;
	if (b.y1<c.y1)
		dummy(rect(b.x1,b.x2,b.y1,c.y1)),b.y1=c.y1;
	if (b.y2>c.y2)
		dummy(rect(b.x1,b.x2,c.y2,b.y2)),b.y2=c.y2;
	return 1;
}
