#include<stdio.h>

#define offset_of(memb, type)	\
	((unsigned long)&(((type *)0)->memb))


struct employee{
	int empid;
	char name[20];
	char address[20];
	double salary;
};


int main(void)
{
	printf("offset_of(empid) = %lu\n", offset_of(empid, struct employee));
	printf("offset_of(name) = %lu\n", offset_of(name, struct employee));
	printf("offset_of(address) = %lu\n", offset_of(address, struct employee));
	printf("offset_of(salary) = %lu\n", offset_of(salary, struct employee));

	return 0;
}




















