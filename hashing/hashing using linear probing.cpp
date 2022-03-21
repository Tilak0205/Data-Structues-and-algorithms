#include<stdio.h>
#include<stdlib.h>
#define size 8
int hash[size]={0};
int count=0;
insert()
{
	int x;
	printf("Enter the number to insert: ");
	scanf("%d",&x);
	if(count==size){
		printf("\nThe hash table is full ");
	}
	else{
		int key=(x%size);
		if(hash[key]==0){
			hash[key]=x;
		}
		else{
			key=(key+1)%size;
			while(hash[key]!=0){
				key=(key+1)%size;
			}
			hash[key]=x;
		}
		count++;
	}
}

search()
{
	int x;
	printf("Enter the element to search: ");
	scanf("%d",&x);
	if(count==0){
		printf("\nThere are no elements to search..");
	}
	else{
		int key=x%size;
		if(hash[key]==x){
			printf("\nThe element is found at index hash[%d]",key);
		}
		else{
			int i;
			for(i=0;i<size;i++){
				if(hash[i]==x){
					printf("\nThe element is found at index hash[%d]",i);
					break;
				}
			}
			printf("\nThe element is not found");
		}
	}
}

display()
{
	if(count==0){
		printf("\nThe hash table is empty..");
	}
	else{
		for(int i=0;i<size;i++){
			printf("\nhash[%d]=%d",i,hash[i]);
		}
	}
}

int main()
{
	int ch;
	while(1){
		printf("\n\n1.Insert\n2.Search\n3.Display\n4.Exit");
		printf("\nChoose any option: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();break;
			case 2: search();break;
			case 3: display();break;
			case 4: exit(1);
			default: printf("\nChoose correct option..");
		}
	}
}


