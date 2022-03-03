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
void insert(void)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&newnode->data);
	newnode->left=newnode->right=NULL;
	if(root==NULL){
		root=newnode;
	}
	else{
		struct node *curr,*p;
		curr=root;
		while(curr){
			p=curr;
			if(newnode->data>curr->data){
				curr=curr->right;
			}
			else{
				curr=curr->left;
			}
		}
		//curr contains null so we take p before that
		if(newnode->data>p->data){
			p->right=newnode;
		}
		else{
			p->left=newnode;
		}		
	}
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
		if(root->right==NULL && root->left==NULL){
			root=NULL;
			free(root);
		}
		else if(root->right==NULL){
			temp=root;
			root=root->left;
			free(temp);
		}
		else if(root->left==NULL){
			temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->left!=NULL && root->right!=NULL){
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
			case 1: insert();break;
			case 2:
				printf("\nEnter the value to delete: ");
				scanf("%d",&val);
				deletedata(root,val);break;
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
