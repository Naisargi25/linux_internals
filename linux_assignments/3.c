#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>

int main( )
{
	struct stat st;
	struct tm dt;
  int fd;
	
	stat("5.c", &st);//
	printf("File size = %lu\n",st.st_size); // size of file
	printf("File inode = %lu\n", st.st_ino); // inode number of the file
	printf("size disc of blocks = %lu\n",st.st_blksize); // size of disk of blocks
  printf("No. of 512 byte blocks allocated = %d\n",st.st_blocks); 
	printf("Permissions = %lo\n",st.st_mode); // file permissions
  printf("Owner id = %lu\n",st.st_uid); // userid
  printf("Group id = %lu\n",st.st_gid); // groupid
  printf("Last modified time = %s\n",ctime(&st.st_mtime)); // last modified time
  printf("Last accessed time = %s\n",ctime(&st.st_atime)); // last accessed time
	
	printf("\n");
	close(fd);
	return 0;
}
