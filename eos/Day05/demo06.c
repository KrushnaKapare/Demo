#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

#define DB_FILE "emp.db"

typedef struct employee{
	int empid;
	char name[20];
	char address[20];
	double salary;
}emp_t;

void add_employee(emp_t *emp);
void print_employees(void);
emp_t *search_employee(int empid);
void edit_employee(int empid, double new_salary);
void delete_employee(int empid);

void accept_emp(emp_t *emp)
{
	printf("Enter employee info (empid, name, address, salary) : ");
	scanf("%d %s %s %lf", &emp->empid, emp->name, emp->address, &emp->salary);
}

void print_emp(emp_t *emp)
{
	printf("%d %s %s %lf\n", emp->empid, emp->name, emp->address, emp->salary);
}

int main(void)
{
	emp_t emp;
	int choice, empid;
	double new_salary;

	do{
		printf("0. Exit\n");
		printf("1. Add employee\n");
		printf("2. Print employees\n");
		printf("3. Search employee\n");
		printf("4. Edit employee\n");
		printf("5. Delete employee\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				accept_emp(&emp);
				add_employee(&emp);
				break;

			case 2:
				print_employees();
				break;

			case 3:
				printf("Enter empid to be searched : ");
				scanf("%d", &empid);
				emp_t *emp1 = search_employee(empid);
				if(emp1 == NULL)
					printf("Employee not found\n");
				else
				{
					print_emp(emp1);	
					free(emp1);
				}
				break;

			case 4:	
				printf("Enter empid : ");
				scanf("%d", &empid);
				printf("Enter new salary : ");
				scanf("%lf", &new_salary);
				edit_employee(empid, new_salary);
				break;
			case 5:
				printf("Enter empid : ");
				scanf("%d", &empid);
				delete_employee(empid);
		}

	}while(choice != 0);

	return 0;
}

void add_employee(emp_t *emp)
{
	int fd = open(DB_FILE, O_WRONLY | O_APPEND | O_CREAT, 0640);
	// err check
	write(fd, emp, sizeof(emp_t));
	close(fd);
}


void print_employees(void)
{
	emp_t emp;
	printf("Employees : \n");
	int fd = open(DB_FILE, O_RDONLY);
	while(read(fd, &emp, sizeof(emp)) > 0)
		print_emp(&emp);
	close(fd);
}

emp_t *search_employee(int empid)
{
	emp_t *emp = (emp_t *)malloc(sizeof(emp_t));
	printf("Employees : \n");
	int fd = open(DB_FILE, O_RDONLY);
	while(read(fd, emp, sizeof(emp_t)) > 0)
	{
		if(emp->empid == empid)
		{
			close(fd);
			return emp;
		}
	}
	close(fd);
	return NULL;
}

void edit_employee(int empid, double new_salary)
{
	emp_t emp;
	int fd = open(DB_FILE, O_RDWR);
	while(read(fd, &emp, sizeof(emp_t)) > 0)
	{
		if(emp.empid == empid)
		{
			emp.salary = new_salary;
			lseek(fd, -1 * sizeof(emp_t), SEEK_CUR);
			write(fd, &emp, sizeof(emp_t));
			close(fd);
			return;
		}
	}
	close(fd);
}

void delete_employee(int empid)
{
	emp_t emp;
	int fd = open(DB_FILE, O_RDWR);
	while(read(fd, &emp, sizeof(emp_t)) > 0)
	{
		if(emp.empid == empid)
		{
			while(read(fd, &emp, sizeof(emp)) > 0)
			{
				lseek(fd, -2 * sizeof(emp_t), SEEK_CUR);
				write(fd, &emp, sizeof(emp_t));
				lseek(fd, +1 * sizeof(emp_t), SEEK_CUR);
			}
			break;
		}
	}
	int new_length = lseek(fd, 0, SEEK_END) - sizeof(emp_t);
	ftruncate(fd, new_length);
	close(fd);
}












