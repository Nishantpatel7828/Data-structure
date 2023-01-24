#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct tree
{
	int data;
	tree*left,*right,*parent;

};
tree *root,*temp,*ttemp,*p;
void init()
{
	root=temp=ttemp=p=NULL;
}
void create_root(int val)
{
	root=(tree*)malloc(sizeof (tree));
	root->data=val;
	root->left=NULL;
	root->right=NULL;
	
}
void Add_Nodes(int val)
{
	temp=root;
	while(temp!=NULL)
	{
		ttemp=temp;
		if(temp->data>val)
		temp=temp->left;
		else
		temp=temp->right;
	}
	p=(tree*)malloc(sizeof (tree));
	p->data=val;
	p->left=NULL;
	p->right=NULL;
	if(ttemp->data>val)
	ttemp->left=p;
	else
	ttemp->right=p;
}
void inorder(tree*p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->data;
		
		inorder(p->right);
	}
}
int getlevel(tree*p,int val,int level)
{
	if(p==NULL)
	return 0;
	if(p->data==val)
	return level;
	int downlevel=getlevel(p->left,val,level+1);
	if(downlevel!=0)
	return downlevel;
	downlevel=getlevel(p->right,val,level+1);
	return downlevel;
}
int main()
{
	init();
	create_root(50);
	Add_Nodes(40);
	Add_Nodes(60);
	Add_Nodes(45);
	Add_Nodes(35);
	Add_Nodes(70);
	Add_Nodes(65);
	Add_Nodes(75);
	inorder(root);
    getlevel(root,75,0);
}
