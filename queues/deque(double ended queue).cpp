#include<stdio.h>
#include<stdlib.h>
#define n 5
//........................................................................................
int deque[n];
int front=-1,rear=-1;
//........................................................................................
void enqueue_front(int x)
{
	if((rear+1)%n==front){    //full condition
		printf("\nThe queue is full");
	}
	else if(front==-1 && rear==-1) //empty condition
	{
		front=rear=0;
		deque[front]=x;		
	}
	else if(front==0){
		front=n-1;
		deque[front]=x;
	}
	else{
		front--;
		deque[front]=x;
	}
}
//........................................................................................
void enqueue_rear(int x)
{
	if((rear+1)%n==front){
		printf("\nThe queue is full");
	}
	else if(front==-1 && rear==-1){
		front=rear=0;
		deque[rear]=x;
	}
	else if(rear==n-1){
		deque[(rear+1)%n]=x; //uses when the front element is empty
	}
	else{
		rear++;
		deque[rear]=x;
	}
}
//........................................................................................
void dequeue_front(void)
{
	if(front==-1 && rear==-1){ //if there is no element in queue
		printf("\nthe queue is empty");
	}
	else if(front==rear){ //if there is only one element in queue
		front=rear=-1;
	}
	else if(front==n-1){
		front=(front+1)%n;
	}
	else{
		front++; //general 
	}
}
//........................................................................................
void dequeue_rear(void)
{
	if(front==-1 && rear==-1){ //if there is no element in queue
		printf("\nthe queue is empty");
	}
	else if(front==rear){ //if there is only one element in queue
		front=rear=-1;
	}
	else if(rear==0){
		rear=n-1;
	}
	else{
		rear--;
	}
}
//........................................................................................
void getfront(void)
{
	printf("\nThe front element is %d",deque[front]);
}
//........................................................................................
void getrear(void)
{
	printf("\nThe rear element is %d",deque[rear]);
}
//........................................................................................
void display(void)
{
	int i;
	if(front==-1 && rear==-1){
		printf("\nThe queue is empty");
	}
	else{
		i=front;
		while(i!=rear){
			printf("%d ",deque[i]);
			i=(i+1)%n;
		}
		printf("%d",deque[i]);
	}
}
//........................................................................................
int main()
{
	int ch,x;
	printf("\nDouble ended queue operations");
	while(1){
		printf("\n\n1.EnqueueFront");
		printf("\n2.EnqueueRear");
		printf("\n3.DequeueFront");
		printf("\n4.DequeueRear");
		printf("\n5.GetFront");
		printf("\n6.GetRear");
		printf("\n7.Display");
		printf("\n8.Exit");
		printf("\n\nchoose any option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the data: ");
				scanf("%d",&x);
				enqueue_front(x); break;
			case 2:
				printf("\nEnter the data: ");
				scanf("%d",&x);
				enqueue_rear(x);break;
			case 3: dequeue_front();break;
			case 4: dequeue_rear();break;
			case 5: getfront();break;
			case 6: getrear();break;
			case 7: display();break;
			case 8: exit(1);
			default: printf("\nChoose valid option..");
		}
	}
}


