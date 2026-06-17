#include<stdio.h>

struct student{
	int rollno;
	char name[20];
	float marks;
};


int main(void)
{
	struct student *p = (struct student *)0;

	printf("Offsets with structure pointer variable : \n");
	printf("offset of rollno = %d\n", (char *)&p->rollno - (char *)p);
	printf("offset of name = %d\n", (char *)&p->name - (char *)p);
	printf("offset of marks = %d\n", (char *)&p->marks - (char *)p);

	printf("address of rollno = %u\n", &p->rollno);
	printf("address of name = %u\n", &p->name);
	printf("address of marks = %u\n", &p->marks);

	return 0;
}




















