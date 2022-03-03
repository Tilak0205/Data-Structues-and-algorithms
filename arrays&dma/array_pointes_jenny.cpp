#include<stdio.h>
//array concepts and dereference operator i.e., pointer*
int main()
{
	int a[]={7,2,8,9,1},q[5],i;
	int *ptr,*ptr2;
	ptr=&a[0];
	for(i=0;i<5;i++){
		printf("%d ",a[i]);
	}
	printf("\n The address of a is %p",&a);
	printf("\nThe address of a is %p",a);       //a=&a
	printf("\nThe pointer contains %p",ptr);     //ptr!=&ptr
	printf("\nThe address of element 2 is %p",&a[1]);
	printf("\nThe address of element 2 using pointer is %p",ptr+1); // we cannot use a++
	printf("\nThe addresss of third element is %p",a+2);
	printf("\nThe first element is %d",*ptr);      //*ptr = *a = a[0]
	printf("\nThe address of element 2 using pointer is %p",a+1);
	printf("\nThe second element of the array is %d",*(ptr+1)); // *(a+1)=*(ptr+1)=a[2]
	printf("\nThe third element of the array is %d",2[a]);   //2[a]=a[2]=*(a+2)
	printf("\n%d",*a+1);//that is 7+1
	printf("\n%d",*(a+1)); //this is the second elemnt of the array
	printf("\n\n");
	for (i=0;i<15;i++){
		printf(" *",i);
	}
	printf("\n\n");
	ptr2=q;
	for(i=0;i<5;i++){
		scanf("%d",&ptr2[i]); //&a[i]=q+i=ptr2+i=&ptr2[i]
	}
	for(i=0;i<5;i++){
		printf("%d ",i[q]); //q[i]=*(q+i)=*(ptr2+i)=i[q]
	}
}

