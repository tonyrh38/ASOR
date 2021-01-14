#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>


int lockf(int fd, int cmd, off_t len);
struct tm *localtime(const time_t *timep);



int main(int argc, char *argv[]){
	
	if(argc != 2) return 0;
	int fd = open(argv[1], O_WRONLY |O_CREAT, 776);
	if(lockf(fd, F_TEST, 0) == 0){
		lockf(fd, F_LOCK, 0);
		time_t t = time(NULL);
		printf(ctime(&t));
		sleep(30);
		lockf(fd, F_ULOCK, 0);
	}
	printf("Ocupado o terminado");
	return 1;
}
