#include<stdio.h>
#include<stdlib.h>
#define n 8
#define k 10
////////////////////////////////////////////////////////////////////////////////
int queue[k];
int graph[n][n]={0};
//.............................................................................
struct node{
	int data;
	struct node *next;
};
struct node *front=0,*rear=0;
//.............................................................................
void enqueue(int i)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=i;
	temp->next=0;
	if(front==0 && rear==0){
		front=rear=temp;
	}
	else{
		rear->next=temp;
		rear=temp;
	}
}
//.............................................................................
int dequeue(int queue[])
{
	
}
//.............................................................................
int isempty(int queue[])
{
	
}
int main()
{
	int i;
	enqueue(1);
	enqueue(1);
	enqueue(1);
	enqueue(1);
	for(i=0;i<n;i++)
	{
		printf("%d ",queue[i]);
	}
}//void enqueue(int queue[],int i)
//{
//	if(rear==-1 && front==-1)
//	{
//		front=rear=0;
//		queue[rear]=i;
//	}
//	else if(front>rear)
//	{
//		front=rear=0;
//		queue[rear]=i;
//	}
//	else{
//		rear++;
//		queue[rear]=i;
//	}
//		
//}
//int isempty(int queue[])
//{
//	if(rear==-1 && front==-1)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//int dequeue(int queue[])
//{
//	if(front==rear)
//	{
//		return queue[front];
//		front=rear=-1;	
//	}
//	else{
//		return queue[front++];
//	}
//}
////...........................................................................................................
////.............................................................................
//struct node{
//	int data;
//	struct node *next;
//};
//struct node *front=NULL;
//struct node *rear=NULL;
////.............................................................................
//void enqueue(int queue[],int i)
//{
//	struct node *temp;
//	temp=(struct node *)malloc(sizeof(struct node));
//	temp->data=i;temp->next=0;
//	if(front==0 || rear==0){
//		front=temp;
//		rear=temp;
//	}
//	else{
//		rear->next=temp;
//		rear=temp;
//	}
//}
////.............................................................................
//int dequeue(int queue[])
//{
//	struct node *temp;
//	temp=front;
//	front=front->next;
//	return temp->data;
//}
////.............................................................................
//int isempty(int queue[])
//{
//	if(front==0 && rear==0)
//	{
//		return 0;
//	}
//	else{
//		return 1;
//	}
//}
