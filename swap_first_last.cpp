#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	node *next,*prev;
};
node *first,*temp,*ttemp,*p,*q;
void init()
{
	first=temp=ttemp=p=q=NULL;
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
void swap_first_last()
{
	p=temp=first;
	temp=temp->next;
	ttemp=p->prev;
	q=ttemp->prev;
	q->next=p;
	p->prev=q;
	p->next=ttemp;
	ttemp->prev=p;
	ttemp->next=temp;
	temp->prev=ttemp;
	first=ttemp;
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
	Add_Nodes(20);
	Add_Nodes(30);
	Add_Nodes(40);
	Add_Nodes(50);
	swap_first_last();
	disp();
}


