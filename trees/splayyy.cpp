#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
}node;
//.......................................................................................................
struct splay_tree {
    struct node *root;
 }splay_tree;
 //.......................................................................................................
 
//struct node* node;
//struct splay_tree* splay_tree;
 
 //.......................................................................................................
struct node* new_node(int data) {
    struct node *n = (struct node*)malloc(sizeof(node));
    n->data = data;
    n->parent = NULL;
    n->right = NULL;
    n->left = NULL;
    return n;
 }
 //.......................................................................................................
 struct splay_tree* new_splay_tree()
 {
    struct splay_tree *t =(struct splay_tree*)malloc(sizeof(struct splay_tree));
     t -> root = NULL;
     return t;
 }
 //.......................................................................................................
 struct node* maximum(struct splay_tree *t,struct node *x)
 {
     while(x -> right != NULL)
       x = x -> right;
     return x;
 }
 //.......................................................................................................
 void left_rotate(struct splay_tree *t,struct node *x)
 {
    struct node *y = x->right;
    x->right = y->left;
    if(y->left != NULL)
    {
    	y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NULL){ // x is root
    	t->root = y;
    }
    else if(x == x->parent->left){ // x is left child
    	x->parent->left = y;
    }
    else{ //x is right child
    	x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
 }
 //.......................................................................................................
 void right_rotate(struct splay_tree *t,struct node *x)
 {
    struct node *y = x->left;
    x->left = y->right;
    if(y->right != NULL){
       y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NULL){ // x is root
       t->root = y;
    }
    else if(x == x->parent->right)
    { // x is left child
		x->parent->right = y;
    }
    else{ // x is right child
       	x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
 }
 //.......................................................................................................
 void splay(struct splay_tree *t,struct node *n) {
     while(n -> parent != NULL) { // node is not root
       if(n -> parent == t -> root) { // node is child of root, one rotation
         if(n == n -> parent -> left) {
           right_rotate(t, n -> parent);
         }
         else {
           left_rotate(t, n -> parent);
         }
       }
       else {
        struct node *p = n -> parent;
        struct node *g = p -> parent; // grandparent
         if(n -> parent -> left == n && p -> parent -> left == p) { // both are left children
           right_rotate(t, g);
           right_rotate(t, p);
         }
         else if(n -> parent -> right == n && p -> parent -> right == p) { // both are right children
           left_rotate(t, g);
           left_rotate(t, p);
         }
         else if(n -> parent -> right == n && p -> parent -> left == p) {
           left_rotate(t, p);
           right_rotate(t, g);
         }
         else if(n -> parent -> left == n && p -> parent -> right == p) {
           right_rotate(t, p);
           left_rotate(t, g);
         }
       }
     }
 }
 //.......................................................................................................
 void insert(struct splay_tree *t,struct node *n)
 {
    struct node *y = NULL;
    struct node *temp = t->root;
    if(t->root==NULL){
    	t->root=n;
	}
	else{
		y=t->root;
		while(temp!=NULL){
			y=temp;
			if(n->data < temp->data){
				temp=temp->left;
			}
			else{
				temp=temp->right;
			}
		}
		n->parent = y;
		if(n->data < y->data){
			y->left=n;
		}
		else{
			y->right=n;
		}
	}
    splay(t, n);
}
//.......................................................................................................     
struct node* search(struct splay_tree *t,struct node *n, int x)
{
    if(x == n->data)
    {
       splay(t, n);
       return n;
    }
    else if(x < n->data)
       return search(t, n->left,x);
    else if(x > n->data)
       return search(t, n->right,x);
    else
       return NULL;
 }
 //.......................................................................................................
void deletedata(struct node *node,int val)
 {
 	
 }
 //.......................................................................................................
 void preorder(struct splay_tree *t,struct node *n)
 {
    if(n==NULL){
		return;
	}
	printf("%d ",n->data);
	preorder(t,n->left);
	preorder(t,n->right);
 }
 //.......................................................................................................
 int main()
 {
    int ch,val;
    struct splay_tree *t = new_splay_tree();
    struct node* node;
 	while(1){
	    printf("\n1.Insert");
	    printf("\n2.Delete");
	    printf("\n3.Preorder");
	    printf("\n4.Search");
	    printf("\n5.Exit");
	    printf("\n\nchoose any option: ");
	    scanf("%d",&ch);
	    switch(ch){
	        case 1:
	            printf("\nEnter the data: ");
	            scanf("%d",&val);
	            node=new_node(val);
	            insert(t,node);break;
	        case 2:
	            printf("\nEnter the value to Delete: ");
	            scanf("%d",&val);
	            deletedata(node,val);break;
	        case 3:
	            preorder(t, t -> root);
	            break;
	        case 4:
	        	int x;
	        	printf("\nEnter the value to search: ");
	        	scanf("%d",&x);
	            node=search(t,node,x);break;
	        case 5: exit(1);
	        default: printf("Enter the valid option");
	    }
 	}
 } 
 //.......................................................................................................
