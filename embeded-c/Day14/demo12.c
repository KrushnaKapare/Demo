#include<stdio.h>
#include<string.h>

typedef struct book{
	int isdn;
	char name[20];
	char author[20];
	float price;
}book_t;

void accept_book(book_t *b)
{
	printf("Enter book details (isdn, name, author, price)  : ");
	scanf("%d %s %s %f", &b->isdn, b->name, b->author, &b->price);
}

void print_book(book_t *b)
{
	printf("%d %s %s %f\n", b->isdn, b->name, b->author, b->price);
}

void write_book(book_t *b)
{
	FILE *fp = fopen("books.txt", "ab");
	fwrite(b, sizeof(book_t), 1, fp);
	fclose(fp);
}

void read_books(void)
{
	book_t b;
	FILE *fp = fopen("books.txt", "rb");
	while(fread(&b, sizeof(book_t), 1, fp) != 0)
		print_book(&b);
	fclose(fp);
}

void search_book(char *name)
{
	book_t b;
	FILE *fp = fopen("books.txt", "rb");
	while(fread(&b, sizeof(book_t), 1, fp) != 0)
	{
		if(!strcmp(name, b.name))
		{
			printf("Book is found : ");
			print_book(&b);
			break;
		}
	}
	fclose(fp);
}

int main(void)
{
	int choice;
	book_t b;
	do{
		printf("0. Exit\n");
		printf("1. Add book\n");
		printf("2. Read books\n");
		printf("3. Search book\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				accept_book(&b);
				write_book(&b);
				break;

			case 2:
				read_books();
				break;

			case 3:
				search_book("abc");
				break;
		}
	}while(choice != 0);
	return 0;
}




















