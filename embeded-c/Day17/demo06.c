#include<stdio.h>

#define offset_of(memb, type)	\
	((unsigned long)&(((type *)0)->memb))


struct student{
	int rollno;
	char name[20];
	float marks;
};


int main(void)
{
	
	printf("offset of rollno = %lu\n", (unsigned long)&(((struct student *)0)->rollno));
	printf("offset of rollno = %lu\n", (unsigned long)&(((struct student *)0)->name));
	printf("offset of rollno = %lu\n", (unsigned long)&(((struct student *)0)->marks));
	
	printf("offset_of(rollno) = %lu\n", offset_of(rollno, struct student));
	printf("offset_of(name) = %lu\n", offset_of(name, struct student));
	printf("offset_of(marks) = %lu\n", offset_of(marks, struct student));

	return 0;
}




















