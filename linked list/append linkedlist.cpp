#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
int main()
{
	struct node *temp,*head,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the data: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL) //if the list is empty this will execute
	{
		head=temp;
	}
	else{
		p=head;
		while(p->link!=NULL){
			p=p->link;
		}
		p=temp;
	}
}

