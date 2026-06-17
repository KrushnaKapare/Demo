

// DIR *opendir(const char *name)
//		arg1 - path of a directory
//		returns - pointer to the directory stream
//				  NULL on failure

// struct dirent *readdir(DIR *dirp)
//		arg1 - directory pointer returned by opendir
//		returns - pointer to the directory entry
//				  NULL on failure or end of directory

//	struct dirent - d_ino, d_type, d_name

// int closedir(DIR *dirp)
//		arg1 - directory pointer returned by opendir
//		returns - 0 on success
//				  -1 on failure


#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>


int main(int argc, char *argv[])
{
	char *dirpath;
	DIR *dp = NULL;
	struct dirent *ent;

	if(argc != 2)
	{
		printf("Directory path is not mentioned...\n");
		printf("Run as : %s <dir path>\n", argv[0]);
		exit(1);
	}
	
	dirpath = argv[1];
	
	//1. open the directory stream
	dp = opendir(dirpath);
	if(dp == NULL)
	{
		printf("Directory is not opened...\n");
		exit(1);
	}

	//2. read entries one by one and print their information
	printf("Directory content : \n");
	while((ent = readdir(dp)) != NULL)
	{
		//printf("%lu %s %u\n", ent->d_ino, ent->d_name, ent->d_type);
		
		
		if(  strcmp(ent->d_name ,".") == 0 ||    strcmp(ent->d_name ,"..") == 0  )
			continue;
		struct stat st;

		int ret = stat(ent->d_name, &st);
		if(ret == -1)
		{
			printf("stat() is failed \n");
			exit(ret);
		}

		printf("Filename = %s\n",ent->d_name );
		printf("inode = %lu\n", st.st_ino);
		printf("mode = %u\n", st.st_mode);
		printf("nlink = %lu\n", st.st_nlink);
		printf("size = %lu\n", st.st_size);

		
	}

	//3. close the directory stream
	closedir(dp);

	return 0;
}















