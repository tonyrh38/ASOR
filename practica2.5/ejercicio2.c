#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char *argv[]){
	
	if (argc != 3) return -1;

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
	bind(sd, info->ai_addr, info->ai_addrlen);

	char recieved[2];
	char sent[64];

	struct sockaddr_storage sa;
	socklen_t sa_len = sizeof(sa);
	char host[NI_MAXHOST];
	char socket[NI_MAXSERV];
	
	time_t t;
	struct tm st_tm;
	char buff[64];

	while (recieved[0] != 'q'){
		recvfrom(sd, recieved, sizeof(char), 0, (struct sockaddr *)&sa, &sa_len);
		recieved[1] = '\0';
		getnameinfo((struct sockaddr *)&sa, sa_len, host, NI_MAXHOST, socket, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV);
		printf("Mensaje de %s:%s> %s\n", host, socket, recieved);

		time(&t);
		localtime_r(&t, &st_tm);
		if(recieved[0] == 't'){
			strftime(buff, 64, "%X\0", &st_tm);
			buff[63] = '\0';
			sendto(sd, buff, 64, 0, (struct sockaddr *)&sa, sa_len);
			sent[63] = '\0';
		}
		if(recieved[0] == 'd'){
			strftime(buff, 64, "%x\0", &st_tm);
			buff[63] = '\0';
			sendto(sd, buff, 64, 0, (struct sockaddr *)&sa, sa_len);
			sent[63] = '\0';
		}
	}
	
	return 0;
}









