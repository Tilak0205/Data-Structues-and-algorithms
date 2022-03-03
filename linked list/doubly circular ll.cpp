#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
///////////////////////////////////////////////////////////////////////
void append(void)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&newnode->data);
	if(head==NULL){
		head=tail=newnode;
		newnode->prev=newnode->next=head;
	}
	else{
		tail->next=newnode;
		newnode->prev=tail;
		newnode->next=head;
		head->prev=newnode;
		tail=newnode;
	}
}
///////////////////////////////////////////////////////////////////////
void addatbegin(void)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&newnode->data);
	if(head==NULL){
		head=tail=newnode;
		newnode->prev=newnode->next=head;
	}
	else{
		newnode->next=head;
		head->prev=newnode;
		newnode->prev=tail;
		tail->next=newnode;
		head=newnode;
		/*tail=head;
		while(tail->next!=head){
			tail=tail->next;
		}
		tail->next=newnode;
		newnode->next=head;
		newnode->prev=tail;
		head->prev=newnode;
		head=newnode;*/
	}
}
///////////////////////////////////////////////////////////////////////
int length(void);
void addatafter(void)
{
	int pos,i;
	printf("\nenter the position to insert: ");
	scanf("%d",&pos);
	if(pos<length() && pos>1)
	{
		struct node *p,*q,*newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter the data: ");
		scanf("%d",&newnode->data);
		i=1;
		p=head;
		while(i<pos-1){
			p=p->next;
			i++;
		}
		q=p->next;
		newnode->next=q;
		newnode->prev=p;
		q->prev=newnode;
		p->next=newnode;
	}
	else if(pos==1){
		addatbegin();
	}
	else if(pos==length()){
		append();
	}
	else{
		printf("\nINVALID position\n");
	}
}
///////////////////////////////////////////////////////////////////////
int length(void)
{
	int len=0;
	if(head==NULL){
		printf("\nList is empty\n");
	}
	else{
		struct node *temp;
		temp=head;
		while(temp->next!=head){
			len++;
			temp=temp->next;
		}
		len++;
		return len;
	}
}
///////////////////////////////////////////////////////////////////////
void display(void)
{
	struct node *temp;
	temp=head;
	if(head==NULL){
		printf("\nList is empty\n");
	}
	else{
		while(temp->next!=head){
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
	}
}
///////////////////////////////////////////////////////////////////////
int length(void);
void deletedata(void)
{
	int pos;
	printf("\nEnter the position to delete: ");
	scanf("%d",&pos);
	if(pos==1){
		if(length()==1){
			head=NULL;
		}
		else{
			struct node *temp;
			temp=head->next;
			head->next=NULL;
			head->prev=NULL;
			temp->prev=tail;
			tail->next=temp;
			head=temp;
		}	
	}
	else if(pos==length()){
		struct node *temp;
		temp=tail;
		tail=temp->prev;
		temp->next=temp->prev=NULL;
		free(temp);
		tail->next=head;
		head->prev=tail;	
	}
	else if(pos<length() && pos>1){
		int i=1;
		struct node *p,*q;
		p=head;
		while(i<pos-1){
			p=p->next;
			i++;
		}
		q=p->next;
		q->next->prev=p;
		p->next=q->next;
		q->next=q->prev=NULL;
		free(q);
	}
}
///////////////////////////////////////////////////////////////////////
void reverse(void)
{
	struct node *current,*nextnode;
	current=head;
	nextnode=current->next;
	while(current!=tail){
		current->next=current->prev;
		current->prev=nextnode;
		current=nextnode;
		nextnode=nextnode->next;
	}
	current->next=current->prev;
	current->prev=head;
	head=current;
	tail=current->prev;
}
///////////////////////////////////////////////////////////////////////
int main()
{
	int ch;int len;
	while(1){
		printf("\n\nDoubly Circular Linked List Operations\n\n");
		printf("1.Append Data\n");
		printf("2.Add at begin\n");
		printf("3.Add at after\n");
		printf("4.Length\n");
		printf("5.Display\n");
		printf("6.Delete\n");
		printf("7.Reverse list\n");
		printf("8.Quit\n");
		printf("\nChoose one option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				append();break;
			case 2:
				addatbegin();break;
			case 3:
				addatafter();break;
			case 4:
				len=length();printf("\nlength is %d\n",len);break;
			case 5:
				display();break;
			case 6:
				deletedata();break;
			case 7:
				reverse();break;
			case 8:
				exit(1);break;
			default:
				printf("\nEnter valid option\n");
		}
	}
}


