#include<stdio.h>
#include<stdlib.h>
//priority queue using arrays of structure
struct priorityqueue{
	int data;
	int priority;
}pq[5];
int rear=-1;
int isempty()
{
	if(rear==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(rear==4)
		return 1;
	else
		return 0;
}
void insert(int x,int y)
{
	rear++;
	pq[rear].data=x;
	pq[rear].priority=y;
}

void display()
{
	int i;
	for(i=0;i<=rear;i++){
		printf("\n|%d element|%d priority",pq[i].data,pq[i].priority);
	}
}
int gethighestpriority()
{
	int i,p=-1;
	if(!isempty()){
		for(i=0;i<=rear;i++){
			if(pq[i].priority>p){
				p=pq[i].priority;
			}
		}
	}
	return p;
}
int DeleteHighestPriority()
{
	int i,j,p,ele;
	p=gethighestpriority();
	for(i=0;i<rear;i++)
	{
		if(pq[i].priority==p){
			ele=pq[i].data;
			break;
		}
	}
	if(i<rear){
		for(j=i;j<rear;j++){
			pq[j].data=pq[j+1].data;
			pq[j].priority=pq[j+1].priority;
		}
	}
	rear--;
	return ele;
}

int main()
{
	int ch;
	printf("\nPriority queue using arrays\n");
	while(1){
		printf("\n1.Insert\n");
		printf("2.Get Highest priority\n");
		printf("3.Display\n");
		printf("4.Delete\n");
		printf("5.Exit\n");
		printf("choose any option: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(isfull()){
						printf("\nThe queue is full....");
					}
					else{
						int x,y;
						printf("\nEnter the element to insert: ");
						scanf("%d",&x);
						printf("\nEnter the priority of element: ");
						scanf("%d",&y);
						insert(x,y);					
					}
					break;
			case 2:
				printf("\nThe highest priority is %d",gethighestpriority());
				break;
			case 3: display();printf("\n");break;
			case 4:
				if(isempty()){
					printf("\nThe queue is empty...");
				}
				else{
					int d=DeleteHighestPriority();
					printf("%d is deleted successfully..",d);
				}
				break;
			case 5: exit(1);break;
			default: printf("\nChoose correct option..");
		}
	}
}

