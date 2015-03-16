#include <iostream>
//using namespace std;
class add
{
	public:
	add()
	{
		s=x=0;
	}
	add(double i,double j)
	{
		s=i;
		x=j;
	}
	add operator + (add &c2)
	{
		return add(s+c2.s,x+c2.x);
	} 
	void display();
	private:
		double s;
		double x;
};
void add::display()
{
	std:: cout<<s<<"£¬"<<x<<"i"<<&std::endl;
}
int main()
{
	add c1(3,4),c2(5,-10),c3;
	c3=c1+c2;
	c1.display();
	c2.display();
	c3.display();
	return 0;
} 
