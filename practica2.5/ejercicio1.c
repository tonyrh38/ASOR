#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]){
	
	struct addrinfo *info;
	
	getaddrinfo(argv[1], NULL, NULL, &info);
		
	while(info != NULL){
		char buff[128];
		getnameinfo(info->ai_addr, sizeof(*info->ai_addr), buff, 128, NULL, 0, NI_NUMERICHOST);
		printf("Direccion IP: %s", buff);
		printf("	Familia de protocolos: %d", info->ai_family);
		printf("	Tipo de Socket: %d\n", info->ai_socktype);
		info = info->ai_next;
	}
	
	return 0;
}
