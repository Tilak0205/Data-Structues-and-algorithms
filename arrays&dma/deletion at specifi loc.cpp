#include<stdio.h>
int main()
{
	int i,pos,a[10],size;
	printf("enter the array size: \n");
	scanf("%d",&size);
	printf("\nEnter the %d elements of array\n",size);
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	printf("\nThe element of the array are: \n");
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	printf("\nEnter the position of element to delete: ");
	scanf("%d",&pos);
	if(pos<=0 || pos>size){
		printf("\nInvalid Position");
	}
	else{
		for(i=pos-1;i<size-1;i++){
		a[i]=a[i+1];
		}
		size--;
		printf("\nThe elements of array after deletion are:\n");
		for(i=0;i<size;i++){
			printf("%d ",a[i]);
		}
	}
}     
