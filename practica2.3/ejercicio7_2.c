#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	execvp(argv[1],&argv[1]);
	printf("El comando termino de ejecutarse\n");	

	return 0;
}
