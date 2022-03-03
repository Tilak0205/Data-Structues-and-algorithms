#include<stdio.h>
#include<stdlib.h>
#define n 5
//stacks using arrays
///////////////////////////////////////////////////////////////////////////////
//global variables here......
int top=-1;
int stack[n];
///////////////////////////////////////////////////////////////////////////////
void push(void)
{
	int x;
	printf("\nEnter the value: ");
	scanf("%d",&x);
	if(top<n-1){
		top++;
		stack[top]=x;
	}
	else{
		printf("\nStack is full\n");
	}
}
/////////////////////////////////////////////////////////////////////////////////
void pop(void)
{
	int i;
	if(top==-1){
		printf("\nStack is empty\n");
	}
	else{
		i=stack[top];
		top--;
		printf("\nSuccessfully popped out the top element %d",i);
	}
}
///////////////////////////////////////////////////////////////////////////////
void peek(void)
{
	int i;
	if(top==-1){
		printf("\nThe stack is empty\n");
	}
	else{
		printf("\nthe peek value is:  %d",stack[top]);
	}
}
///////////////////////////////////////////////////////////////////////////////
void display(void)
{
	int i;
	if(top==-1){
		printf("\nThe stack is empty\n");
	}
	else{
		printf("\n\nThe elements of stack are\n");
		for(i=top;i>=0;i--){
			printf("%d ",stack[i]);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
int main()
{
	int ch;
	printf("Stacks using Arrays Operations\n");
	while(1){
		printf("\n\n1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Choose any option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: push();break;
			case 2: pop();break;
			case 3: peek();break;
			case 4: display();break;
			case 5: exit(0);
			default: printf("\nInvalid entry...\n");
		}
	}
}


