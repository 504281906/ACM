#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct Node
{
    int data;
    struct Node *next;
}*LinkList;
LinkList L;
LinkList InitList()
{
    int e;
    scanf("%d",&e);
    while(e!=-1)
    {
        Node *p;
        p=(Node *)malloc(sizeof(Node));
        p->data=e;
        L->next=p;
        L=p;
        scanf("%d",&e);
    }
    L->next=NULL;
    return L;
}
int main()
{
	LinkList head =new Node;
	head->data=0;
	head->next=NULL;
	L=head;
    L=InitList();
    L=head;
    while(L->next!=NULL)
    {
        printf("%d\t",L->data);
        L=L->next;
    }
    return 0;
}
