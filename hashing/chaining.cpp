#include<stdio.h>
#include<stdlib.h>
#define hs 10
//.......................................................................................
struct node{
	int data;
	struct node *next;
};
struct node *hash[hs]={0};
//.......................................................................................
insert()
{
	struct node *temp,*newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	int key=(newnode->data)%hs;
	if(hash[key]==0){
		hash[key]=newnode;
	}
	else{
		temp=hash[key];
		if(newnode->data <= temp->data){
			newnode->next=temp;
			hash[key]=newnode;
		}
		else{
			while(temp->next!=0 && newnode->data > temp->next->data){
				temp=temp->next;
			}
			newnode->next=temp->next;
			temp->next=newnode;			
		}
	}
}
//.......................................................................................
int search(int s)
{
	struct node *temp;
	int key=s%10;
	temp=hash[key];
	if(temp==0){
		return 0;
	}
	else{
		while(temp!=0){
			if(temp->data > s){
				return 0;
			}
			else if(temp->data==s){
				return 1;
			}
			temp=temp->next;
		}
	}
}
//.......................................................................................
display()
{
	int i;
	for(i=0;i<hs;i++){
		printf("hash[%d]",i);
		struct node *temp=hash[i];
		while(temp!=0){
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
//.......................................................................................
deletedata()
{
	struct node *p,*q;
	int d;
	printf("\nEnter the element to delete: ");
	scanf("%d",&d);
	int key=d%10;
	p=hash[key];
	if(search(d))
	{
		if(p->data==d){
			hash[key]=hash[key]->next;
			free(p);
		}
		else{
			q=hash[key]->next;
			while(q->next!=0 && q->data!=d){
				p=q;
				q=q->next;
			}
			p->next=q->next;
			q->next=0;
			free(q);
		}
		printf("\n%d deleted successfully....",d);
	}
	else{
		printf("\nThe element not found buddy..");
	}
}
//.......................................................................................
int main()
{
	int ch;
	while(1)
	{
		printf("\n\n1.Insert\n2.Search\n3.Display\n4.Delete\n5.Exit");
		printf("\nchoose any option: ");scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();break;
			case 2:	int s;
					printf("\nEnter the element to search: ");
					scanf("%d",&s);
					if(search(s))
						printf("%d found",s);
					else
						printf("%d not found",s);
						break;
			case 3: display();break;
			case 4: deletedata();break;
			case 5: exit(1);
			default: printf("\nChoose correct option");
		}
	}
}
