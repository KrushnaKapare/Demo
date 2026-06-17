#include <stdio.h>
int main ()
{
	int n1, n2 , res;
	char ch;
	printf("\n Enter two nos and one alphabetical character");
	scanf("%d%d%*%c",&n1,&n2,&ch);


	printf("\nsize of num1= %d ",sizeof(n1));
	printf("\nsize of num2=%d",sizeof(n2));
	printf("\nsize of char+%d",sizeof(ch));

	printf("\nhexadecimal = %x",n1);
	printf("\noctal =%o",n2);

	printf("
	return 0;

	
