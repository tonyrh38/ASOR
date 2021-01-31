#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

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
	
	int nfds = (sd > 0)? sd + 1 : 1;
	fd_set *set;

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
		FD_ZERO(set);
		FD_SET(0, set);
		FD_SET(sd, set);
		select(nfds, set, NULL, NULL,NULL);
		if(FD_ISSET(sd, set) != 0){
			recvfrom(sd, recieved, sizeof(char), 0, (struct sockaddr *)&sa, &sa_len);
			recieved[1] = '\0';
			getnameinfo((struct sockaddr *)&sa, sa_len, host, NI_MAXHOST, socket, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV);
			printf("Mensaje de %s:%s> %s\n", host, socket, recieved);
		}
		if(FD_ISSET(0, set) != 0){
			char input[2];			
			read(0, input, sizeof(char) * 2);
			if(input[1] == '\n'){
				strcpy(recieved, input);
				recieved[1] = '\0';
				printf("Mensaje local> %s\n", recieved);
			}
		}

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
