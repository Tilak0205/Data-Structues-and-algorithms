#include<stdio.h>
#include<stdlib.h>
//////////////////////////////////////////////////
//stack using linkedlist
/////////////////////////////////////////////////
struct node{
	int data;
	struct node *link;
};
struct node *top=0;
//////////////////////////////////////////////////////////////////////
void push (void)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&newnode->data);
	newnode->link=top;
	top=newnode;
}
//////////////////////////////////////////////////////////////////////
void pop(void)
{
	struct node *temp;
	temp=top;
	if(top==0){
		printf("\nUnderflow");
	}
	else{
		printf("Successfully popped %d",temp->data);
		top=top->link;
		free(temp);
	}
}
//////////////////////////////////////////////////////////////////////
void peek(void)
{
	if(top==0){
		printf("\nthe stack is empty");
	}
	else{
		printf("\nThe top element in stack is %d",top->data);
	}
}
//////////////////////////////////////////////////////////////////////
void display(void)
{
	struct node *temp;
	temp=top;
	if(top==0){
		printf("\nThe stack is empty");
	}
	else{
		printf("\nThe elements in the stack are\n");
		while(temp!=0){
			printf("%d ",temp->data);
			temp=temp->link;
		}
	}
}
//////////////////////////////////////////////////////////////////////
int main()
{
	int ch;
	printf("Stack using linked list operations\n\n");
	while(1){
		printf("\n\n1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("\nChoose any option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: push();break;
			case 2: pop();break;
			case 3: peek();break;
			case 4: display();break;
			case 5: exit(0);
			default: printf("\nInvalid entry..");
		}
	}
}


