#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
Node *first,*temp,*ttemp;
void init()
{
	first=temp=ttemp=NULL;
	
}
void create_first(int x)
{
	first=(Node*) malloc(sizeof(Node));
	first->data=x;
	first->next=NULL;
}
void Add_Node(int x)
{
	temp=first;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	ttemp=(Node*)malloc(sizeof(Node));
	ttemp->data=x;
	ttemp->next=NULL;
	temp->next=temp;
}
void disp()
{
	temp=first;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}
int main()
{
	init();
	create_first(15);
	Add_Node(20);
    Add_Node(30);
	Add_Node(40);
	Add_Node(50);
	Add_Node(60);
	disp();
	
	}
