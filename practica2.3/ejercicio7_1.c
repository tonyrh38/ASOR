#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	system(argv[1]);
	printf("El comando termino de ejecutarse\n");	

	return 0;
}
