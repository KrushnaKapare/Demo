
int factorial(int num)
{
	int fact = 1;
	for(int i = 1 ; i <= num ; i++)
		fact *= i;
	return fact;
}

int mypower(int base, int index)
{
	int p = 1;
	for(int i = 1 ; i <= index ; i++)
		p *= base;
	return p;
}
