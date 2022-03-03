#include<stdio.h>
#include<stdlib.h>
//binary tree implementation and traversal
//......................................................................................
struct node
{
	int data;
	struct node *left,*right;
};
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
void postorder(struct node *root)
{
	if(root==0){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
//......................................................................................
void inorder(struct node *root)
{
	if(root==0){
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
//......................................................................................
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
	struct node *root;
	root=create();
	printf("\n\nThe preorder is: \n");
	preorder(root);
	printf("\n\nThe postorder is: \n");
	postorder(root);
	printf("\n\nThe inorder is: \n");
	inorder(root);
}
