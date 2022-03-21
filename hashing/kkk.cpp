#include<stdio.h>
int main(){
	int i,j,n,key;
	printf("enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("enter the %d element: ",i);
		scanf("%d",&a[i]);
	}
	int l=0;
	for(i=1;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}

