#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

	if(argc != 2) return 0;
	int fd1 = open(argv[1], O_WRONLY | O_CREAT,777);
	dup2(fd1, 1);
	dup2(fd1, 2);
	
	printf("Mensaje de salida estandar\n");
	perror("Mensaje de salida de error\n");	

	return 1;
}
