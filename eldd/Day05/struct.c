#include<stdio.h>

struct student{
	char name[20];
	int rollno;
	int std;
	int marks;
};

#define offset_of(type, member)		\
	(unsigned long)(&(((type *)0)->member))

#define container_of(address, type, member)		\
	(type *)((char *)address - offset_of(type, member))

int main(void)
{
	struct student st = {"abc", 12, 4, 96};
	
	printf("offset_of(name) = %d\n", offset_of(struct student, name));
	printf("offset_of(rollno) = %d\n", offset_of(struct student, rollno));
	printf("offset_of(std) = %d\n", offset_of(struct student, std));
	printf("offset_of(marks) = %d\n", offset_of(struct student, marks));


	printf("&st = %u\n", &st);

	printf("address_of(name) = %u\n", (char *)&st + offset_of(struct student, name));
	printf("address_of(rollno) = %u\n", (char *)&st + offset_of(struct student, rollno));
	printf("address_of(std) = %u\n", (char *)&st + offset_of(struct student, std));
	printf("address_of(marks) = %u\n", (char *)&st + offset_of(struct student, marks));

	int *ptr = &st.std;

	printf("ptr = %u\n", ptr);

	printf("base address = %u\n", (char *)ptr - offset_of(struct student, std));
	
	printf("container_of(std) = %u\n", container_of(ptr, struct student, std));
	printf("container_of(name) = %u\n", container_of(st.name, struct student, name));
	printf("container_of(rollno) = %u\n", container_of(&st.rollno, struct student, rollno));
	printf("container_of(marks) = %u\n", container_of(&st.marks, struct student, marks));

	return 0;
}









