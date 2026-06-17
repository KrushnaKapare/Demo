#include<stdio.h>

typedef struct student{
	int rollno;				// 4
	char name[20];			// 20
	int std;				// 4
	union result{
		char grade;				
		float percentage;		// 4
	}result;
}stud_t;					// 32 bytes

void accept_student(stud_t *st);
void print_student(const stud_t *st);


int main(void)
{
	stud_t st;

	printf("sizeof(stud_t) = %ld\n", sizeof(stud_t));
	
	accept_student(&st);
	print_student(&st);
	return 0;
}

void accept_student(stud_t *st)
{
	printf("Enter student info (rollno, name, std) : ");
	scanf("%d %s %d", &st->rollno, st->name, &st->std);
	if(st->std < 5)
	{
		printf("Enter grade : ");
		scanf(" %c", &st->result.grade);
	}
	else
	{
		printf("Enter percentage : ");
		scanf("%f", &st->result.percentage);
	}
}

void print_student(const stud_t *st)
{
	printf("Name : %s\n", st->name);
	printf("Rollno : %d\n", st->rollno);
	printf("Std : %d\n", st->std);
	if(st->std < 5)
		printf("Grade : %c\n", st->result.grade);
	else
		printf("Percentage : %f\n", st->result.percentage);

}



















