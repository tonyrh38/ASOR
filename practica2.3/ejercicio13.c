#include <signal.h>
#include <stdlib.h>
#include <string.h>

void handler(int signal){
	sigset_t ss;
	sigemptyset(&ss);	
	sigsuspend(&ss);
}

int main(int argc, char *argv[]){

	if(argc != 2) return -1;

	char cmd[64];
	strcpy(cmd, "rm ");
	strcat(cmd, argv[0]);

	struct sigaction sa;
	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);
	
	sleep(atoi(argv[1]));		

	system(cmd);
	return 0;
}
