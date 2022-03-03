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
int find_min(struct node *root)
{
	if(root==NULL){
		printf("\nThe tree is empty");
	}
	else{
		while(root->left!=NULL){
			root=root->left;
		}
		return root->data;
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
void deletedata(void)
{
	int val;
	struct node *curr,*p,*temp,*t1,*p1;
	printf("\nEnter the data to delete: ");
	scanf("%d",&val);
	if(root==NULL){
		printf("\nThe tree is empty..");
	}
	else if(val==root->data && root->right==NULL && root->left==NULL)//root element
	{
		root =NULL;
	}
	else{
		p=curr=root;
		while(val!=curr->data)
		{
			p=curr;
			if(val > curr->data)
			{
				curr=curr->right;
			}
			else
			{
				curr=curr->left;
			}
		}
		printf("parent %d",p->data);
		printf("current %d",curr->data);
		if(curr->left==NULL && curr->right==NULL) //deleting leaf node
		{
			if(curr==p->right){
				p->right=NULL;
			}
			else{
				p->left=NULL;
			}
			free(curr);
		}
		else if(curr->left==NULL) //deleting node having one child
		{
			temp=curr->right;
			if(p->right==curr){
				p->right=temp;
			}
			else{
				p->left=temp;
			}
			free(curr);
		}
		else if(curr->right==NULL) //deleting node having one child
		{
			temp=curr->left;
			if(p->right==curr){
				p->right=temp;
			}
			else{
				p->left=temp;
			}
			free(curr);
		}
		else if(curr->right!=NULL && curr->left!=NULL) //the node having 2 children
		{
			p1=t1=curr->right;
			while(t1->left!=NULL){
				p1=t1;
				t1=t1->left;
			}
			curr->data=t1->data;
			p1->left=NULL;
			free(t1);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int ch,min,val;
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
				deletedata();break;
			case 3: inorder(root);break;
			case 4: preorder(root);break;
			case 5: postorder(root);break;
			case 6: min=find_min(root);
					printf("\n%d is the minimum value",min);break;
			case 7: exit(1);
			default: printf("\nEnter valid option..");
		}
	}
}
