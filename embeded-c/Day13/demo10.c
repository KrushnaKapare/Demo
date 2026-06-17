#include<stdio.h>

typedef struct employee{
	int empid;
	char name[20];
	double salary;
	struct date{
		int dd;
		int mm;
		int yyyy;
	}dob, doj;
}emp_t;

int main(void)
{
	emp_t emp;

	printf("Enter employee info (empid, name, salary) : ");
	scanf("%d %s %lf", &emp.empid, emp.name, &emp.salary);
	printf("Enter date of birth (dd/mm/yyyy) : ");
	scanf("%d %d %d", &emp.dob.dd, &emp.dob.mm, &emp.dob.yyyy);
	printf("Enter date of joining (dd/mm/yyyy) : ");
	scanf("%d %d %d", &emp.doj.dd, &emp.doj.mm, &emp.doj.yyyy);

	printf("Employee info : \n");
	printf("empid = %d\n", emp.empid);
	printf("name = %s\n", emp.name);
	printf("salary = %.2lf\n", emp.salary);
	printf("date of birth = %d / %d / %d\n", emp.dob.dd, emp.dob.mm, emp.dob.yyyy);
	printf("date of joining = %d / %d / %d\n", emp.doj.dd, emp.doj.mm, emp.doj.yyyy);

	return 0;
}




















