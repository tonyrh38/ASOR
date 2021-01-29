#include <stdio.h>
#include <signal.h>

int volatile n_sint = 0, n_ststp = 0;

void handler(int signal);

// Por algun motivo, en el momento en el que haces Ctrl^C deja
// de invocar el manejador de Ctrl^Z 

int main(int argc, char *argv[]){

	struct sigaction sigint;
	struct sigaction sigtstp;
	sigint.sa_handler = handler;
	sigtstp.sa_handler = handler;

	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGTSTP, &sigtstp, NULL);

	while(n_sint + n_ststp < 10){}
	printf("Nº de señales SIGINT: %d\n", n_sint);
	printf("Nº de señales SIGTSTP: %d\n", n_ststp);

	return 0;
}

void handler(int signal){
	if(signal == SIGINT) n_sint++;
	if(signal == SIGTSTP) n_ststp++;
}
