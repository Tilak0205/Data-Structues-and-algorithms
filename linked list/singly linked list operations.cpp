#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
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
	printf("Singly linked list operations\n\n");
	while(1)
	{
		printf("\n\n1.Append Data\n");
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

///////////////////////////////////////////////////////////////////

void append(void)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the data: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL) //if the list is empty this will execute
	{
		head=temp;
	}
	else{
		struct node *p;
		p=head;
		while(p->link!=NULL){
			p=p->link;
		}
		p->link=temp;
	}
}
////////////////////////////////////////////////////////////////////
int length(void){
	int count=0;
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}
////////////////////////////////////////////////////////////////////
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
			temp=temp->link;
		}
	}
	printf("\n\n");
}
/////////////////////////////////////////////////////////////////////////////////////
void addatbegin(void)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the data: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
		temp->link=head;
		head=temp;
	}
}
///////////////////////////////////////////////////////////////////////////
void addatafter(void)
{
	struct node *temp,*p;
	int loc,len,i=1;
	printf("\nenter the location to add: ");
	scanf("%d",&loc);
	len=length();
	if(loc>len){
		printf("\ninvalid location\n\n");
	}
	else{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\nenter the data: ");
		scanf("%d",&temp->data);
		temp->link=NULL;
		p=head;
		while(i<loc-1){
			p=p->link;
			i++;
		}
		temp->link=p->link;
		p->link=temp;
	}
}
//////////////////////////////////////////////////////////////////////////////////
void deletedata(void)
{
	int loc=0;
	struct node *temp;
	printf("enter the loc: ");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("\nInvalid locaiton..");
	}
	else if(loc==1){
		temp=head;
		head=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else{
		struct node *p,*q;
		p=head;
		int i=1;
		while(i<loc-1){
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}

////////////////////////////////////////////////////////////////////////
void reverselist(void)
{
	struct node *prevnode,*currentnode,*nextnode;
	prevnode=0;
	currentnode=nextnode=head;
	while(nextnode!=0){
		nextnode=currentnode->link;
		currentnode->link=prevnode;
		prevnode=currentnode;
		currentnode=nextnode;
	}
	head=prevnode;
}


