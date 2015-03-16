#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct NUM{
			NUM *last;
			NUM *next;
			__int64 value;
		};
class list
{
	public:
		
		list();
		void insert(__int64 x);
		__int64 query(__int64 x);
		void remove(__int64 x); 
		NUM* getpos(__int64 x); 
		void del(NUM *p);
		NUM *top;
		NUM *bot;
		bool em;
};
void list::insert(__int64 x)
{
	if(em)
	{
		top = new NUM;
		bot = new NUM;
		top->next = bot;
		top->last = NULL;
		top->value = 1;
		bot->last = top;
		bot->next = NULL;
		bot->value = -1;
		em = false;
	}
	NUM *p = new NUM;
	NUM *ks = getpos(x);
	p->last = ks->last;
	p->next = ks;
	ks->last = p;
	//p->value = 
	if(x == 0)
		top = p;
	NUM *p2 = new NUM;
	bot->next = p2;
	p2->last = bot;
	p2->next = NULL;
	bot = p2;
	//p2->value = 
}
NUM *list::getpos(__int64 x)
{
	if(x == 0)
	{
		return top;
	}
	NUM *p = top;
	while(x--)
	{
		p = p->next;
	}
	return p;
}
__int64 list::query(__int64 x)
{
	NUM *p = getpos(x);
	NUM *k = p->next;
	__int64 num = 0;
	while(k->value != p->value)
	{
		num += k->value;
		k = k->next;
	}
	return num;
}
void list::remove(__int64 x)
{
	NUM *p = getpos(x);
	NUM *k = p->next;
	while (k->value != p->value)
	{
		k = k->next;
	}
	del(k);
	del(p);
}
void list::del(NUM *p)
{
	p->last->next = p->next;
	p->next->last = p->last;
	delete p;
}
list::list()
{
	top = NULL;
	bot = NULL;
	em = true;
}
int main()
{
	__int64 n;
	while(cin>>n)
	{
		while(n--)
		{ 
		list li;
		char a[100];
		__int64 x;
		scanf("%s",a);
		scanf("%I64d",&x);
		switch(a[0])
		{
			case 'i':
				li.insert(x);
				break;
			case 'r':
				li.remove(x);
				break;
			case 'q':
				cout<<li.query(x)<<endl;;
				break;
		} 
		}
	}
}
