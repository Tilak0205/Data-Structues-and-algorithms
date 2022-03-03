#include<stdio.h>
#include<stdlib.h>

struct emp
{
	int eno;
	char ename[21];
	float esal;
};
int main()
{
	struct emp* ptr;
	ptr= (struct emp*)malloc(sizeof(struct emp));
	if(ptr==NULL)
	{
		printf("out of memory error");
	}
	else{
		printf("Enter the details of the employee:\n");
		scanf("%d %s %f",&ptr->eno,ptr->ename,&ptr->esal);   //coz its pointer to struct variable
	}
	printf("\nEmployee Name: %s\nEmployee no.: %d\nEmployee Salary: %.2f",ptr->ename,ptr->eno,ptr->esal);
}

