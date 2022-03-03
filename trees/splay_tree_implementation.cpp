#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right,*parent;
};
struct splaytree{
	struct node *root;
};
//..................................................................................
struct node *LeftRotate(struct splaytree *t,struct node *x)
{
	struct node *y=x->right;
	struct node *t2=y->left;
	y->left=x;                    
	x->right=t2; 
	return y;
}
//..................................................................................
struct node *RightRotate(struct splaytree *t,struct node *y)
{
	struct node *x=y->left;     
	struct node *t2=x->right;  
	x->right=y;                 
	y->left=t2;                  
	return x;
}
//........................................................................................
void splay(struct splaytree *t,struct node *n)
{
	while(n->parent != NULL) { //node is not root
	  if(n->parent == t->root) { //node is child of root, one rotation
	    if(n == n->parent->left){
	      RightRotate(t,n->parent);
	    }
	    else{
	      LeftRotate(t,n->parent);
	    }
	}
	}
}
//........................................................................................
struct node *newnode(int val)
{
	struct node *node;
	node=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&node->data);
	node->data=val;
	node->parent=node->left=node->right=NULL;
	return node;
}
//........................................................................................
void insert(struct splaytree *t,struct node *newnode)
{	
	struct node *temp,*p;
	if(t->root==NULL){
		t->root=newnode;
	}
	else{
		temp=t->root;
		while(temp!=NULL){
			p=temp;
			if(newnode->data < temp->data){
				temp=temp->left;
			}
			else{
				temp=temp->right;
			}
		}
		newnode->parent=p;
		if(newnode->data < p->data){
			p->left=newnode;
		}
		else{
			p->right=newnode;
		}
	}
	splay(t,newnode);
}
//........................................................................................
void search(struct splaytree *t,int val)
{
	
}
//........................................................................................
void preorder(struct node *root)
{
	if(root==NULL){
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
//........................................................................................
void deletedata()
{
	
}
//........................................................................................
int main()
{
	int ch,val,ser,del;
	struct splaytree *t;
	struct node *node;
	while(1){
		printf("\n\n1.Insert");
		printf("\n2.Search");
		printf("\n3.Preorder");
		printf("\n4.Delete");
		printf("\n5.Exit");
		printf("\nChoose any option: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the data: ");
				scanf("%d",&val);
				node=newnode(val);
				insert(t,node);break;
			case 2:
				printf("\nEnter the value to search: ");
				scanf("%d",&ser);
				search(t,val);break;
			case 3: preorder(node);break;
			case 4:
				printf("\nEnter the value to delete: ");
				scanf("%d",&del);
				deletedata();break;
			case 5: exit(1);
			default: printf("\nChoose a valid option");
		}
	}
}
