#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
int main()
{
	struct node *head,*newnode;
	head=(struct node*)malloc(sizeof(struct node));
	head->data=45;
	head->link=NULL;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=90;
	newnode->link=NULL;
	head->link=newnode;
	return 0;
}


