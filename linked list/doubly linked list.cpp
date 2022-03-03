#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head=NULL;
int len;

void append(void);
void addatbegin(void);
void addatafter(void);
int length(void);
void display(void);
void deletedata(void);
void reverselist(void);

int main()
{
	int ch;
	printf("Doubly linked list operations\n\n");
	while(1)
	{
		printf("1.Append Data\n");
		printf("2.Add at begin\n");
		printf("3.Add at after\n");
		printf("4.Length\n");
		printf("5.Display\n");
		printf("6.Delete\n");
		printf("7.Reverse list\n");
		printf("8.Quit\n");
		printf("Choose one option: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				append(); break;
			case 2:
				addatbegin();break;
			case 3:
				addatafter();break;
			case 4:
				len=length();
				printf("\nLength is %d\n\n",len);
				break;
			case 5:
				display();break;
			case 6:
				deletedata();break;
			case 7:
				reverselist();break;
			case 8:
				exit(1); break;
			default:
				printf("\nenter the valid option: ");
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
void append(void)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the data: ");
	scanf("%d",&newnode->data);
	newnode->prev=0;
	newnode->next=0;
	if(head==NULL){
		head=newnode;
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
	}
}
//////////////////////////////////////////////////////////////////////////////
void addatbegin(void)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the data: ");
	scanf("%d",&newnode->data);
	newnode->prev=NULL;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
	}
	else{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
}
//////////////////////////////////////////////////////////////////////////////
void addatafter(void)
{
	struct node *temp,*newnode;
	int loc,len,i=1;
	printf("\nenter the location: ");
	scanf("%d",&loc);
	len=length();
	if(loc>len){
		printf("\nIvalid location\n\n");
	}
	else{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nenter the data: ");
		scanf("%d",&newnode->data);
		newnode->prev=0;
		newnode->next=0;
		temp=head;
		while(i<loc-1){
			temp=temp->next;
			i++;
		}
		newnode->next=temp->next;
		temp->next->prev=newnode;
		newnode->prev=temp;
		temp->next=newnode;	
	}
}
//////////////////////////////////////////////////////////////////////////////
int length(void)
{
	struct node *temp;
	int count=0;
	temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}
//////////////////////////////////////////////////////////////////////////////
void display(void)
{
	struct node *temp;
	temp=head;
	if(temp==NULL){
		printf("\nlist is empty\n");
	}
	else{
		while(temp!=NULL){
			printf("%d-->",temp->data);
			temp=temp->next;
		}
	}
	printf("\n\n");
}
//////////////////////////////////////////////////////////////////////////////
void deletedata(void)
{
	struct node *temp;
	int loc;
	printf("\nenter the location to delete: ");
	scanf("%d",&loc);
	if(loc>length()){
		printf("\nInvalid Location\n\n");
	}
	else if(loc==1){
		temp=head;
		head=temp->next;
		temp->next->prev=NULL;
		temp->next=NULL;
	}
	else if(loc<length())
	{
		int i=1;
		struct node *p,*q;
		p=head;
		while(i<loc-1){
			p=p->next;
			i++;
		}
		q=p->next;
		p->next=q->next;
		q->next->prev=p;
		free(q);
	}
	else if(loc==length())
	{
		int i=1;
		temp=head;
		while(i<loc-1)
		{
			temp=temp->next;
			i++;
		}
		temp->next->prev=0;
		free(temp->next);
		temp->next=0;
	}
}
//////////////////////////////////////////////////////////////////////////////
void reverselist(void)
{
	struct node *temp,*p;
	temp=head;
	p=temp->next;
	temp->next=0;
	temp->prev=p;
	while(p!=NULL)
	{
		p->prev=p->next;
		p->next=temp;
		temp=p;
		p=p->prev;
	}
	head=temp;
}
//////////////////////////////////////////////////////////////////////////////


