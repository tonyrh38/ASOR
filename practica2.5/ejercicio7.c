#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	if (argc != 3) return -1;

	struct addrinfo hints;
	struct addrinfo *info;

	hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM; 
  hints.ai_flags = AI_PASSIVE;    
  hints.ai_protocol = 0;          
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

	getaddrinfo(argv[1], argv[2], &hints, &info);
	int sd = socket(info->ai_family, info->ai_socktype, info->ai_protocol);	
	connect(sd, info->ai_addr,info->ai_addrlen);

  char sent[64], buf[64];
	int n = 0;
  
	while(strlen(sent) != 2 || sent[0] != 'q'){
		n = read(0, sent, 64);
		sent[n] = '\0';
		send(sd, sent, n, 0);
		recv(sd, buf, n, 0);
		buf[n] = '\0';
		printf(buf);
	}
  
	close(sd);
  
	return 0;
}
