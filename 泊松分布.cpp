//���ɷֲ���ʽP(X=k)=(e^(-p)*p^k)/(k!) p����ǰ�ܻ�õ�����,kΪĿ���õ�ֵ��
//�������������1�����������ٵ�������p,����Ҫ��1���������ٲ�����k�� 
//p(x<=k)=p(0)+p(1)+p(2)+p(3)+....p(k) 
#include <stdio.h>
#include <math.h> 
int main()
{
	int t,i,n;
	double m;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%lf",&n,&m);
		double k=1.000;
		double s=exp(-m); 
		for (i=1;i<=n;i++)
		{
			k*=(i*1.000);
			s+=exp(-m)*pow(m,i)/k;
		}
		printf("%0.3lf\n",s);
	}
	return 0;
}
