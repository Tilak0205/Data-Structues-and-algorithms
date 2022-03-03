#include<stdio.h>
//insertion of element in an array at specific position
int main()
{
	int a[50],size,i,num,pos;
	printf("enter the size of the array: ");
	scanf("%d",&size);
	printf("\nEnter the elements of the array:\n");
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	printf("\nThe array elements are:\n");
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	printf("\nEnter the number you want to insert: ");
	scanf("%d",&num);
	printf("\nEnter the positon at which you want to insert: ");
	scanf("%d",&pos);
	if(pos<=0 || pos>size){
		printf("\nivalid position");
	}
	else{
		for(i=size-1;i>=pos-1;i--){
		a[i+1]=a[i];
		}
		a[pos-1]=num;
		size++;
		printf("\nThe elements of the array are: \n");
		for(i=0;i<size;i++){
			printf("%d ",a[i]);
		}
	}
}

