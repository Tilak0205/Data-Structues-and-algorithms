#include<stdio.h>
#include<stdlib.h>
#define n 5
int queue[n];
int front=-1;
int rear=-1;
//............................................................................
void enqueue()
{
	int x;
	printf("\nEnter the data: ");
	scanf("%d",&x);
	if(front==-1 && rear==-1){
		front=rear=0;
		queue[rear]=x;
	}
	else if((rear+1)%n==front){
		printf("\nOverflow");
	}
	else{
		rear=(rear+1)%n;
		queue[rear]=x;
	}
}
//............................................................................
int dequeue()
{
	int x=queue[front];
	if(rear==-1 && front==-1){
		printf("\nThe queue is empty");
	}
	else if(rear==front){
		rear=front=-1;
	}
	else{
		front=(front+1)%n;
	}
	return x;
}
//............................................................................
void peek()
{
	if(front==-1 && rear==-1){
		printf("\nThe queue is empty");
	}
	else{
		printf("\n%d is the peek value",queue[front]);
	}
}
//............................................................................
void display()
{
	int i;
	if(front==-1 && rear==-1){
		printf("\nThe queue is empty");
	}
	else{
		i=front;
		while(i!=rear){
			printf("%d ",queue[i]);
			i=(i+1)%n;
		}
		printf("%d ",queue[i]);
	}
}
//............................................................................
int main()
{
	int ch;
	printf("\n\nCircular queue operations");
	while(1){
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\n5.Exit");
		printf("\n\nChoose any option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: enqueue();break;
			case 2: printf("\nDequeu element is %d",dequeue());break;
			case 3: peek();break;
			case 4: display();break;
			case 5: exit(1);break;
			default: printf("\nchoose valid option....");
		}
	}
}


