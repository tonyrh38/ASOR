#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Funcionar funciona, pero no se por que dumpea mas informacion de la que debe

int main(int argc, char *argv[]){
	
	char buff[256];
	strcpy(buff, argv[1]);
	strcat(buff, "\0");
	
	int fd = open("jose", O_WRONLY);
	write(fd, buff, 256);

	close(fd);
	
	return 1;
}
