#include<stdio.h>
//accessing by address
int main()
{
	int* ptr;
	int a[5]={1,2,3,4,5},i;
	ptr=&a[0];
	printf("%d",*ptr);
	
}

