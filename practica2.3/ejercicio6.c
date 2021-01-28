#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	pid_t pid = fork();

	switch(pid){
		case 0:
			setsid();
			printf("Id del proceso: %i\n", getpid());
			printf("Id del proceso padre: %i\n", getppid());
			printf("Id del grupo del proceso: %i\n", getpgid(0));
			printf("Id de la sesion del proceso: %i\n", getsid(0));
			chdir("/temp/");
			
		break;
		default:
			sleep(10);
		break;
	}

	return 0;
}
