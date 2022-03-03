#include<stdio.h>
#include<stdlib.h>
#define N 5
//.........................................................................
int queue[N];
int front =-1;
int rear=-1;
//.........................................................................
void enqueue(void)
{
	int x;
	printf("\nEnter the Data: ");
	scanf("%d",&x);
	if(rear==N-1){
		printf("\nOverflow");
	}
	else if(front==-1 && rear==-1){
		front=rear=0;
		queue[rear]=x;
	}
	else{
		rear++;
		queue[rear]=x;
	}
}
//.........................................................................
void dequeue(void)
{
	if(front==-1 && rear==-1){
		printf("\nQueue is empty");
	}
	else if(front==rear){
		front=rear=-1;
	}
	else{
		front++;
	}
}
//.........................................................................
void display(void)
{
	int i;
	if(front==-1 && rear==-1){
		printf("\nQueue is empty..");
	}
	else{
		for(i=front;i<=rear;i++){
			printf("%d ",queue[i]);
		}
	}
}
//.........................................................................
void peek(void)
{
	if(front==-1 && rear==-1){
		printf("\nQueue is empty");
	}
	else{
		printf("\n%d is the peek value",queue[front]);
	}
}
//.........................................................................
int main()
{
	int ch;
	while(1){
		printf("\n\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display");
		printf("\n4.Peek");
		printf("\n5.Exit");
		printf("\n\nChoose any option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: enqueue(); break;
			case 2: dequeue(); break;
			case 3: display(); break;
			case 4: peek(); break;
			case 5: exit(1);
			default: printf("\nEnter valid option....");
		}
	}
}


