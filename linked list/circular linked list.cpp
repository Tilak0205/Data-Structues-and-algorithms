#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
///////////////////////////////////////////////////////////////////////
void append(void)
{
	struct node *newnode,*temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
	}
	else{
		temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=newnode;
	}
	newnode->next=head;
}
///////////////////////////////////////////////////////////////////////
void addatbegin(void)
{
	struct node *temp,*newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the data: ");
	scanf("%d",&newnode->data);
	if(head==NULL){
		head=newnode;
		newnode->next=newnode;
	}
	else{
		p=temp=head;
		newnode->next=head;
		head=newnode;
		while(temp->next!=p){
			temp=temp->next;
		}
		temp->next=newnode;
	}		
}
///////////////////////////////////////////////////////////////////////
int length(void);
void addatafter(void)
{
	int pos,i;
	int len=length();
	struct node *newnode,*p,*q;
	printf("\nEnter the position to add: ");
	scanf("%d",&pos);
	newnode=(struct node*)malloc(sizeof(struct node));
	
	newnode->next=0;
	p=head;
	if(pos<len && pos>1)
	{
		printf("\nenter the data: ");
		scanf("%d",&newnode->data);
		i=1;
		while(i<pos-1)
		{
			p=p->next;
			i++;
		}
		q=p->next;
		newnode->next=q;
		p->next=newnode;
	}
	else{
		printf("\nIvalid Entry\n");
	}
}
///////////////////////////////////////////////////////////////////////
int length(void)
{
	struct node *temp;
	int len=1;
	temp=head;
	while(temp->next!=head){
		len++;
		temp=temp->next;
	}
	return len;
}
///////////////////////////////////////////////////////////////////////
void display(void)
{
	struct node *temp;
	temp=head;
	if(head==NULL){
		printf("\nlist is empty\n");
	}
	else{
		while(temp->next!= head)
		{
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
	}
}
///////////////////////////////////////////////////////////////////////
void deletedata(void)
{
	int pos,len=length(),i;
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	struct node *temp,*p,*q;
	if(pos==1){
		//deletion at beginning
		temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=head->next;
		head->next=0;
		free(head);
		head=temp->next;
	}
	else if(pos==length()){
		int i=1;
		temp=head;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		temp->next->next=0;
		free(temp->next);
		temp->next=head;
	}
	else if(pos<length() && pos>1){
		int i=1;
		p=head;
		while(i<pos-1){
			p=p->next;
			i++;
		}
		q=p->next;
		p->next=q->next;
		q->next=0;
		free(q);		
	}
}
///////////////////////////////////////////////////////////////////////
void reverse(void)
{
	struct node *prev,*cur,*tail;
	if(head==NULL){
		printf("\nNO items to reverse the list:");
	}
	else{
		tail=prev=head;
		cur=head->next;
		head=head->next;
		while(head!=tail){
			head=head->next;
			cur->next=prev;
			prev=cur;
			cur=head;
		}
		cur->next=prev;
		head=prev;
	}
}
///////////////////////////////////////////////////////////////////////
int main()
{
	int ch;int len;
	while(1){
		printf("\n\nCircular Linked List Operations\n\n");
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


