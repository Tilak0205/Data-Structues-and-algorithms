#include<stdio.h>
#include<stdlib.h>
//.....................................................................................
struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
};
struct node *root=NULL;
//..................................................................................
int max(int a,int b){
	return (a>b)?a:b;
}
//..................................................................................
int getHeight(struct node* node)
{
	if(node==NULL){
		return 0;
	}
	return node->height;
}
//..................................................................................
int getBalanceFactor(struct node* node)
{
	if(node==NULL){
		return 0;
	}
	return getHeight(node->left)-getHeight(node->right);
}
//..................................................................................
struct node* Newnode(int val)
{
	struct node *newnode;
	newnode= (struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->left=newnode->right=NULL;
	newnode->height=1;
	return newnode;
}
//..................................................................................
struct node *LeftRotate(struct node *x)
{
	struct node *y=x->right;                //x---> A
	struct node *t2=y->left;                //       \ 
	//rotating                                y-->    B 
	y->left=x;                              /*       / \           */
	x->right=t2;                        //   t2-->  C   D
	//Updating the heights of x and y
	x->height= max(getHeight(x->right),getHeight(x->left))+1;
	y->height= max(getHeight(y->right),getHeight(y->left))+1;
	return y;
}
//..................................................................................
struct node *RightRotate(struct node *y)
{
	struct node *x=y->left;       //        D    <---- y
	struct node *t2=x->right;     //       /
	//rotating                            B     <---x
	x->right=y;                   /*     / \                */
	y->left=t2;                   //    A   C     <---t2
	//Updating the heights of x and y
	x->height= max(getHeight(x->right),getHeight(x->left))+1;
	y->height= max(getHeight(y->right),getHeight(y->left))+1;
	return x;
}
//..................................................................................
struct node *insertnode(struct node *node,int val)
{
	if(node==NULL){
		return Newnode(val);
	}
	//....................traversing for right position....................
	if(val < node->data){
		node->left=insertnode(node->left,val);
	}
	else if(val > node->data){
		node->right=insertnode(node->right,val);
	}
	else
		return node; //duplicate entries are not allowed in BST
		
	//.................Updating the height of the node after inserting.............
	node->height=max(getHeight(node->right),getHeight(node->left))+1;
	int balance=getBalanceFactor(node);
	//.........................Balancing after inserting..................
	//Left rotation 
	if(balance < -1 && val > node->right->data){
		return LeftRotate(node);
	}
	//Right rotation
	if(balance > 1 && val < node->left->data){
		return RightRotate(node);
	}
	//LR rotation
	if(balance > 1 && val > node->left->data){
		node->left=LeftRotate(node->left);
		return RightRotate(node);
	}
	//RL rotation
	if(balance < -1 && val < node->right->data){
		node->right=RightRotate(node->right);
		return LeftRotate(node);
	}
	return node;
}
//..................................................................................
struct node *MinValueNode(struct node* node){
	if(node==NULL){
		return node;
	}
	while(node->left!=NULL){
		node=node->left;
	}
	return node;
}
//..................................................................................
struct node* deletedata(struct node* node, int val)
{
	struct node *temp;
	if(node==NULL){
		return node;
	}
	//traversing to that element
	else if(val < node->data){
		node->left=deletedata(node->left,val);
	}
	else if(val > node->data){
		node->right=deletedata(node->right,val);
	}
	else{
		//deleting the leaf node i.e having no child
		if(node->right==NULL && node->left==NULL){
			node=NULL;
			free(node);
		}
		//node having one child
		else if(node->left==NULL){
			temp=node;
			node=node->right;
			free(temp);
		}
		else if(node->right==NULL){
			temp=node;
			node=node->left;
			free(temp);
		}
		//node having two children
		else{
			temp=MinValueNode(node->right);
			node->data=temp->data;
			node->right=deletedata(node->right,temp->data);
		}
	}
//..........................................................................
	if(node==NULL){ //if the node is not present
		return node;
	}
	//upation of height and checking balance factor
	node->height= 1 + max(getHeight(node->right),getHeight(node->left));
	int balance = getBalanceFactor(node);
	//rotations according to balance factor
	if(balance>1 && getBalanceFactor(node->left)>=0){//R1 and R0 condition
		return RightRotate(node);
	}
	if(balance>1 && getBalanceFactor(node->left)<0){ //R-1 condition
		node->left=LeftRotate(node->left);
		return RightRotate(node);
	}
	if(balance<-1 && getBalanceFactor(node->right)<=0) //L0 and L-1 condition
	{
		return LeftRotate(node);
	}
	if(balance <-1 && getBalanceFactor(node->right)>0){ //L1 condition
		node->right= RightRotate(node->right);
		return LeftRotate(node);
	}
	return node;
}
//..................................................................................
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
//......................................
int main()
{
	int ch,val,del;
	printf("\n*********AVL TREES**********");
	while(1){
		printf("\n\n1.Insert");
		printf("\n2.Delete data");
		printf("\n3.Inorder");
		printf("\n4.Postorder");
		printf("\n5.Preorder");
		printf("\n6.Exit");
		printf("\n\nChoose any option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the element to insert: ");
				scanf("%d",&val);
				root=insertnode(root,val); break;
			case 2:
				printf("\nEnter the value to delete: ");
				scanf("%d",&del);
				root=deletedata(root,del); break;
			case 3: printf("\nInorder Traversal\n");inorder(root); break;
			case 4: printf("\nPostOrdre Traversal\n");postorder(root);break;
			case 5: printf("\nPreOrder Traversal\n");preorder(root);break;
			case 6: exit(1);
			default: printf("\nChoose valid option: ");
		}
	}
}
