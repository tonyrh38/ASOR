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
  hints.ai_socktype = SOCK_STREAM; 
  hints.ai_flags = AI_PASSIVE;    
  hints.ai_protocol = 0;          
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;
	
	getaddrinfo(argv[1], argv[2], &hints, &info);
	int sd = socket(info->ai_family, info->ai_socktype, info->ai_protocol);	
	bind(sd, info->ai_addr, info->ai_addrlen);
	listen(sd, 5);

	struct sockaddr_storage sa;
	socklen_t sa_len = sizeof(sa);
	char host[NI_MAXHOST];
	char socket[NI_MAXSERV];
	char buf[128];
	
	while(1){
		int cli_sd = accept(sd, (struct sockaddr *)&sa, &sa_len);
		getnameinfo((struct sockaddr *)&sa, sa_len, host, NI_MAXHOST, socket, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV);
		int n;
		while(n = recv(cli_sd, buf, 128, 0)){
			buf[n] = '\0';
			printf("Conexion desde %s:%s> %s\n",host, socket, buf);
			send(cli_sd, buf, n, 0);
		}
		close(cli_sd);
		printf("Conexion terminada\n");
	}

	return 0;
}
