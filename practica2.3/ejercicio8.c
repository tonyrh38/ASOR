#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

	pid_t pid = fork();

	switch(pid){
		case 0:
			setsid();
			chdir("/tmp");
			int fdout = open("daemon.out", O_RDWR | O_CREAT, 0666);
			int fderr = open("daemon.err", O_RDWR | O_CREAT, 0666);
			int fdin = open("/dev/null", O_RDWR);
			dup2(fdout, 1);
			dup2(fderr, 2);
			dup2(fdin, 0);
			execvp(argv[1], &argv[1]);
		break;
		default:
			sleep(5);
		break;
	}

	return 0;
}
