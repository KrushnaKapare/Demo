#include<stdio.h>

struct student{
	int rollno;
	char name[20];
	float marks;
};

typedef struct student stud_t;

int main(void)
{
	stud_t s1 = {12, "abc", 95.0f};

	printf("s1 = %d %s %f\n", s1.rollno, s1.name, s1.marks);

	stud_t *ptr = &s1;

	printf("*ptr = %d %s %f\n", ptr->rollno, ptr->name, ptr->marks);

	printf("sizeof(s1) = %d\n", sizeof(s1));	// 28 bytes
	printf("sizeof(ptr) = %d\n", sizeof(ptr));	// 8 bytes

	return 0;
}




















