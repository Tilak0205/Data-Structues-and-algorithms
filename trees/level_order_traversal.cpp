#include<stdio.h>
#include<stdlib.h>
#define size 20
int f=-1,r=-1;
//binary tree implementation and level order traversal
//......................................................................................
struct node
{
	int data;
	struct node *left,*right;
};
struct node *root=0;
struct node *queue[size];
void enqueue(struct node *node)
{
	if(f==-1 && r==-1){
		f++;
		queue[++r]=node;
	}
	else{
		queue[++r]=node;
	}
}
struct node *dequeue()
{
	struct node *t=queue[f];
	if(r==f){
		f=r=-1;
	}
	else{
		f=f+1;
	}
	return t;
}
int isEmpty()
{
	if(f==-1 && r==-1)
	{
		return 1;
	}
	else{
		return 0;
	}
}
//......................................................................................
void preorder(struct node *root)
{
	if(root==0){
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
//......................................................................................
void levelorder(struct node *root)
{
	if(root==0)
		return;
	struct node *temp;
	enqueue(root);
	while(!isEmpty())
	{
		temp=dequeue();
		printf("%d ",temp->data);
		if(temp->left)
			enqueue(temp->left);
		if(temp->right)
			enqueue(temp->right);
	}
}
////......................................................................................
struct node *create()
{
	int x;
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&x);
	if(x==-1){
		return 0;
	}
	newnode->data=x;
	printf("\nEnter the left child of %d: ",x);
	newnode->left=create();
	printf("\nEnter the right child of %d: ",x);
	newnode->right=create();
	return newnode;
}
int main()
{
	int ch;
	printf("\nBinary Tree implementation");
	root=create();
	printf("\n\nThe levelorder is: \n");
	levelorder(root);
}
