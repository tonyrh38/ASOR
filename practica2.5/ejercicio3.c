#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	if (argc != 4) return -1;

	struct addrinfo hints;
	struct addrinfo *info;

	hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM; 
  hints.ai_flags = AI_PASSIVE;    
  hints.ai_protocol = 0;          
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

	getaddrinfo(argv[1], argv[2], &hints, &info);
	int sd = socket(info->ai_family, info->ai_socktype, info->ai_protocol);	
	sendto(sd, argv[3], sizeof(char), 0, info->ai_addr, info->ai_addrlen);
		
	if(argv[3][0] == 'd' || argv[3][0] == 't'){
		char received[64];
		ssize_t n = recvfrom(sd, received, 64, 0, NULL, NULL);
		received[n] = '\0';
		printf("%s\n", received);
	}

	return 0;
}
