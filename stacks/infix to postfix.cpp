#include<stdio.h>
#include<string.h>
#define size 10
int top=-1;
int stack[size];
push(char x){
	if(top<=size-1){
		top++;
		stack[top]=x;
	}
	else{
		printf("\nStack overflow");
	}
}
char pop(){
	if(top==-1){
		printf("\nStack underflow");
	}
	else{
		return stack[top--];
	}
}
int isoperand(char x){
	if(x=='*' || x=='+' || x=='-' || x=='/'){
		return 0;
	}
	else{
		return 1;
	}
}
int pre(char x){
	if(x=='#'){
		return 1;
	}
	else if(x=='+' || x=='-'){
		return 2;
	}
	else if(x=='*' || x=='/'){
		return 3;
	}
}
int isdigit(char x){
	if(x>=48 && x<=57){
		return 1;
	}
	else{
		return 0;
	}
}
//evaluates postfix expression
evaluate(char postfix[]){
	char ch;
	int i = 0,x1,x2;
	while( (ch = postfix[i++]) != '\0') {
		if(isdigit(ch))
		{
			push(ch-'0'); // Push the operand
		}else {
			//Operator,pop two operands
			x2 = pop();
			x1 = pop();
			switch(ch) {
				case '+':
					push(x1+x2);
					break;
				case '-':
					push(x1-x2);
					break;
				case '*':
					push(x1*x2);
					break;
				case '/':
					push(x1/x2);
					break;
			}
		}
	}
	printf("\n%d ",stack[top]);
}

convert(char infix[])
{
	char postfix[30];
	int i=0,j=0;
	while(infix[i]!='\0'){
		if(isoperand(infix[i])){
			postfix[j++]=infix[i++];
		}
		else{
			if(pre(infix[i])>pre(stack[top])){
				push(infix[i++]);
			}
			else{
				while(pre(infix[i])<=pre(stack[top])){
						postfix[j++]=pop();
					}
					push(infix[i++]);
				}
			}
	}
	while(stack[top]!='#'){
		postfix[j++]=pop();
	}
	postfix[j++]='\0';
	printf("Postfix expression %s\n",postfix);
	evaluate(postfix);
}
int main()
{
	char input[30];
	printf("Enter the infix expression: ");
	scanf("%s",input);
	push('#');
	convert(input);
}
