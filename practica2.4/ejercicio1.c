#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	int pipefd[2];
    pid_t pid;

   	if (pipe(pipefd) == -1) {
	   	perror("pipe");
	   	return -1;
   	}
	
	pid = fork();

   	if (pid == -1) {
	       	perror("fork");
		return -1;
   	}

   	if (pid == 0) {
	   	close(pipefd[1]);
		dup2(pipefd[0], 0);
		execlp(argv[3], argv[3], argv[4], (char *) NULL);
	   	close(pipefd[0]);
   	} 
	else {            
	   	close(pipefd[0]);
		dup2(pipefd[1], 1);
		execlp(argv[1], argv[1], argv[2], (char *) NULL);
	   	close(pipefd[1]);
   	}

	return 0;
}
