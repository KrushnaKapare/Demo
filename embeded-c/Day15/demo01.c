#include<stdio.h>
#include<string.h>
#include<unistd.h>

typedef struct book{
	int isdn;
	char name[20];
	char author[20];
	float price;
}book_t;

void accept_book(book_t *b)
{
	printf("Enter book info (isdn, name, author, price) : ");
	scanf("%d %s %s %f", &b->isdn, b->name, b->author, &b->price);
}

void print_book(book_t *b)
{
	printf("%d %s %s %.2f\n", b->isdn, b->name, b->author, b->price);
}

void write_book(book_t *b)
{
	FILE *fp = fopen("books.txt", "ab");
	fwrite(b, sizeof(book_t), 1, fp);
	fclose(fp);
}

void read_books(void)
{
	FILE *fp = fopen("books.txt", "rb");
	book_t b;

	printf("Books : \n");
	while(fread(&b, sizeof(book_t), 1, fp) != 0)
		print_book(&b);

	fclose(fp);
}

void edit_book(char *name, float newprice)
{
	FILE *fp = fopen("books.txt", "rb+");
	book_t b;

	while(fread(&b, sizeof(book_t), 1, fp) != 0)
	{
		if(!strcmp(name, b.name))
		{
			b.price = newprice;
			fseek(fp, -sizeof(book_t), SEEK_CUR);
			fwrite(&b, sizeof(book_t), 1, fp);
			break;
		}
	}
	fclose(fp);
}
/*
void delete_book(char *name)
{
	FILE *fp = fopen("books.txt", "rb");
	book_t b;
	FILE *ft = fopen("temp.txt", "wb");

	while(fread(&b, sizeof(book_t), 1, fp) != 0)
	{
		if(strcmp(name, b.name))
		{
			fwrite(&b, sizeof(book_t), 1, ft);
		}
	}
	fclose(fp);
	fclose(ft);
	rename("temp.txt", "books.txt");
}
*/
void delete_book(char *name)
{
	FILE *fp = fopen("books.txt", "rb+");
	book_t b;

	while(fread(&b, sizeof(book_t), 1, fp) != 0)
	{
		if(!strcmp(name, b.name))
		{
			while(fread(&b, sizeof(book_t), 1, fp) != 0)
			{
				fseek(fp, -2 * sizeof(book_t), SEEK_CUR);
				fwrite(&b, sizeof(book_t), 1, fp);
				fseek(fp, +1 * sizeof(book_t), SEEK_CUR);
			}
			break;
		}
	}
	fseek(fp, -1 * sizeof(book_t), SEEK_END);
	int pos = ftell(fp);
	printf("%d\n", pos);
	fclose(fp);
	truncate("books.txt", pos);
}

int main(void)
{
	book_t b = {5, "mno", "mno", 567.50f};
	write_book(&b);
	
	read_books();

	//edit_book("pqr", 900.0f);

	//delete_book("pqr");
	delete_book("abc");

	printf("-------------------------\n");
	read_books();

	return 0;
}




















