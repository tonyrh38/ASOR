#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	int h_p[2], p_h[2];
	pid_t pid;

	pipe(h_p);
	pipe(p_h);

	pid = fork();

	if(pid == 0){
		close(h_p[0]);
		close(p_h[1]);
		int i = 1;
		while(i < 10){
			char buff[512];
			ssize_t bytes = read(p_h[0], buff, 512);
			buff[bytes] = '\0';
			printf(buff);
			sleep(1);
			write(h_p[1], "1", sizeof(char));
			i++;
		}
		write(h_p[1], "q", sizeof(char));
		close(h_p[1]);
		close(p_h[0]);
	}
	else {
		close(p_h[0]);
		close(h_p[1]);
		char *cond = "1";
		while(cond == "1"){
			char buff[512];
		 	ssize_t bytes = read(0, buff, 512);
			buff[bytes] = '\0';
			write(p_h[1], buff, 512);
			read(h_p[0], cond, sizeof(char));
		}
		wait(NULL);
		close(p_h[1]);
		close(h_p[0]);
	}

	return 0;
}
