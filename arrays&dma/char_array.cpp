#include<stdio.h>
//character array intitialization at compile time
int main()
{
	char s[5]={'h','e','l','l','0'};
	int i;
	for(i=0;i<5;i++){
		printf("%c",s[i]);
	}
	
}

