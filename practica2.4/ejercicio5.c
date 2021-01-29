#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <unistd.h>



int main(int argc, char *argv[]){
	
	int fdjose = open("jose", O_RDONLY | O_NONBLOCK);
	int fdramiro = open("ramiro", O_RDONLY | O_NONBLOCK);
	
	while(1){
		char buff[256];
		buff[255] = '\0';

		fd_set set;
		FD_ZERO(&set);
		FD_SET(fdjose, &set);
		FD_SET(fdramiro, &set);

		int nfds = (fdjose > fdramiro)? fdjose + 1 : fdramiro + 1;
	
		select(nfds, &set, NULL, NULL, NULL);
	
		if(FD_ISSET(fdjose, &set) != 0){
			read(fdjose, buff, 256);
			printf("Jose dice: %s\n", buff);
			close(fdjose);
			fdjose = open("jose", O_RDONLY | O_NONBLOCK);
		}
		if(FD_ISSET(fdramiro, &set) != 0){
			read(fdramiro, buff, 256);
			printf("Ramiro dice: %s\n", buff);
			close(fdramiro);
			fdramiro = open("ramiro", O_RDONLY | O_NONBLOCK);
		}
	}
	return 0;
}













