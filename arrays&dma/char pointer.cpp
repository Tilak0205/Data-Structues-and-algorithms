#include<stdio.h>

int main()
{
	char *ptr = "geeksforgeeks";
	printf("%s\n", *&*&ptr);
	printf("%c\n", *&*&*ptr);
	return 0;
}

