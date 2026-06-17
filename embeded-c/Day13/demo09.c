#include<stdio.h>

typedef struct student{
	int rollno;
	char name[20];
	float marks;
}stud_t;

void accept_student(stud_t *s);
void print_student(stud_t s);

int main(void)
{
	stud_t s1;

	accept_student(&s1);	// pass by address
							// 8 bytes address will be copied into formal argument

	print_student(s1);		// pass value
							// 28 bytes will be copied into formal argument


	return 0;
}

void accept_student(stud_t *s)
{
	printf("Enter student info (rollno, name, marks) : ");
	scanf("%d %s %f", &s->rollno, s->name, &s->marks);
}
void print_student(stud_t s)
{
	printf("student : %d %s %f\n", s.rollno, s.name, s.marks);
}


















