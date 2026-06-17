#include<stdio.h>

// int fseek(FILE *stream, long offset, int whence);
//		stream - FILE *
//		offset - number of bytes by which position will be changed
//			+ve offset - position will be changed ahead
//			-ve offset - position will be changed behind
//		whence - from where file position will be changed
//			SEEK_SET - position will be changed from start of the file
//			SEEK_CUR - position will be changed from current positiom
//			SEEK_END - position will be changed from end of the file

int main(void)
{
	char ch;

	FILE *fp = fopen("file.txt", "r");

	//fseek(fp, 5, SEEK_SET);
	//fseek(fp, -5, SEEK_END);
	
	//fseek(fp, 10, SEEK_SET);
	//fseek(fp, -5, SEEK_CUR);
	//fseek(fp, 5, SEEK_CUR);


	while((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	fclose(fp);
	return 0;
}




















