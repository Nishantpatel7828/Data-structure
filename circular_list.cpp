#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	node *next,*prev;
};
node *first,*temp,*ttemp,*p;
void init()
{
	first=temp=ttemp=p=NULL;
}
void create_first(int val)
{
	first=(node*) malloc(sizeof(node));
	first->data=val;
	first->next=first;
	first->prev=first;
}
void Add_Nodes(int val)
{
	temp=first->prev;
	ttemp=(node*)malloc(sizeof(node));
	ttemp->data=val;
	ttemp->next=first;
	ttemp->prev=temp;
	temp->next=ttemp;
	first->prev=ttemp;
	
}
void del_first()
{
	p=temp=first;
	ttemp=temp->prev;
	temp=first->next;
	ttemp->next=temp;
	temp->prev=ttemp;
	p->prev=NULL;
	p->prev=NULL;
		free(p);
		first=temp;
	
}
void disp()
{
	temp=first;
	do
	{
		cout<<temp->data;
		temp=temp->next;
	}
	while(temp!=first);
}
int main()
{
	init();
	create_first(10);
    Add_Nodes(30);
	Add_Nodes(30);
	Add_Nodes(40);
	Add_Nodes(50);
	del_first();
	disp();
}


