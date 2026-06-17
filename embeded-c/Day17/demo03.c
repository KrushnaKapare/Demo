#include<stdio.h>

struct student{
	int rollno;
	char name[20];
	float marks;
};


int main(void)
{
	struct student s = {120, "abc", 85.0f};

	printf("&s = %u\n", &s);
	printf("&rollno = %u\n", &s.rollno);
	printf("&name = %u\n", &s.name);
	printf("&marks = %u\n", &s.marks);


	printf("Offsets with structure variable : \n");
	printf("offset of rollno = %d\n", (char *)&s.rollno - (char *)&s);
	printf("offset of name = %d\n", (char *)&s.name - (char *)&s);
	printf("offset of marks = %d\n", (char *)&s.marks - (char *)&s);

	struct student *p = &s;

	printf("Offsets with structure pointer variable : \n");
	printf("offset of rollno = %d\n", (char *)&p->rollno - (char *)p);
	printf("offset of name = %d\n", (char *)&p->name - (char *)p);
	printf("offset of marks = %d\n", (char *)&p->marks - (char *)p);

	return 0;
}




















