#include<stdio.h>

// type declaration
struct student{
	int rollno;
	char name[20];
	float marks;
};

int main(void)
{
	struct student s1 = {12, "abc", 95.0f};
						// structure initializer list

	//	to access members of structure variable use '.' operator
	//	syntax :	<variable name>.<member name>
	//		eg.	s1.rollno

	printf("Name = %s\n", s1.name);
	printf("Rollno = %d\n", s1.rollno);
	printf("Marks = %f\n", s1.marks);

	struct student s2 = {
			.name = "pqr",
			.rollno = 13,
			.marks = 90.5f
		};					// tagged initialization

	printf("s2 = %d %s %f\n", s2.rollno, s2.name, s2.marks);

/*
	struct student s1 = {12, "abc", 95.0f};
	struct student s1 = {12, "abc"};
	struct student s1 = {"abc", 95.0f};			// structure members will not be initialized properly
	struct student s1 = {0, "abc", 95.0f};

	struct student s1 = {
			.name = "abc",
			.marks = 95.0f
	};
*/

	return 0;
}




















