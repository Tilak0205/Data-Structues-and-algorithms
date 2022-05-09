#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int priority;
	struct node *next;
};
struct node *head=NULL;
int isempty()
{
	if(head==0){
		return 1;
	}
	else
		return 0;
}

void insert(int x,int y)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->priority=y;
	newnode->next=0;
	if(head==0){
		head=newnode;
	}
	else if(head->priority <=y){
		newnode->next=head;
		head=newnode;
	}
	else{
		temp=head;
		while(temp->next!=0 && temp->next->priority>y){
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}

void display()
{
	if(isempty()){
		printf("The queue is empty..");
	}
	else{
		struct node *temp=head;
		while(temp!=0){
			printf("\n%d element %d priority",temp->data,temp->priority);
			temp=temp->next;
		}
	}
}
int gethighestpriority()
{
	if(isempty()){
		printf("\nThe queue is empty");return 0;
	}
	else{
		return head->data;
	}
}
int DeleteHighestPriority()
{
	struct node *temp;
	if(head==0){
		printf("Queue Underflow");
	}
	else{
		temp=head;
		head=head->next;
		return temp->data;
		free(temp);
	}
}

int main()
{
	int ch;
	printf("\nPriority queue using arrays\n");
	while(1){
		printf("\n\n1.Insert\n");
		printf("2.Get Highest priority\n");
		printf("3.Display\n");
		printf("4.Delete\n");
		printf("5.Exit\n");
		printf("choose any option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				int x,y;
				printf("\nEnter the element to insert: ");
				scanf("%d",&x);
				printf("\nEnter the priority of element: ");
				scanf("%d",&y);
				insert(x,y);					
				break;
			case 2:
				printf("\nThe highest priority element is %d\n",gethighestpriority());
				break;
			case 3: display();printf("\n");break;
			case 4:
				if(isempty()){
					printf("\n\nThe queue is empty...\n");
				}
				else{
					int d=DeleteHighestPriority();
					printf("\n%d is deleted successfully..\n",d);
				}
				break;
			case 5: exit(1);break;
			default: printf("\nChoose correct option..\n");
		}
	}
}

