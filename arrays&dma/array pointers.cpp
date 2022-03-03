#include<stdio.h>
int sum1(int *arr)
{
	int i,sum=0;
	for(i=0;i<5;i++){
		sum=sum+arr[i];
	}
	printf("The sum of array is %d",sum);
}
int main()
{
	int arr[]={1,2,3,4,5};
	sum1(arr);
}

