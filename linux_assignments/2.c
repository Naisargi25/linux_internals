#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{	
	char buff[100]="Hello, how are you?";
	char readfile[100];
	
	int f1;

   	//open a file called lseek.txt 
	f1=open("lseek.txt",O_CREAT|O_RDWR,777);

	write(f1,buff,50);

   	printf("File pointer set at start position of file\n");
	lseek(f1,0,SEEK_SET);
	read(f1,readfile,50);
	printf("Data in file is: %s \n",readfile);

	printf("\nFile pointer set at current position of file\n");
	lseek(f1,-40,SEEK_CUR);
	read(f1,readfile,50);
	printf("Data in file is: %s \n",readfile);

	printf("\nFile pointer set at end position of file\n");
	lseek(f1,-35,SEEK_END);
	read(f1,readfile,50);
	printf("Data in file is: %s \n",readfile);

	close(f1);
   	return 0;
}
