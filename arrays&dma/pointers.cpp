#include<stdio.h>

int main()
{
	int a=8;
	int *ptr,*ptr2;
	int **ptr3;
	ptr =&a;
	ptr3 = &ptr;
	ptr2=NULL;
	printf("the value of a is %d",a);
	printf("\nThe address of a is %d",ptr);
	printf("\nThe value of a is %d",*ptr);
	printf("\nThe address of pointer is %d",&ptr);
	printf("\nThe null pointer is %d",ptr2);
	printf("\nThe value of ptr3 is %d",**ptr3);
	printf("\nThe address of ptr2 is %d",ptr3);
	
}

