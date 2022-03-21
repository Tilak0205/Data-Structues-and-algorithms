#include<stdio.h>
#include<stdlib.h>
//Binary search Trees in c
//...................................................................................................
struct node{
	int data;
	struct node *left,*right;
};
struct node *root=NULL;
//....................................................................................................
struct node *createNode(int val){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->right=newnode->left=0;
	return newnode;
}

struct node *insert(struct node *root,int val)
{	
	if(root==0){
		return createNode(val);
	}
	if(val < root->data){
		root->left=insert(root->left,val);
	}
	else{
		root->right=insert(root->right,val);
	}
	return root;
}
//....................................................................................................
struct node* find_min(struct node *root)
{
	if(root==NULL){
		printf("\nThe tree is empty");
	}
	else{
		while(root->left!=NULL){
			root=root->left;
		}
		return root;
	}
}
//....................................................................................................
struct node* search(struct node* root, int val)
{
	struct node *temp;
	if(val==root->data){
		return root;
	}
	else{
		if(val>root->data){
			search(root->right,val);
		}
		else
			search(root->left,val);
	}
}
//....................................................................................................
struct node *deletedata(struct node* root,int val)
{
	struct node *temp;
	if(root==NULL){
		return root;
	}
	else if(val > root->data){
		root->right=deletedata(root->right,val);
	}
	else if(val < root->data){
		root->left = deletedata(root->left,val);
	}
	else{
		if(root->right==NULL && root->left==NULL){ //leaf node
			root=NULL;
			free(root);
		}
		else if(root->right==NULL){ //node contains left child
			temp=root->left;
			free(root);
			return temp;
		}
		else if(root->left==NULL){ //node contains right child
			temp=root->right;
			free(root);
			return temp;
		}
		else if(root->left!=NULL && root->right!=NULL){ //node is at middle
			temp=find_min(root->right);
			root->data=temp->data;
			root->right=deletedata(root->right,temp->data);
		}
		return root;
	}
}
//....................................................................................................
void inorder(struct node* root)
{
	if(root==NULL){
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
//....................................................................................................
void preorder(struct node* root)
{
	if(root==NULL){
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
//....................................................................................................
void postorder(struct node* root)
{
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
//....................................................................................................
int main()
{
	int ch,val;
	struct node *min;
	printf("Operations on Binary Search Trees\n");
	while(1){
		printf("\n\n1.Insertion");
		printf("\n2.Delete");
		printf("\n3.Inorder");
		printf("\n4.Preorder");
		printf("\n5.Postorder");
		printf("\n6.Minimum element");
		printf("\n7.Exit");
		printf("\n\nChoose any option: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: int val;
				printf("\nEnter the value to insert: ");scanf("%d",&val);
				root=insert(root,val);break;
			case 2:
				printf("\nEnter the value to delete: ");
				scanf("%d",&val);
				root=deletedata(root,val);break;
			case 3: inorder(root);break;
			case 4: preorder(root);break;
			case 5: postorder(root);break;
			case 6: min=find_min(root);
					printf("\n%d is the minimum value",min->data);break;
			case 7: exit(1);
			default: printf("\nEnter valid option..");
		}
	}
}
