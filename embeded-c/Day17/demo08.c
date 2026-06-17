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
	struct student st = {120, "abc", 85.0f};
/*
	st.rollno =>	*(int *)((char *)&st + offset_of(rollno, struct student))
	st.name		=>	(char *)&st + offset_of(name, struct student)
	st.marks	=>	*(float *)((char *)&st + offset_of(marks, struct student))

	struct student *ptr = &st;

	(*ptr).rollno
	(*ptr).name
	(*ptr).marks
*/
	printf("rollno = %d\n", *(int *)((char *)&st + offset_of(rollno, struct student)));
	printf("name = %s\n", (char *)&st + offset_of(name, struct student));
	printf("marks = %f\n", *(float *)((char *)&st + offset_of(marks, struct student)));


	return 0;
}




















