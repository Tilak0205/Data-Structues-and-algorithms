#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
//..........................................................................
void enqueue(void)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(front==0 && rear==0){
		front=rear=newnode;
	}
	else{
		rear->next=newnode;
		rear=newnode;
	}
}
//..........................................................................
int dequeue(void)
{
    struct node *temp;
	if(front==0 && rear==0)
	{
		printf("Underflow");
	}
    else if(front->next==NULL)
    {
         temp=front;
         front=rear=0;
         return temp->data;
         free(temp);
	}
    else
    {
        temp = front;
        front = front->next;
		return temp->data;
       	free(temp);
    }
}
//..........................................................................
void peek(void)
{
	if(front==0){
		printf("\nThe queue is empty");
	}
	else{
		printf("%d is the peek value",front->data);
	}
}
//..........................................................................
void display(void)
{
	struct node *temp;
	temp=front;
	if(temp==NULL){
		printf("\nQueue is empty...");
	}
	else{
		while(temp!=0){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
//..........................................................................
int main()
{
	int ch;
	while(1){
		printf("\n\nQueue using linked list operations");
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\n5.Exit");
		printf("\n\nChoose any option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: enqueue();break;
			case 2: int x;x=dequeue();printf("%d is dequeued dta",x);break;
			case 3: peek();break;
			case 4: display();break;
			case 5: exit(1); break;
			default: printf("\nIvalid option");
		}
	}
}


