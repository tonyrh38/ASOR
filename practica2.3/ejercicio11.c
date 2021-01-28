#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGTSTP);
	sigprocmask(SIG_BLOCK, &set, NULL);

	char *sleep_secs = getenv("SLEEP_SECS");
  	int secs = atoi(sleep_secs);
  	sleep(secs);

	sigset_t pending;
	sigpending(&pending);
	if(sigismember(&set, SIGINT) == 1){
		printf("Se ha recibido la señal SIGINT\n");
	}
	if(sigismember(&set, SIGTSTP) == 1){
		printf("Se ha recibido la señal SIGITSTP\n");
		sigdelset(&set, SIGTSTP);
	}

	sigprocmask(SIG_UNBLOCK, &set, NULL);

	return 0;
}


