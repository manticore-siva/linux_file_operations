#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc,char * argv[])
{
	int fd,flag;
	int lenth;

	char buff[BUF_SIZE];
	char *ptr;
	ptr = argv[2];
	lenth = strlen(ptr);

	for(int i=0;i<lenth;i++)
	{
		buff[i]=*(ptr+i);
	}

//	char buff[]="hiilinuxprogramming";

	mode_t per;

	ssize_t numcount;

	flag = O_CREAT | O_RDWR;

	per = S_IWUSR | S_IWOTH | S_IWGRP | S_IRUSR | S_IRGRP | S_IROTH;

	fd = open(argv[1],flag,per);
	perror("open() ");

	if(fd == -1)
	{
		perror("open() ");
		exit(10);
	}



	numcount = write(fd,buff,lenth);

	for(int i=0;i<numcount;i++)
	{
		printf("%c\n",buff[i]);
	}
	
	if(close(fd) == -1)
	{
		perror("close() ");
	}
	else
		perror("close() ");
	return 0;
}
