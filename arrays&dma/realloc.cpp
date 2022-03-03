#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, *arr,i;
	printf("enter the size of the array: ");
	scanf("%d",&n);
	arr= (int*)calloc(n,sizeof(int));
	if(arr==NULL){
		printf("out of memory\n");
	}
	else{
		printf("\nEnter the elements of the array: \n");
		for(i=0;i<n;i++){
			scanf("%d",&*(arr+i));
		}
		printf("The element before size increasing are: \n");
		for(i=0;i<n;i++)
		{
			printf("%d ",*(arr+i));
		}
		n=n+5;
		arr=(int*)realloc(arr,n*sizeof(int));
		printf("\nMemory successfully allocated by realloc\n");
		printf("\nEnter the remaining %d elements: \n",n-5);
		for(i=5;i<n;i++){
			scanf("%d",&*(arr+i));
		}
		printf("elements after the new size is declared: \n");
		for(i=0;i<n;i++){
			printf("%d ",*(arr+i));
		}
		free(arr);
	}
	return 0;
}

