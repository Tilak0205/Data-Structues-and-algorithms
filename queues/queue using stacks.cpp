#include<stdio.h>
#include<stdlib.h>
#define n 5
int s1[n],s2[n];
int top1=-1,top2=-1;
int count=0;
//...............................................................................
void push2(int x)
{
	if(top2==n-1){
		printf("\nOverflow....");
	}
	else{
		top2++;
		s2[top2]=x;
	}
}
//...............................................................................
void push1(int x)
{
	if(top1==n-1){
		printf("\nOverflow....");
	}
	else{
		top1++;
		s1[top1]=x;
	}
}
//...............................................................................
int pop2(void)
{
	return s2[top2--];
}
//.............................................................................
int pop1(void)
{
	return s1[top1--];
}
//.............................................................................
void enqueue(int x)
{
	push1(x);
	count++;
}
//.............................................................................
void dequeue(void)
{
	int i,a,b;
	if(top1==-1 && top2==-2){
		printf("\nThe stack is empty");
	}
	else{
		for(i=0;i<count;i++){
			a=pop1();
			push2(a);
		}
		b=pop2();
		printf("\nThe popped element is: %d",b);
		count--;
		for(i=0;i<count;i++){
			a=pop2();
			push1(a);
		}
	}
}
//.............................................................................
void display(void)
{
	int i;
	if(top1==-1){
		printf("\nThe stack is empty");
	}
	else{
		for(i=0;i<=top1;i++)
		{
			printf("%d ",s1[i]);
		}
	}
}
//.............................................................................
int main()
{
	int ch,x;
	printf("Implementation of queue using stacks\n\n");
	while(1){
		printf("\n\n1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("\n\nChoose any option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the data: ");
				scanf("%d",&x);
				enqueue(x);break;
			case 2: dequeue();break;
			case 3: display();break;
			case 4: exit(1);
			default: printf("Enter valid option..");
		}
	}
}


